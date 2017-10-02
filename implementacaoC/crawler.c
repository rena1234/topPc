#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <regex.h>
#include <glib.h>
#include <string.h>

#include "crawler.h"

struct MemoryStruct {
  char *memory;
  size_t size;
};

static size_t
WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp){
    
  size_t realsize = size * nmemb;
  struct MemoryStruct *mem = (struct MemoryStruct *)userp;

  mem->memory = realloc(mem->memory, mem->size + realsize + 1);
  if(mem->memory == NULL) {
    /* out of memory! */
    printf("not enough memory (realloc returned NULL)\n");
    return 0;
  }

  memcpy(&(mem->memory[mem->size]), contents, realsize);
  mem->size += realsize;
  mem->memory[mem->size] = 0;

  return realsize;
}

char *getHtml(char *url){
  CURL *curl_handle;
  CURLcode res;

  struct MemoryStruct chunk;

  chunk.memory = malloc(1);  /* will be grown as needed by the realloc above */
  chunk.size = 0;    /* no data at this point */

  curl_global_init(CURL_GLOBAL_ALL);

  /* init the curl session */
  curl_handle = curl_easy_init();

  /* specify URL to get */
  curl_easy_setopt(curl_handle, CURLOPT_URL, *url);

  /* send all data to this function  */
  curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);

  /* we pass our 'chunk' struct to the callback function */
  curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void *)&chunk);

  /* some servers don't like requests that are made without a user-agent
     field, so we provide one */
  curl_easy_setopt(curl_handle, CURLOPT_USERAGENT, "libcurl-agent/1.0");

  /* get it! */
  res = curl_easy_perform(curl_handle);
  char *html = NULL;
  /* check for errors */
  if(res != CURLE_OK) {
    fprintf(stderr, "curl_easy_perform() failed: %s\n",
            curl_easy_strerror(res));
  }
  else {
    *html = *chunk.memory;
    printf("%lu bytes retrieved\n", (long)chunk.size);
  }

  /* cleanup curl stuff */
  curl_easy_cleanup(curl_handle);

  free(chunk.memory);

  /* we're done with libcurl, so clean it up */
  curl_global_cleanup();

  return html;
}

regex_t *returnCompiledPattern(char * pattern){
    regex_t * preg;
    if (0 != (int rc = regcomp(preg, pattern, 0))) {
      printf("regcomp() failed, returning nonzero (%d)\n", rc);
      exit(EXIT_FAILURE);
    }

    return preg;
}

char **getUrls(char *html, int maxMatches){
/*
 * using regex.h too hard
 *
    regex_t *preg = returnCompiledPattern("href\s?=\s?\"(^\")*\"");
    regmatch_t pmatch;
    while( regexec(&preg, html, maxMatches, pmatch, 0) == 0 );
    
    for(int i = 0; i <
*/
    GError *err  = NULL;
    GRegex regex = g_regex_new("href\s?=\s?\"(^\")*\"", 0, 0, &err);
    GMatchInfo *matchInfo;
    g_regex_match(regex, html, 0, matchInfo);
    
    char **urls; int i = 0;
    while(g_match_info_matches(matchInfo)){
        gchar *result = g_match_info_fetch(matchInfo, 0);
        //g_print("mykey=%s\n", result);
        strcpy(urls[i],result);
        g_match_info_next(matchInfo, &err);
        g_free(result);
        i++;
    }

    return urls;
}

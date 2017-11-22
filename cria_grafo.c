#include <stdlib.h>
#include "no.h"
#include <time.h>
#include <stdbool.h>
#include "cria_grafo.h"
#include <stdio.h>
bool retorna_sucesso(int probabilidade){
    int aleatorio = rand() % 100;
    if ( aleatorio < probabilidade)
        return true;
    return false;
}

Ambiente * cria_ambiente(int num_sites, int num_threads){

  srand(time(NULL));
  Ambiente * ambiente = malloc(sizeof(ambiente));
  No *** vetores_sites = malloc(num_threads * sizeof(vetores_sites));
  int num_maliciosos = 0;
  for( int j = 0; j < num_threads; j++){
      No ** sites = malloc( num_sites * sizeof(sites));
      vetores_sites[j] = sites;
      for( int i = 0; i < num_sites / num_threads; i++){
          int max_links = 100;
          int num_links = rand () % max_links;
          int * links = malloc(num_links * sizeof(int));
        
          for( int k = 0; k < num_links; k++){
              links[k] = rand() % num_sites;
          }
        
            sites[i] = cria_site(retorna_sucesso(5), links, num_links);
            if(sites[i] -> malicioso) num_maliciosos ++;
            
      }
  }
    
    
    ambiente -> vetores_sites = vetores_sites;
    ambiente -> num_maliciosos = num_maliciosos;
    ambiente -> num_threads = num_threads;
    ambiente -> total_sites = num_sites;

    return ambiente;
}

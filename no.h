#ifndef NO_H_INCLUDED
#define NO_H_INCLUDED
#include <stdbool.h>

typedef struct NO{
    int * links;
    int num_links;
    bool malicioso;
}No;

No * cria_site(bool malicioso, int * links, int num_links);

#endif

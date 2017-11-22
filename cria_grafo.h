#ifndef CRIA_GRAFO_H_INCLUDED
#define CRIA_GRAFO__H_INCLUDED
#include <stdbool.h>
#include "no.h"

typedef struct AMBIENTE{
    No *** vetores_sites;
    int num_maliciosos;
    int total_sites;
    int num_threads;
}Ambiente;

bool retorna_sucesso(int probabilidade);
Ambiente * cria_ambiente(int num_sites, int num_threads);

#endif

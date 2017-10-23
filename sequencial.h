#ifndef SEQUENCIAL_H_INCLUDED
#define SEQUENCIAL_H_INCLUDED
#include <stdbool.h>
#include "no.h"

int calcula_indice_reinicio(bool visitados[], int indice_ultimo_reinicio);
int percorre_arvore(bool visitados[], No ** sites, int indice_no_base);
bool busca_maliciosos(No ** sites, int total_sites, int total_maliciosos);

#endif

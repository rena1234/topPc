#ifndef TESTE_H_INCLUDED
#define TESTE_H_INCLUDED
#include <stdbool.h>
#include "no.h"

typedef struct AMBIENTETESTE{
    No ** vetor_sites;
    int num_sites;
    int num_maliciosos;
}AmbienteTeste;

AmbienteTeste * cria_ambiente_teste();
bool testa(AmbienteTeste * ambiente);

#endif

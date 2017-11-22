#include "teste.h"
#include <stdio.h>
#include "cria_grafo.h"
#include "paralelo.h"

int main(){
    
    int num_sites = 10000;
    int num_threads = 2;
    Ambiente * ambiente = cria_ambiente(num_sites, num_threads);

    if(p_busca_maliciosos(ambiente))
        printf("SUCESSO\n");
    else printf ("DEU RUIM \n");
    
    return 0;
}

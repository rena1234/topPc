#include "teste.h"
#include <stdio.h>
#include "cria_grafo.h"
#include "paralelo.h"

int main(){
    
    int num_sites = 10000;
    int num_threads = 1;
    int num_maliciosos = 0;
    Ambiente * ambiente = cria_ambiente(num_sites, num_threads);
    No ** sites = *(ambiente -> vetores_sites);
    for(int i = 0; i < ambiente -> total_sites; i++)
        if(sites[i] -> malicioso)
            num_maliciosos++;

    printf("%d\n", num_maliciosos );

    if(p_busca_maliciosos(ambiente))
        printf("SUCESSO\n");
    else printf ("DEU RUIM \n");
    
    return 0;
}

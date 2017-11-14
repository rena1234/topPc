#include "teste.h"
#include <stdio.h>
#include "cria_grafo.h"
#include "sequencial.h"
int main(){
    
    /*
    if(testa(cria_ambiente_teste()))
        printf("SUCESSO\n");
    else printf("DEU RUIM\n");
    */
    int num_sites = 10000;
    No ** sites = cria_vetor_sites(num_sites);
    int num_maliciosos = 0;
    for(int i = 0; i < num_sites; i++)
        if (sites[i] -> malicioso)
            num_maliciosos++;
    
    if(busca_maliciosos(sites, num_sites, num_maliciosos))
        printf("SUCESSO\n");
    else printf ("DEU RUIM \n");
    
    return 0;
}

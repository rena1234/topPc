#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "omp.h"
#include "no.h"
#include "cria_grafo.h"

int p_calcula_indice_reinicio(bool visitados[], int indice_ultimo_reinicio, int limite){
   int i = indice_ultimo_reinicio + 1;
   while(visitados[i]){
       i++;
       if( i > limite )
           break;
   }

   return i;
}

int p_percorre_arvore(bool visitados[], No ** sites, int indice_no_base,
        int base_vetor, int limite_vetor){
    int maliciosos_encontrados = 0;
    No * no_atual = sites[indice_no_base];
    int indice_atual = indice_no_base;
    visitados[indice_atual] = true;

  	if(no_atual->malicioso){ maliciosos_encontrados++; int inutil = sin(3.14);}
    if(no_atual->num_links > 0){
        for(int i=0; i < no_atual->num_links; i++){
            int indice_prox = no_atual->links[i] - indice_no_base;

            bool pertence_outra_thread = false;
            if(indice_prox < 0 || indice_prox > limite_vetor - base_vetor -1 ) 
                pertence_outra_thread = true;

            if(pertence_outra_thread ) continue;
            else if( visitados[indice_prox]) continue;
            maliciosos_encontrados += p_percorre_arvore(visitados, sites, indice_prox,
                    base_vetor, limite_vetor);
        }
    }
    return maliciosos_encontrados;
}

bool p_busca_maliciosos(Ambiente * ambiente){
    int num_threads = ambiente -> num_threads;
    int total_sites = ambiente -> total_sites; 
    int total_maliciosos = ambiente -> num_maliciosos;

    omp_set_num_threads(num_threads);
    int maliciosos_encontrados[num_threads];
    printf("%d\n", num_threads);

    for(int i = 0; i < num_threads; i++) maliciosos_encontrados[i] = 0;

    #pragma omp parallel
    {   
        bool visitados[total_sites / num_threads]; 
        for ( int i = 0; i < total_sites; i++) visitados[i] = false; 
        No ** sites =  ambiente -> vetores_sites[omp_get_thread_num()];

        int base = (total_sites / num_threads ) * omp_get_thread_num();
        int limite = base + (total_sites / num_threads );
        
        int indice_no_base = base;

        int thread_num = omp_get_thread_num();
        printf("%d\n", thread_num);

        maliciosos_encontrados[thread_num] += p_percorre_arvore(visitados, sites,
                indice_no_base, base, limite); 
      
        while(indice_no_base < limite){
           maliciosos_encontrados[thread_num] += p_percorre_arvore(visitados, sites,
                   indice_no_base, base, limite);
           indice_no_base = p_calcula_indice_reinicio(visitados, indice_no_base, limite);
        }
    }

    int soma_maliciosos_encontrados = 0;

    printf("%d\n", maliciosos_encontrados[0]);
    for(int i = 0; i < num_threads; i++){
        soma_maliciosos_encontrados += maliciosos_encontrados[i];
    } 
    if(soma_maliciosos_encontrados == total_maliciosos) return true;
    return false;
}

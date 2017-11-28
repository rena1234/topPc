#include <stdio.h>
#include <glib.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "omp.h"
#include "no.h"
#include "cria_grafo.h"

int p_calcula_indice_reinicio(No ** sites, int indice_ultimo_reinicio, int limite){
   int i = indice_ultimo_reinicio + 1;
   while(sites[i] -> visitado){
       i++;
       if( i > limite )
           break;
   }

   return i;
}

bool decide_empilhamento(No ** sites, int indice_candidato,
        int base_vetor, int limite_vetor
){
    bool empilha = true;
    if(indice_candidato < base_vetor || indice_candidato > limite_vetor) 
        empilha = false;

    else if( sites[indice_candidato] -> visitado) empilha = false;

    return empilha;
}

int p_percorre_arvore(No ** sites, int indice_no_base,
        int base_vetor, int limite_vetor){
    int maliciosos_encontrados = 0;
  
    No * no_atual = sites[indice_no_base];
    int indice_atual = indice_no_base;
    no_atual -> visitado = true;

  	if(no_atual->malicioso){ maliciosos_encontrados++; int inutil = sin(3.14);}
    if(no_atual->num_links > 0){
        for(int i=0; i < no_atual->num_links; i++){
            int indice_prox = no_atual->links[i];

            bool pertence_outra_thread = false;
            if(indice_prox < base_vetor || indice_prox > limite_vetor) 
                pertence_outra_thread = true;

            if(pertence_outra_thread ) continue;
            else if( sites[indice_prox] -> visitado) continue;
            maliciosos_encontrados += p_percorre_arvore( sites, indice_prox,
                    base_vetor, limite_vetor);
        }
    }
    return maliciosos_encontrados;
}

bool p_busca_maliciosos(Ambiente * ambiente){
    int num_threads = ambiente -> num_threads;
    int total_sites = ambiente -> total_sites; 
    int total_maliciosos = ambiente -> num_maliciosos;
    No ** sites =  ambiente -> sites;

    omp_set_num_threads(num_threads);
    int maliciosos_encontrados[num_threads];
    printf("%d\n", num_threads);

    for(int i = 0; i < num_threads; i++) maliciosos_encontrados[i] = 0;

    #pragma omp parallel
    {   
        int base = (total_sites / num_threads ) * omp_get_thread_num();
        int limite = base + (total_sites / num_threads ) - 1;
                    
        int indice_no_base = base;

        int thread_num = omp_get_thread_num();
        printf("%d\n", thread_num);

        GQueue *  pilha = g_queue_new();
        for(int i = base; i <= limite; i++){
            if(!sites[i] -> visitado)
                g_queue_push_head(pilha, sites[i]);
            while( pilha -> length > 0){
               No * site = g_queue_pop_head(pilha);
               if(site -> visitado) continue;
               site -> visitado = true;
               if(site -> malicioso){
                   maliciosos_encontrados[thread_num] += 1;
                   int inutil = sin(3.14);
               }
               for(int j = 0; j < site -> num_links; j++){
                   if(decide_empilhamento(sites,site -> links[j], base, limite))
                       g_queue_push_head(pilha, sites[site -> links[j]]);
               }
            }
        }
    }

    int soma_maliciosos_encontrados = 0;

    for(int i = 0; i < num_threads; i++){
        soma_maliciosos_encontrados += maliciosos_encontrados[i];
        printf("thread %d %d\n", i, maliciosos_encontrados[i]);
    } 
    
    printf("encontrados %d\n", soma_maliciosos_encontrados);

    if(soma_maliciosos_encontrados == total_maliciosos) return true;
    return false;
}

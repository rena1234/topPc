#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "no.h"
#include "teste.h"

int calcula_indice_reinicio(bool visitados[], int indice_ultimo_reinicio){
   int i = indice_ultimo_reinicio + 1;
   while(visitados[i]){i++;}

   return i;
}

int percorre_arvore(bool visitados[], No ** sites, int indice_no_base){
    int maliciosos_encontrados = 0;
    No * no_atual = sites[indice_no_base];
    int indice_atual = indice_no_base;
    visitados[indice_atual] = true; 

    if(no_atual->malicioso){ maliciosos_encontrados++; int inutil = sin(3.14);}
    if(no_atual->num_links > 0){
        for(int i=0; i < no_atual->num_links; i++){
            int indice_prox = no_atual->links[i];
            if(visitados[indice_prox]) continue;
            maliciosos_encontrados += percorre_arvore(visitados, sites, indice_prox);
        }
    }
    return maliciosos_encontrados;
}

bool busca_maliciosos(No ** sites, int total_sites, int total_maliciosos){
    bool visitados[total_sites]; 
    for ( int i = 0; i < total_sites; i++) visitados[i] = false; 
    int maliciosos_encontrados = 0;
    int indice_ultimo_no_base = 0;
    int indice_no_base = 0;

    maliciosos_encontrados += percorre_arvore(visitados, sites, indice_no_base); 
    
    while( maliciosos_encontrados < total_maliciosos && indice_no_base < total_sites - 1){
        indice_no_base = calcula_indice_reinicio(visitados, indice_no_base);
        maliciosos_encontrados += percorre_arvore(visitados, sites, indice_no_base);
    }

    if(maliciosos_encontrados == total_maliciosos) return true;
    return false;

}


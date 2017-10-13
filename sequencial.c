#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

typedef struct NO{
    int * links;
    int num_links;
    bool malicioso;
}NO;

int calcula_indice_reinicio(bool visitados[], int indice_ultimo_reinicio){

   int i = indice_ultimo_reinicio + 1;
   while(visitados[i]){i++;}

   return i;
}

int busca_em_ordem(bool visitados[], NO sites[], int indice_inicio){
    int maliciosos_encontrados = 0;
    NO * no_atual = sites[indice_inicio];
    int indice_atual = indice_inicio;
    
    if(visitados[indice_atual]) return 0;
    
    if(no_atual->malicioso){ maliciosos_encontrados++; int inutil = sin(3.14);}

    if(no_atual->num_links > 0){
        for(int i=0; i < no_atual->num_links; i++){
      
            int indice_prox = no_atual->links[i];
            if(visitados[indice_prox]) continue;
            
            maliciosos_encontrados += busca_em_ordem(bool visitados[], 
                    No sites[], indice_prox);
        }
    }
    
    return maliciosos_encontrados;
}

int main(){
    bool visitados[] =  
    int total_sites = 
    int maliciosos_encontrados = 0;
    int indice_ultimo_reinicio = 0;

    maliciosos_encontrados += busca_em_ordem(visitados, sites, 0); 

    while( maliciosos_encontrados < total_maliciosos ){
        while(indice_ultimo_reinicio < total_sites - 1){
            int indice_reinicio = calcula_indice_reinicio(visitados,
                    indice_ultimo_reinicio);

            maliciosos_encontrados += busca_em_ordem(visitados, sites,
                    indice_reinicio);
        }
                
    }
    return 0;
}

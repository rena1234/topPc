#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

typedef struct NO{
    int * links;
    int num_links;
    bool malicioso;
}No;

int calcula_indice_reinicio(bool visitados[], int indice_ultimo_reinicio){

   int i = indice_ultimo_reinicio + 1;
   while(visitados[i]){i++;}

   return i;
}

int percorre_arvore(bool visitados[], No sites[], int indice_no_base){
    int maliciosos_encontrados = 0;
    No * no_atual = &sites[indice_no_base];
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

int busca_maliciosos(No sites[], int total_sites, int total_maliciosos){

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
    return maliciosos_encontrados;

}

typedef struct AMBIENTETESTE{
    No ** vetor_sites;
    int num_sites;
    int total_maliciosos;
}AmbienteTeste;

No * cria_site(bool malicioso, int links[], int num_links){
    No * novo_site;   
    novo_site = malloc(sizeof(No));
    
    novo_site -> links = links;
    novo_site -> malicioso = malicioso;
    novo_site -> num_links = num_links;

    return novo_site;
}

AmbienteTeste * cria_ambiente_teste(){
   AmbienteTeste * ambiente;
   ambiente = malloc(sizeof(AmbienteTeste));
   
   int num_sites = 6;
   int num_maliciosos = 3;
   No * sites[num_sites];
   for( int i = 0; i < num_sites; i++) sites[i] = NULL;
   
   ambiente -> vetor_sites = &sites[0];
   ambiente -> num_sites = num_sites;
   ambiente -> total_maliciosos = num_maliciosos;

   int links_0[2] = {1, 2};
   ambiente ->  vetor_sites[0] = cria_site(false, links_0, 2);

   int links_1[1] = {3};
   ambiente -> vetor_sites[1] = cria_site(false, links_1, 1);

   int * links_2 = NULL;
   ambiente -> vetor_sites[2] = cria_site(true, links_2, 0);

   int links_3[1] = {4};
   ambiente -> vetor_sites[3] = cria_site(false, links_3, 1);

   int links_4[1] = {3};
   ambiente -> vetor_sites[4] = cria_site(true, links_4, 1);

   int * links_5 = NULL;
   ambiente -> vetor_sites[5] = cria_site(true, links_5, 0);

   return ambiente;

}

bool testa(AmbienteTeste * ambienteTeste){
        

}

int main(){
    return 0;
}

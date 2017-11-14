#include <stdlib.h>
#include "no.h"
#include <time.h>
#include <stdbool.h>

bool retorna_sucesso(int probabilidade){
    int aleatorio = rand() % 100;
    if ( aleatorio < probabilidade)
        return true;
    return false;
}

No ** cria_vetor_sites(int num_sites){

  srand(time(NULL));
  
  No ** sites = malloc( num_sites * sizeof(sites));
  for( int i = 0; i < num_sites; i++){
    
      int max_links = 100;
    	
      int num_links = rand () % max_links;
      int * links = malloc(num_links * sizeof(int));
    
      for( int i = 0; i < num_links; i++){
          links[i] = rand() % 10000;
      }
    
    	sites[i] = cria_site(retorna_sucesso(5), links, num_links);
        
  }
  return sites;
}

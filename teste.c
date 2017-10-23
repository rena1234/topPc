#include "teste.h"
#include <stdlib.h>
#include "sequencial.h"


AmbienteTeste * cria_ambiente_teste(){
   AmbienteTeste * ambiente;
   ambiente = malloc(sizeof(AmbienteTeste));
   
   int num_sites = 6;
   int num_maliciosos = 3;
   No ** sites = malloc(num_sites * sizeof(sites));
   for( int i = 0; i < num_sites; i++) sites[i] = NULL;
   
   ambiente -> vetor_sites = sites;
   ambiente -> num_sites = num_sites;
   ambiente -> num_maliciosos = num_maliciosos;
   
   int num_links_0 = 2;
   int * links_0 = malloc( num_links_0 * sizeof(int) );
   links_0[0] = 1; links_0[1] = 2;
   sites[0] = cria_site(false, links_0, 2);

   int num_links_1 = 1;
   int * links_1 = malloc( num_links_1 * sizeof(int) );
   links_1[0] = 3;
   sites[1] = cria_site(false, links_1, 1);

   int * links_2 = NULL;
   sites[2] = cria_site(true, links_2, 0);

   int num_links_3 = 1;
   int * links_3 = malloc( num_links_3 * sizeof(int) );
   links_3[0] = 4;
   sites[3] = cria_site(false, links_3, 1);

   int num_links_4 = 1;
   int * links_4 = malloc( num_links_4 * sizeof(int) );
   links_4[0] = 3;
   sites[4] = cria_site(true, links_4, 1);

   int * links_5 = NULL;
   sites[5] = cria_site(true, links_5, 0);

   return ambiente;

}

bool testa(AmbienteTeste * ambiente){
    return busca_maliciosos(ambiente -> vetor_sites, ambiente -> num_sites,
            ambiente -> num_maliciosos);

}


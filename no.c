#include "no.h"
#include <stdlib.h>
#include <stdbool.h>

No * cria_site(bool malicioso, int links[], int num_links){
    /*
     * Função testada
     */
    No * novo_site;   
    novo_site = malloc(sizeof(No));
    
    novo_site -> links = links;
    novo_site -> malicioso = malicioso;
    novo_site -> num_links = num_links;

    return novo_site;
}

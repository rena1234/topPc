#include "teste.h"
#include <stdio.h>

int main(){
    if(testa(cria_ambiente_teste()))
        printf("SUCESSO\n");
    else printf("DEU RUIM\n");

    return 0;
}

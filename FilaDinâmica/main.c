#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main(){
    system("cls");
    int e;
    t_fila f;

    inicializar(&f);


    enfileirar(23,&f);
    enfileirar(43,&f);
    enfileirar(78,&f);
    enfileirar(24,&f);
    enfileirar(01,&f);
    enfileirar(10,&f);
    enfileirar(99,&f);
    desenfileirar(&f);

    printf("Frente da fila: %d\n", frente(&f));
    printf("Costas da fila: %d\n", costas(&f));

    printf("\n\n");

    printf("Frente da fila: %d\n", frente(&f));
    printf("Costas da fila: %d\n", costas(&f));







    return 0;


}





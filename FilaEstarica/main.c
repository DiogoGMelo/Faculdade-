#include <stdio.h>
#include <stdlib.h>
#include "fila.h"


int main()
{
   int e;
   t_fila f;

   inicializar(&f);

   enfileirar(23,&f);
   enfileirar(45,&f);
   enfileirar(13,&f);
   enfileirar(88,&f);
   enfileirar(90,&f);
   enfileirar(2,&f);


    costas(&f);
    printf("\n");
    frente(&f);

    desenfileirar(&f);
    printf("\n");

    costas(&f);
    printf("\n");
    frente(&f);





   return 0;

}

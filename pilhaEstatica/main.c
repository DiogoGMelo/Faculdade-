#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main()
{
    t_pilha P;
    int e;
    inicializar(&P);
    int n;
    scanf("%d",&n);
    for (int i = 0 ;i<n;i++){
        e=rand()%99+1;
        push(e,&P);
    }
    contar(&P);
    int d;
    scanf("%d",&d);
    for (int i = 0 ;i<d;i++){
        pop(i,&P);
    }
    contar(&P);
    for (int i = 0 ;i<n;i++){
        e=rand()%99+1;
        push(e,&P);
    }
    contar(&P);

}

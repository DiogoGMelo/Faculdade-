#include <stdio.h>
#include "pilha.h"

void inicializar(t_pilha *P){
    P->topo = -1;
}

int push(int e,t_pilha *P){
    if(cheia(P)){
        return CHEIA;
    }
    P->topo++;
    P->pilha[P->topo]=e;

    return SUCESSO;
}

int pop(int e,t_pilha *P){
    if(vazia(P)){
        return VAZIA;
    }
    int E = P->pilha[P->topo];
    P->topo--;
    return E;
}

int vazia(t_pilha *P){
    if(P->topo < 0){
        return 1;
    }else{
        return 0;
    }

}

int cheia(t_pilha *P){
    if (P->topo == MAX-1){
        return 1;
    }else{
        return 0;
    }
}

int topo(t_pilha *P){
    if (vazia(P)){
        return VAZIA;
    }
    return P->pilha[P->topo];
}

int contar(t_pilha *P){

    printf("tamanho da pilha = %d ",P->topo+1);
    printf("LIFO = %d ",P->pilha[P->topo]);
    return P->topo +1;

}




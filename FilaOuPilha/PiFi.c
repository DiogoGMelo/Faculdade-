#include "PiFi.h"
#include <stdio.h>
#include <stdlib.h>


int iniciarFila(t_fila *f){
    f->fim = NULL;
    f->inicio = NULL;
    return 0;
}

int vazia(t_fila *f){
    if (f->inicio == NULL){
        return 1;
    } else {
        return 0;
    }
}

int enfileirar(int e,t_fila *f){
    t_apontador a =(t_apontador)malloc(sizeof(t_no));
    
    a->elemento = e;
    a->proximo = NULL;
    if(vazia(f)){
        f->inicio=a;
    } else {
        f->fim->proximo=a;
    }
    f->fim = a;

    return 0;

}

int desenfileirar(t_fila *f) {
    if (vazia(f)) {
        return -1;
    }
    if(f->inicio == f->fim){
        f->inicio = NULL;
    }
    int d;
    f->inicio->elemento = d;
    t_apontador a = f->inicio;
    f->inicio = f->inicio->proximo;
    free(a);

    return d;
}
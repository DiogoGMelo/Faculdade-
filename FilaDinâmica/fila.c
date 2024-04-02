#include <stdio.h>
#include<stdlib.h>
#include "fila.h"

int inicializar(t_fila *f){
    f->fim = NULL;
    f->inicio = NULL;
}

int enfileirar(int e,t_fila *f){
    t_apontador a =(t_apontador)malloc(sizeof(t_no));
    if (a==NULL){
        return CHEIA;
    }
    a->elemento = e;
    a->proximo = NULL;
    if(vazia(f)){
        f->inicio=a;
    } else {
        f->fim->proximo=a;
    }
    f->fim = a;

    return SUCESSO;

}

int desenfileirar(t_fila *f) {
    if (vazia(f)) {
        return NAO_EXISTE;
    }
    if(f->inicio == f->fim){
        f->inicio = NULL;
    }
    t_apontador a = f->inicio;
    f->inicio = f->inicio->proximo;
    free(a);

    return SUCESSO;
}


int frente(t_fila *f){
    if (vazia(f)){
        return NAO_EXISTE;
    }
    //printf("%d ",f->inicio->elemento);
    return f->inicio->elemento;
}

int costas(t_fila *f){
    if(vazia(f)){
        return NAO_EXISTE;
    }
    //printf("%d ",f->fim->elemento);
    return f->fim->elemento;

}

int vazia(t_fila *f){
    if (f->inicio == NULL){
        return 1;
    } else {
        return 0;
    }
}

int cheia(t_fila *f){
    t_apontador a = (t_apontador)malloc(sizeof(t_no));
    if(a == NULL){
        return 1;
    } else {
        return 0;
    }
}



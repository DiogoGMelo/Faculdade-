#include <stdio.h>
#include "fila.h"

void inicializar(t_fila *f){
    f->inicio = 0;
    f->fim = -1;
}

int enfileirar(int e,t_fila *f){
    if (cheia(f)){
        return CHEIA;
    }
    f->fim ++;
    f->fila[f->fim]=e;
    return SUCESSO;
}

int desenfileirar(t_fila *f){
    if(vazia(f)){
        return VAZIA;
    }
    int aux = f->fila[f->inicio];
    f->inicio ++;
    return aux;
}

int frente(t_fila *f){
    printf("%d ",f->fila[f->inicio]);
    return f->fila[f->inicio];
}

int costas(t_fila *f){
    if (vazia(f)){
        return VAZIA;
    }
    printf("%d ",f->fila[f->fim]);
    return f->fila[f->fim];
}
int vazia(t_fila *f){
        if (f->inicio < 0 || f->inicio > f->fim){
            printf("esta vazia ");
            return 1;
        } else {
            return 0;
        }
}

int cheia(t_fila *f){
    if (f->fim ==  MAX -1){
        return 1;
    } else {
        return 0;
    }
}






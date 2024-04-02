#ifndef FILA_H
#define FILA_H

#define SUCESSO 1
#define NAO_EXISTE -1
#define JA_EXISTE -2
#define INVALIDO -3
#define CHEIA -4
#define VAZIA -5


typedef struct t_no *t_apontador;

typedef struct t_no{
    int elemento;
    t_apontador proximo;
    t_apontador anterior;
}t_no;

typedef struct{
    t_apontador inicio;
    t_apontador fim;
}t_fila;


int inicializar(t_fila *f);
int enfileirar(int e,t_fila *f);
int desenfileirar(t_fila *f);
int frente(t_fila *f);
int costas(t_fila *f);
int vazia(t_fila *f);
int cheia(t_fila *f);








#endif //FILA_H

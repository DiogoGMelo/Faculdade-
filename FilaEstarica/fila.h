#ifndef PILHA_H
#define PILHA_H

#define SUCESSO 1
#define NAO_EXISTE -1
#define JA_EXISTE -2
#define INVALIDO -3
#define CHEIA -4
#define VAZIA -5

#define MAX 128

typedef struct{
    int inicio;
    int fim;
    int fila[MAX];

}t_fila;

void inicializar(t_fila *f);
int enfileirar(int e,t_fila *f);
int desenfileirar(t_fila *f);
int frente(t_fila *f);
int costas(t_fila *f);
int vazia(t_fila *f);
int cheia(t_fila *f);



#endif // PILHA_H


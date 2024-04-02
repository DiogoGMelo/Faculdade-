#ifndef PIFI_H
#define PIFI_H

typedef struct t_no *t_apontador;

typedef struct t_no {
	int elemento;
	t_apontador proximo;
} t_no;

typedef struct {
	t_apontador topo;
	int count;
} t_pilha;

typedef struct{
    t_apontador inicio;
    t_apontador fim;
}t_fila;

int iniciarFila(t_fila *f);
int enfileirar(int e,t_fila *f);
int desenfileirar(t_fila *f);
int vazia(t_fila *f);
int iniciarPilha(t_pilha *p);
int pop(t_pilha *p);
int push(int e, t_pilha *p);


#endif
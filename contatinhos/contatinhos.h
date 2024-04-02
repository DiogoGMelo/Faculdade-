#ifndef CONTATINHOS_H
#define CONTATINHOS_H

#define MAX_LEVEL 6

typedef struct contato {
    char nome[11];
    char* tel;
    struct contato** forward;
} contato;

typedef struct t_skip {
    int level;
    int size;
    contato* header;
}t_skip;
int alterar(t_skip* list,char* nome,char* novo_tel);
void iniciar(t_skip* list);
contato* procura(t_skip* list, char* nome);
int exists(t_skip* list, char* nome);
static int generateRandomLevel();
void insert(t_skip* list, char* nome, char* tel);
static void freecontato(contato* x);
void removecontato(t_skip* list, char* nome);
void printList(t_skip* list);

#endif

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "contatinhos.h"

void iniciar(t_skip* list) {
    contato* header = (contato*) malloc(sizeof(contato));

    list->header = header;
    strcpy(header->nome, "");

    header->forward = (contato**) malloc((MAX_LEVEL + 1) * sizeof(contato*));
    for (int i = 0; i <= MAX_LEVEL; i++) {
        header->forward[i] = list->header;
    }

    list->level = 1;
    list->size = 0;
}

contato* procura(t_skip* list, char* nome) {
    contato* x = list->header;

    for (int i = list->level; i >= 1; i--) {
        while (x->forward[i] != list->header && strcmp(x->forward[i]->nome, nome) < 0) {
            x = x->forward[i];
        }
    }

    if (x->forward[1] != list->header && strcmp(x->forward[1]->nome, nome) == 0) {
        return x->forward[1];
    } else {
        return NULL;
    }
}


int exists(t_skip* list, char* nome) {
    contato* n = procura(list, nome);
    return n != NULL;
}

static int generateRandomLevel() {
    int level = 1;
    while (rand() < RAND_MAX / 2 && level < MAX_LEVEL) {
        level++;
    }

    return level;
}

void insert(t_skip* list, char* nome, char* tel) {
    contato* update[MAX_LEVEL + 1];
    contato* x = list->header;
    int level;

    for (int i = list->level; i >= 1; i--) {
        while (x->forward[i] != list->header && strcmp(x->forward[i]->nome, nome) < 0) {
            x = x->forward[i];
        }

        update[i] = x;
    }

    if (x->forward[1] != list->header) {
        x = x->forward[1];
    }

    if (x != list->header && strcmp(nome, x->nome) == 0) {
        free(x->tel);
        x->tel = strdup(tel);
        return;
    } else {
        level = generateRandomLevel();

        if (level > list->level) {
            for (int i = list->level + 1; i <= level; i++) {
                update[i] = list->header;
            }

            list->level = level;
        }

        x = (contato*) malloc(sizeof(contato));
        strcpy(x->nome, nome);
        x->tel = strdup(tel);
        x->forward = (contato**) malloc(sizeof(contato*) * (level + 1));

        for (int i = 1; i <= level; i++) {
            x->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = x;
        }

        list->size = list->size + 1;
    }
}

int alterar(t_skip *list, char* nome, char* novo_tel) {
    contato* x = procura(list, nome);
    if (x) {
        strcpy(x->tel, novo_tel);
        return 1;
    } else {
        return 0;
    }
}

static void freecontato(contato* x) {
    if (x) {
        free(x->forward);
        free(x);
    }
}

void removecontato(t_skip* list, char* nome) {
    contato* update[MAX_LEVEL + 1];
    contato* x = list->header;

    for (int i = list->level; i >= 1; i--) {
        while (x->forward[i] != list->header && strcmp(x->forward[i]->nome, nome) < 0) {
            x = x->forward[i];
        }

        update[i] = x;
    }

    if (x->forward[1] != list->header) {
        x = x->forward[1];
    }

    if (x != list->header && strcmp(x->nome, nome) == 0) {
        for (int i = 1; i <= list->level; i++) {
            if (update[i]->forward[i] != x) {
                break;
            }

            update[i]->forward[i] = x->forward[i];
        }

        free(x->tel);
        freecontato(x);

        while (list->level > 1 && list->header->forward[list->level] == list->header) {
            list->level--;
        }

        list->size = list->size - 1;
    }
}

void printList(t_skip* list) {
   contato* x = list->header;
    while (x && x->forward[1] != list->header) {
        printf("%s[%s]->", x->forward[1]->nome, x->forward[1]->tel);
        x = x->forward[1];
    }

    printf("NIL\n");
}

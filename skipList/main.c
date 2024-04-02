#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "contatinhos.h"


int main() {
    char op;

    t_skip list;
    iniciar(&list);

    while(1) {
        scanf(" %c", &op);

        if (op == '0') {
            break;
        }
        char nome[11];
        char tel[10];

        switch (op) {
            case 'I':
                scanf("%s %s", nome, tel);

                if (exists(&list, nome)) {
                    printf("Contatinho ja inserido\n");
                    break;
                }

                insert(&list, nome, tel);
            break;
            case 'P':
                scanf("%s", nome);

                contato* n = procura(&list, nome);
                if (n == NULL) {
                    printf("Contatinho nao encontrado\n");
                    break;
                }

                printf("Contatinho encontrado: telefone %s\n", n->tel);
            break;
            case 'A':
                scanf("%s %s", nome, tel);

                if (!exists(&list, nome)) {
                    printf("Operacao invalida: contatinho nao encontrado\n");
                    break;
                }

                alterar(&list, nome, tel);
            break;
            case 'R':
                scanf("%s", nome);

                if (!exists(&list, nome)) {
                    printf("Operacao invalida: contatinho nao encontrado\n");
                    break;
                }

                removecontato(&list, nome);
            break;
            default:
            break;
        }
    }

    return 0;
}

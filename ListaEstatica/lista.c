
#include <stdio.h>
#include "lista.h"


int criar(t_lista *l) {
	l->ultimo = -1;
}

int inserir(t_elemento e, t_lista *l) {

	if (cheia(l)) {
		printf("Erro, lista cheia\n");
		return CHEIA;
	}

	if (pesquisar(e.chave, l) >= 0) {
		printf("Chave ja existe\n");
		return JA_EXISTE;
	}

	l->ultimo++;
	l->lista[l->ultimo] = e;

	return SUCESSO;

}


int remover(t_chave chave, t_lista *l) {

	int pos = pesquisar(chave, l);

	if (pos < 0) {
		printf("Chave nao existe\n");
		return NAO_EXISTE;
	}

	l->lista[pos] = l->lista[l->ultimo];
	l->ultimo--;

	return SUCESSO;

}

int pesquisar(t_chave chave, t_lista *l){

	for (int i = 0; i <= l->ultimo; i++) {
		if (l->lista[i].chave  == chave) {
			return i;
		}
	}

	return NAO_EXISTE;

}

int vazia(t_lista *l) {
	if (l->ultimo == -1)
		return 1;
	else
		return 0;
}

int cheia(t_lista *l) {

	if (l->ultimo == MAX-1)
		return 1;
	else
		return 0;

}

void imprimir(t_lista *l) {

	for (int i = 0; i <= l->ultimo; i++) {
		printf("%d, %s\n",
			l->lista[i].chave,
			l->lista[i].nome);
	}

}

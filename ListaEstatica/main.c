#include <stdio.h>
#include <string.h>

#include "lista.h"

int main() {

	t_lista l;
	t_elemento e;

	criar(&l);
	int n;
	scanf("%d",&n);
	for (int i = 0;i < n;i++){
        e.chave=i;
        strcpy(e.nome,"diogo");
        inserir(e,&l);
	}
    imprimir(&l);
    remover(5,&l);
    printf("\n\n");
    imprimir(&l);




	int d;
	scanf("%d",&d);
	for (int i = 0;i<d;i++){
        remover(i,&l);
	}
    imprimir(&l);
    pesquisar(4,&l);



}

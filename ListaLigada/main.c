#include <stdio.h>
#include <string.h>

#include "lista.h"

int main() {

	t_lista l;
	t_elemento e;

	inicializar(&l);
    int n;
    printf("inserir chaves : ");
    scanf("%d",&n);
    for (int i = 0;i<n;i++){
        scanf("%d",&e.chave);
        inserir(e,&l);
    }
    t_apontador p = l.primeiro;

    printf("%d ",p->elemento.chave);
	imprimir(&l);
	int c;
	printf("chave a ser removida : ");
	scanf("%d",&c);
	remover(c,&l);
	 p = l.primeiro;
    printf("%d ",p->elemento.chave);
	imprimir(&l);

	printf("elemento a ser pesquisado : ");
	int pes;
	scanf("%d",&pes);
	pesquisar(pes,&l);


}

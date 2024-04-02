#include "PiFi.h"
#include <stdio.h>
#include <stdlib.h>


#define indefinido 1
#define fila 2
#define pilha 3
#define impossivel 4

int main(){

    struct podeser{
        int podeserPILHA;
        int podeserFIla;
    }podeser;


    int N;//numero de casos
    scanf("%d",&N);

    int numerodeop[N];
    int armazenar[N];
    
    for(int i = 0;i<N ;i++) {
        scanf("%d",&numerodeop[i]);

        t_pilha p;
        t_fila f;
        iniciarFila(&f);
        iniciarPilha(&p);
        podeser.podeserFIla = 1;
        podeser.podeserPILHA = 1;

        for(int j =0;j<numerodeop[i];j++){
            int nu;
            char op;
            scanf("%c",&op);
            scanf("%d",&nu);

            if(op == 'i'){
                enfileirar(nu,&f);
                push(nu,&p);
            } else if (op == 'r'){
                int retiradoF = desenfileirar(&f);
                int retiradoP = pop(&p);
                if (retiradoF != nu){
                    podeser.podeserFIla = 0;
                } else if(retiradoP != nu){
                    podeser.podeserPILHA = 0;
                }else return -1;
            }else return -1;
        }

        if (podeser.podeserFIla == 1 && podeser.podeserPILHA == 1){
            armazenar[i] = 1;
        } else if (podeser.podeserFIla == 1){
            armazenar[i] = 2;
        } else if (podeser.podeserPILHA == 1){
            armazenar[i] = 3;
        } else armazenar[i] = 4;
    } 
    for (int i = 0;i<N ;i++){
        if (armazenar[i] == 1){
            printf("indefinido");
        } else if (armazenar[i] == 2){
            printf("fila");
        } else if (armazenar[i] == 3){
            printf("pilha");
        } else if (armazenar[i] == 4){
            printf("impossivel");
        }
    }
    return 0;
}

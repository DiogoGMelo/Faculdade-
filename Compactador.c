#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define TAM 256




typedef struct No
{
    unsigned char caracter;
    int frequencia;
    struct No *esq, *dir, *proximno;
}No;

typedef struct 
{
   No *inicio;
   int tam; 
}lista;


No* remove_no_inicio(lista *lista){
    No *aux = NULL;

    if(lista->inicio){
        aux = lista->inicio;
        lista->inicio = aux->proximno;
        aux->proximno = NULL;
        lista->tam--;
    }
    return aux;
}

No* montar_arvore(lista *lista){
    No *primeiro, *segundo, *novo;
    while(lista->tam > 1){
        primeiro = remove_no_inicio(lista);
        segundo = remove_no_inicio(lista);
        novo = malloc(sizeof(No));

        if(novo){
            novo->caracter = '+';
            novo->frequencia = primeiro->frequencia + segundo->frequencia;
            novo->esq = primeiro;
            novo->dir = segundo;
            novo->proximno = NULL;

            inserir_ordenado(lista, novo);

        } else {
            // printf("erro de memoria");
            break;
        }
    }
    return lista->inicio;
}

void imprimir_arvore(No *raiz, int tam){
    if(raiz->esq == NULL && raiz->dir == NULL){
        printf("\t Folha: %c \t Altura: %d\n",raiz->caracter, tam);
    } else {
        imprimir_arvore(raiz->esq, tam + 1);
        imprimir_arvore(raiz->dir, tam + 1);
    }
}




int altura_arvore(No *raiz){
    int esq, dir;
    
    if(raiz == NULL){
        return -1;
    } else {
        esq = altura_arvore(raiz->esq) + 1;
        dir = altura_arvore(raiz->dir) + 1;
        if(esq > dir){
            return esq;
        } else{
            return dir;
        }
    }
}
char** aloca_dici(int colunas){
    char **dici;
    
    dici = malloc(sizeof(char*) * TAM);
    for(int i = 0; i < TAM; i++){
        dici[i] = calloc(colunas, sizeof(char));
    }
    return dici;
}

void gerar_dici(char **dici, No *raiz, char *caminho, int colunas){
    char esquerda[colunas], direita[colunas];
    if(raiz->esq == NULL && raiz->dir == NULL){
        strcpy(dici[raiz->caracter], caminho);
    } else {
        strcpy(esquerda, caminho);
        strcpy(direita, caminho);

        strcat(esquerda, "0");// adiciona 0 para o caminho
        strcat(direita , "1");//adiciona 1 para o caminho

        gerar_dici(dici, raiz->esq, esquerda, colunas);
        gerar_dici(dici, raiz->dir, direita, colunas);
    }
}
void imprime_dici(char **dici){
    int i;
    printf("\t dicionario");
    for(i=0 ;i < TAM;i++){
        printf("\t%d: %s\n", i, dici[i]);
    }
}




void criar_lista(lista *lista){
    lista->inicio = NULL;
    lista->tam = 0;
}
void inserir_ordenado(lista *lista, No *no) {
    No *atual = lista->inicio;
    No *anterior = NULL;

    // Lista vazia ou novo nó deve ser o primeiro
    if (atual == NULL || no->frequencia < atual->frequencia) {
        no->proximno = atual;
        lista->inicio = no;
    } else {
        while (atual != NULL && no->frequencia >= atual->frequencia) {
            anterior = atual;
            atual = atual->proximno;
        }

        no->proximno = atual;
        anterior->proximno = no;
    }

    lista->tam++;
}

void preencher_lista(unsigned int tab[], lista *lista){
    int i;
    No *novo;
    for(i=0;i<TAM;i++){
        if(tab[i]>0){
            novo = malloc(sizeof(No));
            if(novo){
                novo->caracter = i;
                novo->frequencia = tab[i];
                novo->dir = NULL;
                novo->esq = NULL;
                novo->proximno = NULL;

                inserir_ordenado(lista, novo);
            } else {
                printf("erro de memoria");
                break;
            }
        }
    }
}
void imprimir_lista(lista *lista){
    No *aux = lista->inicio;
    printf("\t Lista ordenada de tamanha: %d\n",lista->tam);
    while(aux){
        printf("\tCaracter: %c Frequencia: %d\n",aux->caracter, aux->frequencia);
        aux = aux->proximno;
    }
}

void compactar(unsigned char str[]){
    FILE *arquivo = fopen("arquivo.comp", "wb");
    int i = 0;
    int j = 7;
    unsigned char mascara, byte = 0; 
    if(arquivo){
        while(str[i] != '\0'){
            mascara = 1;
            if(str[i] == '1'){
                mascara = mascara << j;
                byte = byte | mascara;
            }
            j--;
            if(j < 0){
                fwrite(&byte, sizeof(unsigned char), 1, arquivo);
                byte = 0;
                j = 7;
            }
            i++;
        }
        if(j != 7){
          fwrite(&byte, sizeof(unsigned char), 1, arquivo);  
        }
        fclose(arquivo);
    } else {
        printf("\n erro de arquivo");
    }
}







//inicia a tabala com 0 
void iniciar_tab0(unsigned int tab[]){
    for(int i = 0;i<TAM;i++){
        tab[i] = 0;
    }
}
void preenche_tab_freque(unsigned char texto[], unsigned int tab[]){
    for(int i = 0; texto[i] != '\0'; i++){
        tab[texto[i]]++;
    }
}
void imprime_tab_freque(unsigned int tab[]){
    int i;

    printf("\tTABELA DE FREQ");
    for(int i = 0; i<TAM;i++){
        if(tab[i]>0){
            printf("\t%d = %d = %c\n", i, tab[i], i);
        } 
    }
}

int cal_tamanha_string(char **dici, char *texto){
    int i = 0, tam = 0;
    while(texto[i] != '\0'){
        tam += strlen(dici[texto[i]]);
        i++;
    }
    return tam + 1; // Adiciona 1 para o caractere '\0'
}

char* codificar(char **dici, unsigned char *texto){
    int i = 0;
    int tam =  cal_tamanha_string(dici, texto);
    char *codigo = calloc(tam, sizeof(char));
    while(texto[i] != '\0'){
        strcat(codigo, dici[texto[i]]);
        i++;
    }
    return codigo;
}

int descobrir_tamanho(){
    FILE *arquivo = fopen("arquivo.txt", "r");
    int tam = 0;
    if(arquivo){
        while(fgetc(arquivo) != -1){
            tam++;
        }
        fclose(arquivo);
    } else {
        printf("erro de arquivo");
    } return tam;
}
void ler_texto(unsigned char *texto){
    FILE *arquivo = fopen("arquivo.txt", "r");
    char letra;
    int i = 0;
    if(arquivo){
        while(!feof(arquivo)){
            letra = fgetc(arquivo);
            if(letra != -1){
                texto[i] = letra;
                i++;
            }
        }
        fclose(arquivo);
    } else {
       printf("erro ao ler o arquivo"); 
    }
}

int main(){
    int tam;
    unsigned char *texto;
    unsigned int tab_freque[TAM];
    lista L;
    No *arvore;
    int colunas;
    char **dici;
    char *codificado;
    tam = descobrir_tamanho();
    texto = calloc(tam + 2,sizeof(unsigned char)); 
    ler_texto(texto);
    //tabela de frequencia
    iniciar_tab0(tab_freque);
    preenche_tab_freque(texto, tab_freque);
    //imprime_tab_freque(tab_freque);
    //---------------------------------------------------
    //lista ordenada
    criar_lista(&L);
    preencher_lista(tab_freque, &L);
    //imprimir_lista(&L);
    //--------------------------------------------------------
    //arvore
    arvore =  montar_arvore(&L);
    printf("Arvore \n");
    //imprimir_arvore(arvore, 0);
    //------------------------------------------------------
    //dicionario
    colunas = altura_arvore(arvore) + 1;
    dici = aloca_dici(colunas);
    gerar_dici(dici, arvore, "", colunas);
    //imprime_dici(dici);
    //------------------------------------------------------
    //codificação
    codificado = codificar(dici, texto);
    //printf("\n\t Texto codificado: %s\n", codificado);
    //------------------------------------------------------------
    //compactar
    compactar(codificado);

    free(texto);
    free(codificado);
    
    return 0;
}

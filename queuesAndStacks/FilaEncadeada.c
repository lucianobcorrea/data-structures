#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define CLEAN_BUFF do{ int c; while((c = getchar()) != '\n' && c != EOF);}while(0)

struct nodo{
    char prefixo[30];
    char nome[30];
    char companhia[30];
    struct nodo *proximo;
};
typedef struct nodo tipoNodo;

struct fila{
    tipoNodo *inicio;
    tipoNodo *fim;
    int tam;
};
typedef struct fila tipoFila;

void inicializar(tipoFila *fila);
int isEmpty(tipoFila *fila);
void lerDados(tipoNodo *nodo);
void inserirFila(tipoFila *fila);
int tamanhoFila(tipoFila *fila);
void imprimirFila(tipoFila *fila);
void removeFila(tipoFila *fila);

int main(){
    tipoFila *fila = (tipoFila *) malloc (sizeof(tipoFila));
    inicializar(fila);

    if(isEmpty(fila)){
        printf("PISTA DE DECOLAGEM VAZIA!\n");
    }else{
        printf("PISTA JA TEM AVIOES!\n");
    }

    printf("Tamanho Fila: %d\n", tamanhoFila(fila));

    inserirFila(fila);
    inserirFila(fila);
    inserirFila(fila);

    printf("Tamanho Fila: %d\n", tamanhoFila(fila));

    imprimirFila(fila);

    removeFila(fila);

    printf("Tamanho Fila: %d\n", tamanhoFila(fila));
    printf("\n");
    imprimirFila(fila);

    return 0;
}

void inicializar(tipoFila *fila){
    fila -> tam = 0;
    fila -> inicio = NULL;
    fila -> fim = NULL;
}

int isEmpty(tipoFila *fila){
    if(fila -> fim == NULL){
        return TRUE;
    }else{
        return FALSE;
    }
}

void lerDados(tipoNodo *nodo){
    printf("Prefixo: ");
    scanf("%30[^\n]s", nodo -> prefixo);
    CLEAN_BUFF;
    printf("Nome: ");
    scanf("%30[^\n]s", nodo -> nome);
    CLEAN_BUFF;
    printf("Companhia: ");
    scanf("%30[^\n]s", nodo -> companhia);
    CLEAN_BUFF;
}

void inserirFila(tipoFila *fila){
    tipoNodo* novoNodo = (tipoNodo *) malloc (sizeof(tipoNodo));
    lerDados(novoNodo);
    if(novoNodo != NULL){
        if(fila -> inicio == NULL){
        fila -> inicio = novoNodo;
        fila -> fim = novoNodo;
        fila -> tam++;
    }else{
        fila -> fim -> proximo = novoNodo;
        fila -> fim = novoNodo;
        fila -> tam++;
    }
    }else{
        printf("Problema ao Alocar Memoria!!\n");
    }
}

int tamanhoFila(tipoFila *fila){
    if(isEmpty(fila)){
        printf("FILA AINDA ESTA VAZIA!!\n");
    }else{
        return fila -> tam;
    }
}

void imprimirFila(tipoFila *fila){
    tipoNodo *paux;
    paux = fila -> inicio;
    printf("FILA ATUAL\n");
    while(paux){
        printf("Prefixo: %s\n", paux -> prefixo);
        printf("Nome: %s\n", paux -> nome);
        printf("Companhia: %s\n", paux -> companhia);
        paux = paux -> proximo;
    }
}

void removeFila(tipoFila *fila){
    tipoNodo *nodoRemovidoTopo;
    if(isEmpty(fila)){
        printf("FILA ESTA VAZIA!\n");
    }else{
        nodoRemovidoTopo = fila -> inicio;
        fila -> inicio = fila -> inicio -> proximo;
        if(fila -> inicio == NULL){
            fila -> fim = NULL;
        }
        printf("AVIAO QUE SAIU: %s\n", nodoRemovidoTopo -> nome);
        free(nodoRemovidoTopo);
        fila -> tam--;
    }
}




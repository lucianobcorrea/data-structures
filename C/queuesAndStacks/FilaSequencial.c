#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 31
#define TAMFILA 3

// CRIANDO A ESTRUTURA DO AVIAO
struct aviao {
    char prefixo[TAM];
    char cia[TAM];
};
typedef struct aviao TipoAviao;

// CRIANDO A ESTRUTURA DA FILA DE AVIÃƒâ€¢ES
struct fila {
    TipoAviao avioes[TAMFILA];
    int inicio;
    int fim;
};
typedef struct fila TipoFila;

/* CRIACAO DA FILA */
TipoFila criar(TipoFila fila) {
    fila.inicio = -1;
    fila.fim = -1;
    return fila;
}

/* VERIFICA SE A FILA ESTA VAZIA */
int verificar_vazia(TipoFila fila) {
    if (fila.inicio < 0 || fila.inicio > fila.fim)
        return 1;
    else
        return 0;
}

/* ADICIONANDO UM AVIAO NA FILA */
TipoFila adicionar_fila(TipoAviao aviao, TipoFila fila) {
    if (verificar_vazia(fila)) { // primeiro elemento da fila sendo adicionado
        fila.avioes[++fila.fim] = aviao;
        fila.inicio++;
    }
    else
        if (fila.fim < TAMFILA - 1) // evitando que o tamanho da fila estoure
            fila.avioes[++fila.fim] = aviao;
        else
            printf("Overflow !!!\n");
    return fila;
}

/* REMOVENDO UM AVIAO DA FILA */
TipoFila remover_fila(TipoFila fila) {
    if (verificar_vazia(fila))
        printf("Fila Vazia !!!\n");
    else
        if (fila.inicio < TAMFILA) {
            printf("AVIAO que saiu da fila: %s - %s\n", 
            fila.avioes[fila.inicio].prefixo,
            fila.avioes[fila.inicio++].cia);
        }
    return fila;
}

void imprimir(TipoFila fila) {
    int i = fila.inicio;
    printf("FILA ATUAL\n");
    if (fila.inicio < 0)
        printf("Fila vazia.\n");
    else
        while (i <= fila.fim) {
            printf("%s - %s\t\t", fila.avioes[i].prefixo, fila.avioes[i].cia);
            i++;
        }
    printf("\n");
}

int main () {
    TipoFila fila;
    TipoAviao aviao;
    fila = criar(fila);
    
    strcpy(aviao.prefixo, "A");strcpy(aviao.cia, "AA");
    fila = adicionar_fila(aviao, fila);
    printf("%d - %d\n", fila.inicio, fila.fim);
    imprimir(fila);
    getchar();
    
    strcpy(aviao.prefixo, "B");strcpy(aviao.cia, "BB");
    fila = adicionar_fila(aviao, fila);
    printf("%d - %d\n", fila.inicio, fila.fim);
    imprimir(fila);
    getchar();
    
    strcpy(aviao.prefixo, "C");strcpy(aviao.cia, "CC");
    fila = adicionar_fila(aviao, fila);
    printf("%d - %d\n", fila.inicio, fila.fim);
    imprimir(fila);
    getchar();

    fila = remover_fila(fila);
    imprimir(fila);
    printf("%d - %d\n", fila.inicio, fila.fim);
    getchar();

    strcpy(aviao.prefixo, "D");strcpy(aviao.cia, "DD");
    fila = adicionar_fila(aviao, fila);
    printf("%d - %d\n", fila.inicio, fila.fim);
    imprimir(fila);
    getchar();
    
    fila = remover_fila(fila);
    printf("%d - %d\n", fila.inicio, fila.fim);
    imprimir(fila);
    getchar();
    
    fila = remover_fila(fila);
    printf("%d - %d\n", fila.inicio, fila.fim);
    imprimir(fila);
    getchar();

    fila = remover_fila(fila);
    printf("%d - %d\n", fila.inicio, fila.fim);
    imprimir(fila);
    getchar();

    fila = remover_fila(fila);
    printf("%d - %d\n", fila.inicio, fila.fim);
    imprimir(fila);
    getchar(); 
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#define TAMANHO 200000
#define NUM_ALEAT 1000000

void quickSort(int vetor[], int inicio, int fim);
void monta_vetor(int A[]);
void escreve_vetor(int A[], char *msg);

int main(){
    clock_t inicio, fim;
    double diferenca;
    int vetor[TAMANHO];
    monta_vetor(vetor);
    //escreve_vetor(vetor, "VETOR DESORDENADO");
    inicio = clock();
    quickSort(vetor, 0, TAMANHO - 1);
    fim = clock();
    diferenca = fim - inicio;
    printf("Tempo em ms: %10.4f", diferenca/(CLOCKS_PER_SEC/1000));
    //escreve_vetor(vetor, "VETOR ORDENADO");
    return 0;
}

void quickSort(int vetor[], int inicio, int fim){
    int i, j, coringa, aux;
    i = inicio;
    j = fim - 1; //TESTAR OQ ACONTECE SE NAO DEIXAR O -1
    coringa = vetor[(inicio + fim) / 2];
    while(i <= j){
        while(vetor[i] < coringa && i < fim){
            i++;
        }
        while(vetor[j] > coringa && j > inicio){
            j--;
        }
        if(i <= j){
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            i++;
            j--;
        }
    }
    if(j > inicio){
        quickSort(vetor, inicio, j + 1);
    }
    if(i < fim){
        quickSort(vetor, i, fim);
    }
}

void monta_vetor(int A[]) {
    int i;
    srand(time(NULL));
    for (i=0; i<TAMANHO; i++)
        A[i] = rand()%(NUM_ALEAT+1);
}

void escreve_vetor(int A[], char *msg) {
    int i;
    printf("*********** %s ***********\n", msg);
    for (i=0; i<TAMANHO; i++)
        printf("%d ", A[i]);
    printf("\n");
}
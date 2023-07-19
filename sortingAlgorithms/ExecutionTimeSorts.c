#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#define TAMANHO 50000
#define NUM_ALEAT 1000000

// Algoritmo que utiliza a estratÃ©gia do insertion sort para ordenar o vetor.
void insertion_sort(int A[]) {
    int i,j,key;
    for (j=1; j<TAMANHO; j++) {
      key = A[j];
      i = j-1;
      while (i >= 0 && A[i] > key) {
        A[i+1] = A[i];
        i = i-1;
      }
      A[i+1] = key;
    }
}

// FunÃ§Ã£o que cria os valores de modo aleatÃ³rio para o vetor que deseja-se ordenar
void monta_vetor(int A[]) {
    int i;
    srand(time(NULL));
    for (i=0; i<TAMANHO; i++)
        A[i] = rand()%(NUM_ALEAT+1);
}
// FunÃ§Ã£o que imprime os valores do vetor
void escreve_vetor(int A[], char *msg) {
    int i;
    printf("*********** %s ***********\n", msg);
    for (i=0; i<TAMANHO; i++)
        printf("%d ", A[i]);
    printf("\n");
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

void bubbleSort(int vetor[]){
    int auxiliar;
    for(int i = 1; i < TAMANHO; i++){
        for(int j = 0; j < TAMANHO - 1; j++){
            if(vetor[j] > vetor[j + 1]){
                auxiliar = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = auxiliar;
            }
        }
    }
}

void selectionSort(int vetor[]){
    int auxiliarMin, auxiliar;
    for(int i = 0; i < TAMANHO; i++){
        auxiliarMin = i;
        for(int j = i + 1; j < TAMANHO; j++){
            if(vetor[j] < vetor[auxiliarMin]){
                auxiliarMin = j;
            }
            auxiliar = vetor[auxiliarMin];
            vetor[auxiliarMin] = vetor[i];
            vetor[i] = auxiliar;
        }
    }
}

void MERGE(int A[TAMANHO], int p, int q, int r){
    int left = q - p + 1;
    int right = r - q;

    int L[left + 1];
    int R[right + 1];

    int i, j;

    for(i = 0; i < left; i++){
        L[i] = A[p + i];
    }
    for(j = 0; j < right; j++){
        R[j] = A[q + j + 1];
    }
    L[left] = INT_MAX;
    R[right] = INT_MAX;
    i = 0;
    j = 0;
    for(int k = p; k <= r; k++){
        if(L[i] <= R[j]){
            A[k] = L[i];
            i += 1;
        }else{
            A[k] = R[j];
            j += 1;
        }
    }
}

void MERGE_SORT(int A[TAMANHO], int p, int r){
    int q;
    if(p < r){
        q = (p + r)/2;
        MERGE_SORT(A, p, q);
        MERGE_SORT(A, q + 1, r);
        MERGE(A, p, q, r);
    }
}

int main () {
    clock_t inicio, fim;
    double diferenca;
    int A[TAMANHO];
    monta_vetor(A);
    inicio = clock();
    //MERGE_SORT(A, 0, TAMANHO - 1);
    //insertion_sort(A);
    quickSort(A, 0, TAMANHO - 1);
    fim = clock();
    diferenca = fim - inicio;
    printf("Tempo em ms: %10.4f\n", diferenca/(CLOCKS_PER_SEC/1000));
}
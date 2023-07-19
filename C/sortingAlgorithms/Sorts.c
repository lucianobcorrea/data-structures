#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 6

void escreveVetorCrescente(int vetor[]);
void escreveVetorDecrescente(int vetor[]);
void selectionSort(int vetor[]);
void bubbleSort(int vetor[]);

int main(){

    int A[TAMANHO] = {5, 3, 4, 6, 1, 2};
    printf("BUBBLE SORT!\n");
    bubbleSort(A);
    escreveVetorCrescente(A);
    escreveVetorDecrescente(A);

    printf("\n\n");

    printf("SELECTION SORT!\n");
    selectionSort(A);
    escreveVetorCrescente(A);
    escreveVetorDecrescente(A);

    printf("\n\n");

    printf("INSERTION SORT!\n");
    insertionSort(A);
    escreveVetorCrescente(A);
    escreveVetorDecrescente(A);
    
    return 0;
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

void insertionSort(int vetor[]){
    int key;
    int i;
    for(int j = 1; j < TAMANHO; j++){
        key = vetor[j];
        i = j - 1;
        while(i >= 0 && vetor[i] > key){
            vetor[i + 1] = vetor[i];
            i = i - 1;
        }
        vetor[i + 1] = key;
    }
}

void escreveVetorCrescente(int vetor[]){
    printf("VETOR ORDENADO CRESCENTE!\n");
    for(int i = 0; i < TAMANHO; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

void escreveVetorDecrescente(int vetor[]){
    printf("VETOR ORDENADO DECRESCENTE!\n");
    int i = TAMANHO;
    do{
        i--;
        printf("%d ", vetor[i]);
    }while (i > 0);
}
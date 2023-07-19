#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#define TAMANHO 10

void MERGE(int A[TAMANHO], int p, int q, int r);
void MERGE_SORT(int A[TAMANHO], int p, int r);

int main(){
    int A[TAMANHO] = {9, 8, 7, 5, 6, 4, 3, 1, 2, 0};

    printf("VETOR DESORDENADO:\n");
    for(int i = 0; i < TAMANHO; i++){
        printf("%d ", A[i]);
    }
    printf("\n");

    MERGE_SORT(A, 0, TAMANHO - 1);

    printf("VETOR ORDENADO:\n");
    for(int i = 0; i < TAMANHO; i++){
        printf("%d ", A[i]);
    }


    return 0;
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
#include <stdlib.h>
#include <stdio.h>

#define TAM 5

int soma(int vetor[TAM]){

    int *ponteiro = vetor;
    int soma = 0;
    for(int i = 0; i < TAM; i++){
        soma += (*ponteiro);
        ponteiro++;
    }
    return soma;
}

int main(){

    int vetor[TAM] = {5, 50, 100, 150, 200};
    printf("Soma dos valores do Vetor = %d", soma(vetor));
    return 0;
}
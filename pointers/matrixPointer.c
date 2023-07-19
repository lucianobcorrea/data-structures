#include <stdio.h>
#include <stdlib.h>

#define TAM 3

int soma(int matriz[TAM][TAM]){

    int soma = 0;
    int *ponteiro = matriz;
    for(int i = 0; i < TAM; i++){
        for(int j = 0; j < TAM; j++){
            soma += (*ponteiro);
            ponteiro++;
        }
    }
    return soma;
}

int main(){

    int matriz[TAM][TAM] = {{2,4,8}, {1,5,6}, {3,1,0}};
    printf("Soma dos valores da Matriz = %d", soma(matriz));
    return 0;
}
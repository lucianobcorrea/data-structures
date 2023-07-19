#include <stdio.h>
#include <stdlib.h>

#define TAM 3

int main()
{

    int matriz[TAM][TAM] = {{2, 4, 8},
                            {1, 5, 6},
                            {3, 1, 0}};                       
    int soma(int matriz[TAM][TAM]);

    printf("Soma = %d", soma(matriz));

    return 0;
}

int soma(int matriz[TAM][TAM]){

    int *ponteiro = matriz;
    int soma = 0;
    for(int i = 0; i < TAM * TAM; i++){
        soma = soma + (*(ponteiro + i));
    }
    return soma;
}
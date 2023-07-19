/******************************************************************************
MANIPULAÃ‡ÃƒO DE BLOCO DE MEMÃ“RIA: CompreensÃ£o da funÃ§Ã£o malloc
*******************************************************************************/
#define TAM 10

#include <stdio.h>

void imprimeBlocoMemoria(int *pv, int num) {
    int i = 0;
    while (i < TAM * num) {
        printf("%d - %p: %d\n", (pv+i), (pv+i), *(pv+i));
        i++;
    }
}

int* copiaVetorEmBlocoMemoria(int *pv, int vetor[], int num) {
    int i;
    
    pv = (int *) malloc (num * TAM * sizeof(int));
    printf("inicio %d\n", pv);
    if (pv) {
        for (i = 0; i < (num * TAM); i++)
            *(pv+i) = vetor[i%TAM];
    }
    else {
        printf("MemÃ³ria insuficente !");
        exit(1);
    }
    return pv;
}

int main() {
    int vetor[TAM] = {10,20,30,40,50,60,70,80,90,100};
    int *pv, num;
    
    printf("Digite quantas copias do vetor voce quer fazer na memoria:\n");
    scanf("%d", &num);

    pv = copiaVetorEmBlocoMemoria(pv, vetor, num);
    imprimeBlocoMemoria(pv, num);
    
    free(pv);

    return 0;
}
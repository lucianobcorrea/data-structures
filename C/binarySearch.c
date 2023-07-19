#include <stdio.h>
#include <stdlib.h>

#define TAM 20

int buscaBinaria(int vetor[TAM], int num);
int buscaBinariaRecursiva(int vetor[TAM], int num, int base, int topo);

int main(){
    int base = 0, topo = TAM - 1;
    int num;
    int vetor[TAM] = {1,5,10,15,20,25,30,35,40,45,50,55,60,65,70,75,80,85,90,95};
    printf("Digite um numero: ");
    scanf("%d", &num);
    printf("O numero da posicao %d do vetor e: %d", num, buscaBinaria(vetor, num));
    printf("\n");
    printf("O numero da posicao %d do vetor e: %d", num, buscaBinariaRecursiva(vetor, num, base, topo));

    return 0;
}

int buscaBinaria(int vetor[TAM], int num){
    int base = 0, topo = TAM - 1;
    while(base <= topo){
        int metade = (base + topo) / 2;
        if(vetor[metade] == num){
            return metade;
        }
        if(vetor[metade] < num){
            base = metade + 1;
        }else{
            topo = metade - 1;
        }
    }
    return -1;
}

int buscaBinariaRecursiva(int vetor[TAM], int num, int base, int topo){
    int metade = (base + topo) / 2;
    if(base > topo){
        return -1;
    } 
    if(vetor[metade] == num){
        return metade;
    }
    if(vetor[metade] < num){
        return buscaBinariaRecursiva(vetor, num, base + 1, topo);
    }else{
        return buscaBinariaRecursiva(vetor, num, base, topo - 1);
    }
}
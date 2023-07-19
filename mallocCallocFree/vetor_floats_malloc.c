#include <stdio.h>
#include <stdlib.h>

void lista_floats(float *vetor, int qtd);

int main(){

    int qtd;
    float *vetor;
    printf("Quantos valores float vc deseja armazenar? ");
    scanf("%d", &qtd);
    vetor = (float *) malloc (qtd * sizeof(float));

    if(vetor != NULL){
        for(int i = 0; i < qtd; i++){
            printf("0%d float: ", i + 1);
            scanf("%f", &vetor[i]);
        }
        lista_floats(vetor, qtd);
        free(vetor);
    }else{
        printf("Problema ao alocar memoria!");
    }

    return 0;
}

void lista_floats(float *vetor, int qtd){

    printf("Lista de floats: \n");
    for(int i = 0; i < qtd; i++){
        printf("%.2f\n", *vetor);
        vetor++;
    }
}
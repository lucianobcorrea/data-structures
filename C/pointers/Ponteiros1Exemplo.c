#include <stdlib.h>
#include <stdio.h>

int main(){

    float nota = 8.9, valor = 0.0;
    float *p1, *p2;

    p1 = &nota;
    printf("IMPRIMINDO OS VALORES\n\n");
    printf("ENDERECO DE p1: %u\n", &p1);
    printf("CONTEUDO DE p1: %u\n", p1);
    printf("CONTEUDO DA VARIAVEL PARA A QUAL p1 APONTA: %f\n", *p1);
    printf("CONTEUDO DA VARIAVEL nota: %f\n", nota);
    printf("\n");

    p2 = p1;
    printf("ENDERECO DE p2: %u\n", &p2);
    printf("CONTEUDO DE p2: %u\n", p2);
    printf("CONTEUDO DA VARIAVEL PARA A QUAL p2 APONTA: %f\n", *p2);
    printf("\n");

    valor = *p1;
    printf("CONTEUDO DA VARIAVEL valor: %f\n", valor);

    return 0;
}
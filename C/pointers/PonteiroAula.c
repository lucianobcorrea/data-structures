#include <stdlib.h>
#include <stdio.h>

int main(){

    int a, b;
    void trocar(int *p1, int *p2);

    printf("Primeiro valor a: ");
    scanf("%d", &a);
    printf("Segundo valor b: ");
    scanf("%d", &b);

    trocar(&a, &b);
    printf("a: %d - b: %d", a, b);
    
    return 0;
}

void trocar(int *p1, int *p2){
    int aux;
    aux = *p1;
    *p1 = *p2;
    *p2 = aux;
}
#include <stdlib.h>
#include <stdio.h>

#define CLEAN_BUFF do{ int c; while((c = getchar()) != '\n' && c != EOF);}while(0)

int main(){

    int qtd;
    printf("Quantas strings vc deseja armazenar? ");
    scanf("%d", &qtd);
    CLEAN_BUFF;
    char *strings[qtd];
    printf("Digite as palavras\n");

    for(int i = 0; i < qtd; i++){
        strings[i] = (char*) malloc(31);
        if(strings[i] != NULL){
            scanf("%30[^\n]s", strings[i]);
            CLEAN_BUFF;
        }else{
            printf("Problema ao alocar memoria!");
            exit(1);
        }
    }
    printf("\n");
    listaStrings(strings, qtd);
    for(int i = 0; i < qtd; i++){
        free(strings[i]);
    }
    return 0;
}

void listaStrings(char *strings[], int qtd){
    printf("--STRINGS--\n");
    for(int i = 0; i < qtd; i++){
        printf("String 0%d: %s\n", i + 1, strings[i]);
    }
}
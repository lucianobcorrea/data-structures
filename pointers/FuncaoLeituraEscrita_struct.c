#include <stdlib.h>
#include <stdio.h>

#define CLEAN_BUFF do{ int c; while((c = getchar()) != '\n' && c != EOF);}while(0)

struct TipoProduto{
    int codigo;
    char descricao[60];
};

void leitura(struct TipoProduto *p, int qtd);
void escrita(struct TipoProduto *p, int qtd);

int main(){

    int qtd = 3;
    struct TipoProduto *p, vetor[3];

    p = vetor;

    leitura(p, qtd);
    printf("\n");
    escrita(p, qtd);

    return 0;

}

void leitura(struct TipoProduto *p, int qtd){
    
    for(int i = 0; i < qtd; i++){
        printf("Codigo: ");
        scanf("%d", &p[i].codigo);
        printf("Descricao: ");
        CLEAN_BUFF;
        scanf("%60[^\n]s", &p[i].descricao);
    }   
}

void escrita(struct TipoProduto *p, int qtd){

    printf("::::PRODUTOS E SEUS CODIGOS::::\n\n");

    for(int i = 0; i < qtd; i++){
        printf("Codigo: %d\n", p[i].codigo);
        printf("Descricao: %s\n", p[i].descricao);
    }
}
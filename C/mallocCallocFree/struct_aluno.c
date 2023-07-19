#include <stdlib.h>
#include <stdio.h>

#define CLEAN_BUFF do{ int c; while((c = getchar()) != '\n' && c != EOF);}while(0)

struct aluno{
    int matricula;
    char nome[30];
    float media;
};

int main(){

    struct aluno *alunos;
    int qtd;
    printf("Quantos alunos vc quer armazenar? ");
    scanf("%d", &qtd);
    alunos = (struct aluno *) malloc (qtd * sizeof(struct aluno));

    if(alunos != NULL){
        leituraAlunos(alunos, qtd);
    }else{
        printf("Problema ao alocar memoria!");
    }
    listaAlunos(alunos, qtd);
    free(alunos);
    return 0;
}

void leituraAlunos(struct aluno *alunos, int qtd){
    for(int i = 0; i < qtd; i++){
        printf("\nMatricula: ");
        scanf("%d", &alunos[i].matricula);
        CLEAN_BUFF;
        printf("\nNome: ");
        scanf("%30[^\n]s", alunos[i].nome);
        CLEAN_BUFF;
        printf("\nMedia: ");
        scanf("%f", &alunos[i].media);
        CLEAN_BUFF;
    }
}

void listaAlunos(struct aluno *alunos, int qtd){
    for(int i = 0; i < qtd; i++){
        printf("\nMatricula: %d", alunos[i].matricula);
        printf("\nNome: %s", alunos[i].nome);
        printf("\nMedia: %.2f", alunos[i].media);
        printf("\n");
    }
}
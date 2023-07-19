#include <stdlib.h>
#include <stdio.h>

#define CLEAN_BUFF do{ int c; while((c = getchar()) != '\n' && c != EOF);}while(0)

struct Aluno {
    int matricula;
    char nome[100];
    float media;
    struct Aluno *proximo;
};

void leListaAlunos(struct Aluno *aux);
void imprimirListaAlunos(struct Aluno *aux);

int main(){
    struct Aluno *cabeca;
    cabeca = (struct Aluno *) malloc (sizeof(struct Aluno));
    leListaAlunos(cabeca);
    cabeca -> proximo = (struct Aluno *) malloc (sizeof(struct Aluno));
    leListaAlunos(cabeca -> proximo);
    cabeca -> proximo -> proximo = (struct Aluno *) malloc (sizeof(struct Aluno));
    leListaAlunos(cabeca -> proximo -> proximo);
    imprimirListaAlunos(cabeca);
}

void leListaAlunos(struct Aluno *aux){
    printf("Matricula: ");
    scanf("%d", &aux -> matricula);
    CLEAN_BUFF;
    printf("Nome: ");
    scanf("%30[^\n]s", aux -> nome);
    CLEAN_BUFF;
    printf("Media: ");
    scanf("%f", &aux -> media);
    CLEAN_BUFF;
    aux -> proximo = NULL;
    printf("\n");
}

void imprimirListaAlunos(struct Aluno *aux){
    struct Aluno *paux;
    for(paux = aux; paux != NULL; paux = paux -> proximo){
        printf("Matricula: %d\nNome: %s\nMedia: %.2f\n", paux -> matricula, paux -> nome, paux -> media);
        printf("\n");
    }
}
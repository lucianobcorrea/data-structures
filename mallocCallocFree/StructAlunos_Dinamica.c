#include <stdio.h>
#include <stdlib.h>

#define CLEAN_BUFF do{ int c; while((c = getchar()) != '\n' && c != EOF);}while(0)
#define TAM_STR 30

struct aluno
{
    int matricula;
    char nome[TAM_STR];
    float media;
};

void lista_alunos(struct aluno *p, int num);

int main()
{

    struct aluno *alunos;
    int num = 0, i = 0;

    printf("Quantos alunos voce deseja armazenar: ");
    scanf("%d", &num);
    system("cls");
    
    alunos = (struct aluno*) malloc (num * sizeof(struct aluno));

    if (alunos != NULL){

        for (i = 0; i < num; i++){

            printf("Matricula Aluno 0%d: ", (i + 1));
            scanf("%d", &alunos[i].matricula);
            printf("Nome Aluno 0%d: ", (i + 1));
            CLEAN_BUFF;
            scanf("%30[^\n]s", &alunos[i].nome);
            printf("Media Aluno 0%d: ", (i + 1));
            scanf("%f", &alunos[i].media);
            printf("\n");
        }

        lista_alunos(alunos, num);
        free(alunos);

    }
    else
    {
        printf("*** Problema ao alocar memoria! ***");
        exit(1);
    }

    return 0;
}

void lista_alunos(struct aluno *p, int num)
{

    printf("::: ALUNOS CADASTRADOS :::\n\n");

    for (int i = 0; i < num; i++)
    {
        printf("Matricula: %d\n", p[i].matricula);
        printf("Nome: %s\n", p[i].nome);
        printf("Media: %.2f\n", p[i].media);
        printf("\n");
    }
}
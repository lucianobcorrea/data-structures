#include <stdlib.h>
#include <stdio.h>

#define CLEAN_BUFF do{ int c; while((c = getchar()) != '\n' && c != EOF);}while(0)

int main()
{
    int num;
    char c;
    void lista_strings(char *strings[], int num);

    printf("Quantas strings voce deseja armazenar? ");
    scanf("%d", &num);
    char *strings[num];
    printf("\n");
    CLEAN_BUFF;

    printf("Digite as palavras:\n");
    for (int i = 0; i < num; i++){

        strings[i] = (char*) malloc(31);

        if (strings[i] != NULL){
            fgets(strings[i], 31, stdin);
            //CONSOME A LINHA EM BRANCO (\n)
            strings[i][strcspn(strings[i], "\n")] = 0;           
        }
        else{
            printf("*** Não foi possível alocar memoria! ***");
            exit(1);
        }
    }

    lista_strings(strings, num);
    for (int i = 0; i < num; i++){

        free(strings[i]);
    }

    return 0;
}

void lista_strings(char *strings[], int num){

    printf("\n::: PALAVRAS :::\n");
    for (int i = 0; i < num; i++){

        printf("%s\n", strings[i]);
    }
}



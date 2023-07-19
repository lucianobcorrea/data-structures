#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CLEAN_BUFF do{ int c; while((c = getchar()) != '\n' && c != EOF);}while(0)

struct PontoTuristico
{
    char descricao[41];
    float latitude;
    float longitude;
    struct PontoTuristico *anterior;
    struct PontoTuristico *proximo;
};
typedef struct PontoTuristico PontoTuristico;

struct descritor_lista
{
    PontoTuristico *inicio;
    PontoTuristico *fim;
    int tamanho;
};
typedef struct descritor_lista TipoDescritorLista;

/* Criação de uma lista vazia */

void criar_lista(TipoDescritorLista *descritor_lista)
{
    descritor_lista->inicio = NULL;
    descritor_lista->fim = NULL;
    descritor_lista->tamanho = 0;
}

/* Leitura de um novo ponto turistico */

void lerPontoTuristico(struct PontoTuristico *aux)
{
    printf("\nDescricao: ");
    scanf("%[^\n]", aux->descricao);
    CLEAN_BUFF;
    printf("\nLatitude: ");
    scanf("%f", &aux->latitude);
    CLEAN_BUFF;
    printf("\nLongitude: ");
    scanf("%f", &aux->longitude);
    CLEAN_BUFF;
}

/* Insercao no início da lista */

void inserir_lista_inicio(TipoDescritorLista *descritor_lista)
{
    PontoTuristico *novo = (PontoTuristico *)malloc(sizeof(PontoTuristico));
    lerPontoTuristico(novo);
    if (!descritor_lista->inicio){
        novo->proximo = NULL;
        novo->anterior = NULL;
        descritor_lista -> fim = novo;
    }
    else{
        novo->anterior = NULL;
        novo->proximo = descritor_lista->inicio;
        descritor_lista->inicio->anterior = novo;
    }
    descritor_lista->inicio = novo;
    descritor_lista->tamanho++;
}

void inserir_lista_final(TipoDescritorLista *descritor_lista){
    PontoTuristico *novo = (PontoTuristico *)malloc(sizeof(PontoTuristico));
    lerPontoTuristico(novo);
    if(!descritor_lista -> inicio){
        novo -> proximo = NULL;
        novo -> anterior = NULL;
        descritor_lista -> inicio = novo;
    }else{
        novo -> proximo = NULL;
        novo -> anterior = descritor_lista -> fim;
        descritor_lista -> fim -> proximo = novo;
    }
    descritor_lista -> fim = novo;
    descritor_lista -> tamanho++;
}

void imprimir_lista(TipoDescritorLista *descritor_lista){
    if(!descritor_lista->inicio){
        printf("Lista Vazia!");
    }else{
        PontoTuristico *paux;
        for(paux = descritor_lista -> inicio; paux != NULL; paux = paux -> proximo){
            printf("\nDescricao: %s\nLatitude: %.2f\nLongitude: %.2f\n", paux -> descricao, paux -> latitude, paux -> longitude);
        }
    }
}

int main(){
    TipoDescritorLista *descritorLista;
    descritorLista = (TipoDescritorLista *) malloc (sizeof(TipoDescritorLista));
    criar_lista(descritorLista);

    imprimir_lista(descritorLista); 
    inserir_lista_inicio(descritorLista);
    inserir_lista_inicio(descritorLista);
    inserir_lista_final(descritorLista);
    imprimir_lista(descritorLista);

    return 0;
}
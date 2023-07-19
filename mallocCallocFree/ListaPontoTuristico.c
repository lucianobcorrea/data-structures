#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CLEAN_BUFF do{ int c; while((c = getchar()) != '\n' && c != EOF);}while(0)
#define TAM 41

struct pontoTuristico{
    char descricao[41];
    float latitude;
    float longitude;
    struct pontoTuristico *proximo;
};

struct pontoTuristico* inserirInicio(struct pontoTuristico *cabeca);
struct pontoTuristico* criarLista();
void imprimeLista(struct pontoTuristico *aux);
void lerPontoTuristico(struct pontoTuristico *aux);
struct pontoTuristico* inserirFinal(struct pontoTuristico *cabeca);
struct pontoTuristico* buscarLista(struct pontoTuristico *cabeca, char *descricao);
struct pontoTuristico* removerLista(struct pontoTuristico *cabeca, char *descricao);

int main(){
    struct pontoTuristico *cabeca;
    struct pontoTuristico *lista1;
    struct pontoTuristico *lista2;  
    int *teste;
    char descricao[TAM];

    lista1 = criarLista();
    lista2 = criarLista();
    lista1 = inserirInicio(lista1);
    lista2 = inserirInicio(lista2);

    imprimeLista(lista1);
    imprimeLista(lista2);
    printf("Comparando as duas listas..."); getchar();
    if(compararListas(lista1, lista2) == 1){
        printf("Listas Iguais!");
    }else{
        printf("Diferentes!");
    } 
    printf("\n\n");

    cabeca = criarLista();
    cabeca = inserirInicio(cabeca);
    cabeca = inserirInicio(cabeca);
    cabeca = inserirInicio(cabeca);

    printf("Imprimindo os nodos inseridos..."); getchar();
    imprimeLista(cabeca);
    printf("\n");

    printf("Qual Ponto Turistico voce deseja buscar? ");
    scanf("%30[^\n]s", descricao);
    CLEAN_BUFF;
    struct pontoTuristico *busca = buscarLista(cabeca, descricao); 
    printf("Procurando..."); getchar();
    if(busca != NULL){
        printf("Ponto Turistico encontrado: %s - Latitude: %.2f - Longitude: %.2f", 
        busca -> descricao, busca -> latitude, busca -> longitude);
    }else{
        printf("Ponto Turistico Nao Encontrado");
    }

    printf("\nQual Ponto Turistico voce deseja remover? ");
    scanf("%30[^\n]s", descricao);
    CLEAN_BUFF;
    printf("Removendo o nodo %s...", descricao); getchar();
    cabeca = removerLista(cabeca, descricao);

    printf("Imprimindo os blocos restantes..."); getchar();
    imprimeLista(cabeca);
    printf("Liberando todos os blocos da lista..."); getchar();
    cabeca = liberarLista(cabeca);

    return 0;
}

struct pontoTuristico* criarLista(){
    return NULL;
}

struct pontoTuristico* inserirInicio(struct pontoTuristico *cabeca){
    struct pontoTuristico *novoPontoTuristico = (struct pontoTuristico *) malloc (sizeof(struct pontoTuristico));
    lerPontoTuristico(novoPontoTuristico);
    novoPontoTuristico -> proximo = cabeca;
    return (novoPontoTuristico);
}

struct pontoTuristico* inserirFinal(struct pontoTuristico *cabeca){
    struct pontoTuristico *auxiliar, *anterior = NULL;
    struct pontoTuristico *novoPontoTuristico = (struct pontoTuristico *) malloc (sizeof(struct pontoTuristico));
    lerPontoTuristico(novoPontoTuristico);
    novoPontoTuristico -> proximo = NULL;
    if(cabeca == NULL){
        cabeca = novoPontoTuristico;
    }else{
        auxiliar = cabeca;
        while(auxiliar != NULL){
            anterior = auxiliar;
            auxiliar = auxiliar -> proximo;
        }
        anterior -> proximo = novoPontoTuristico;
    }
    return cabeca;
}

void imprimeLista(struct pontoTuristico *aux){
    struct pontoTuristico *paux;
    for(paux = aux; paux != NULL; paux = paux -> proximo){
        printf("Descricao: %s\tLatitude: %.2f\tLongitude: %.2f\t\n", paux -> descricao, paux -> latitude, paux -> longitude);
    }
}

void lerPontoTuristico(struct pontoTuristico *aux){
    printf("Descricao: ");
    scanf("%30[^\n]s", aux -> descricao);
    CLEAN_BUFF;
    printf("Latitude: ");
    scanf("%f", &aux -> latitude);
    CLEAN_BUFF;
    printf("Longitude: ");
    scanf("%f", &aux -> longitude);
    CLEAN_BUFF;
    printf("\n");
}

struct pontoTuristico* buscarLista(struct pontoTuristico *cabeca, char *descricao){
    struct pontoTuristico *paux;
    for(paux = cabeca; paux != NULL; paux = paux -> proximo){
        if(strcmpi(paux -> descricao, descricao) == 0){
            return paux;
        }
    }
    return NULL;
}

int compararListas(struct pontoTuristico *ponto1, struct pontoTuristico *ponto2){
    struct pontoTuristico *atual1 = ponto1;
    struct pontoTuristico *atual2 = ponto2;
    while(atual1 != NULL || atual2 != NULL){
        if(strcmpi(atual1 -> descricao, atual2 -> descricao) != 0 || atual1 == NULL || atual2 == NULL){
            return 0;
        }
        atual1 = atual1 -> proximo;
        atual2 = atual2 -> proximo;
    }
    return 1;
}

struct pontoTuristico* removerLista(struct pontoTuristico *cabeca, char *descricao){
    struct pontoTuristico *paux = cabeca;
    struct pontoTuristico *anterior = NULL;
    while(strcmpi(paux -> descricao, descricao) != 0 && paux != NULL){
        anterior = paux;
        paux = paux -> proximo;
    }
    if(paux == NULL){
        return NULL;
    }
    if(anterior == NULL){
        cabeca = paux -> proximo;
    }else{
        anterior -> proximo = paux -> proximo;
        free(paux);
        return cabeca;
    }

}

struct pontoTuristico* liberarLista(struct pontoTuristico *cabeca){
    struct pontoTuristico *aux = NULL;
    struct pontoTuristico *paux = cabeca;
    while(paux != NULL){
        aux = paux -> proximo;
        free(paux);
        paux = aux;
    }
    return NULL;
}

int verificar_lista_vazia(struct PontoTuristico* cabeca) {
    return (cabeca == NULL);
}
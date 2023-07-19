#include <stdlib.h>
#include <stdio.h>

#define CLEAN_BUFF do{ int c; while((c = getchar()) != '\n' && c != EOF);}while(0)

struct PontoTuristico{
    char descricao[41];
    float latitude;
    float longitude;
    struct PontoTuristico *proximo;
};

struct PontoTuristico *criar_lista();
struct PontoTuristico *inserir_inicio(struct PontoTuristico *cabeca);
void imprimir(struct PontoTuristico *cabeca);
struct PontoTuristico *inserir_final(struct PontoTuristico *cabeca);
struct PontoTuristico *buscar_lista(struct PontoTuristico *cabeca, char *desc);
struct PontoTuristico *remover_lista(struct PontoTuristico *cabeca, char *desc);

int main(){

    struct PontoTuristico *cabeca;
    cabeca = criar_lista();
    cabeca = inserir_inicio(cabeca);
    cabeca = inserir_final(cabeca); 


    return 0;
}

struct PontoTuristico *criar_lista(){
    return NULL;
}

struct PontoTuristico *inserir_inicio(struct PontoTuristico *cabeca){
    struct PontoTuristico *novo = (struct PontoTuristico *) malloc (sizeof(struct PontoTuristico));
    ler_ponto_turistico(novo);
    novo -> proximo = cabeca;
    return (novo);
}

struct PontoTuristico *inserir_final(struct PontoTuristico *cabeca){

}

void imprimir(struct PontoTuristico *cabeca){
    struct PontoTuristico *paux;
    for(paux = cabeca; paux != NULL; paux = paux -> proximo){
        printf("Descricao: %s\tLatitude: %.2f\tLongitude: %.2f\t\n",paux->descricao,
    paux->latitude, paux->longitude);
    }
}

struct PontoTuristico *buscar_lista(struct PontoTuristico *cabeca, char *desc){
    struct PontoTuristico *paux;
    for(paux = cabeca; paux != NULL; paux = paux -> proximo){
        if(strcmpi(paux -> descricao, desc) == 0){
            return paux;
        }
    }
    return NULL;
}

struct PontoTuristico *remover_lista(struct PontoTuristico *cabeca, char *desc){
    struct PontoTuristico *paux = cabeca;
    struct PontoTuristico *anterior_paux = NULL;
    while(paux != NULL && strcmpi(paux -> descricao, desc) != 0){
        anterior_paux = paux;
        paux = paux -> proximo;
    }
    if(paux == NULL){
        return NULL;
    }
    if(anterior_paux == NULL){
        cabeca = paux -> proximo;
    }else{
        anterior_paux -> proximo = paux -> proximo;
        free(paux);
        return cabeca;
    }
}

void ler_ponto_turistico(struct PontoTuristico *aux){
    printf("\nDescricao: ");
    scanf("%41[^\n]s", aux -> descricao);
    CLEAN_BUFF;
    printf("\nLatitude: ");
    scanf("%f", aux -> latitude);
    CLEAN_BUFF;
    printf("Longitude: ");
    scanf("%f", aux -> longitude);
    CLEAN_BUFF;
}
    


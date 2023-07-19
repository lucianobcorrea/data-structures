#include <stdio.h>
#include <string.h>

#define TAM_PILHA 52

struct carta
{
    int numero;
    char naipe;
};
typedef struct carta TipoCarta;

struct pilha
{
    TipoCarta informacao[TAM_PILHA];
    int topo;
};
typedef struct pilha TipoPilha;

/* INICIALIZA PILHA */
TipoPilha criar(TipoPilha pilha)
{
    pilha.topo = 0;
    return pilha;
}

/* RETORNAR ELEMENTO DO TOPO DA PILHA */
TipoCarta buscar_topo(TipoPilha pilha)
{
    return pilha.informacao[pilha.topo - 1];
}

/* VERIFICA SE PILHA ESTÃ VAZIA */
int verificar_vazia(TipoPilha pilha)
{
    return !pilha.topo;
}

/* EMPILHANDO UM NODO NA PILHA */
TipoPilha push(TipoCarta carta, TipoPilha pilha)
{
    if (pilha.topo >= 0 && pilha.topo < TAM_PILHA)
        pilha.informacao[pilha.topo++] = carta;
    else
        printf("FORA DOS LIMITES DA PILHA !!!\n");
    return pilha;
}

/* DESEMPILHANDO UM NODO NA PILHA E RETORNANDO O VALOR QUE FOI DESEMPILHADO*/
TipoPilha pop(TipoPilha pilha)
{
    if (verificar_vazia(pilha))
        printf("Pilha Vazia !!!\n");
    else
    {
        pilha.topo--;
        printf("Carta que saiu da pilha: %d%c\n",
               pilha.informacao[pilha.topo].numero,
               pilha.informacao[pilha.topo].naipe);
    }
    return pilha;
}

void imprimir(TipoPilha pilha)
{
    int i = pilha.topo - 1;
    printf("PILHA ATUAL\n");
    while (i >= 0)
    {
        printf("%d%c \n", pilha.informacao[i].numero, pilha.informacao[i].naipe);
        i--;
    }
}

int main()
{
    TipoPilha pilha;
    TipoCarta carta;

    pilha = criar(pilha);
    carta.numero = 1;
    carta.naipe = 'E';
    pilha = push(carta, pilha);
    imprimir(pilha);
    getchar();
    carta.numero = 2;
    carta.naipe = 'E';
    pilha = push(carta, pilha);
    imprimir(pilha);
    getchar();
    carta.numero = 3;
    carta.naipe = 'E';
    pilha = push(carta, pilha);
    imprimir(pilha);
    getchar();
    carta.numero = 4;
    carta.naipe = 'E';
    pilha = push(carta, pilha);
    imprimir(pilha);
    getchar();
    pilha = pop(pilha);
    imprimir(pilha);
    getchar();
    carta.numero = 9;
    carta.naipe = 'C';
    pilha = push(carta, pilha);
    imprimir(pilha);
    getchar();
    pilha = pop(pilha);
    imprimir(pilha);
    getchar();
    pilha = pop(pilha);
    imprimir(pilha);
    getchar();
    pilha = pop(pilha);
    imprimir(pilha);
    getchar();
    pilha = pop(pilha);
    imprimir(pilha);
    getchar();
    return 0;
}
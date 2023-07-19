#include <stdio.h>
#define TRUE 1
#define FALSE 0

struct nodo
{
    int conteudo;
    struct nodo *link;
};
typedef struct nodo TipoNodo;

struct pilha
{
    TipoNodo *topo;
    int tam;
};
typedef struct pilha TipoPilha;

/* INICIALIZA PILHA */
void inicializar(TipoPilha *pilha)
{
    pilha->tam = 0;
    pilha->topo = NULL;
}

/* RETORNAR ELEMENTO DO TOPO DA PILHA */
int buscar_topo(TipoPilha *pilha)
{
    return pilha->topo->conteudo;
}

/* VERIFICA SE PILHA ESTÁ VAZIA */
int estaVazia(TipoPilha *pilha)
{
    if (pilha->topo == NULL)
        return TRUE;
    else
        return FALSE;
}

/* EMPILHANDO UM NODO NA PILHA */
void empilhar(int valor, TipoPilha *pilha)
{
    TipoNodo *nodo_novo;
    nodo_novo = (TipoNodo *)malloc(sizeof(TipoNodo));
    if (nodo_novo)
    {
        nodo_novo->conteudo = valor;
        nodo_novo->link = pilha->topo;
        pilha->topo = nodo_novo;
        pilha->tam++;
    }
    else
        printf("Overflow !!!\n");
}

/* DESEMPILHANDO UM NODO NA PILHA E RETORNANDO O VALOR QUE FOI DESEMPILHADO*/
int desempilhar(TipoPilha *pilha)
{
    TipoNodo *nodo_que_sai_topo;
    int valor_nodo_que_sai_topo;

    if (estaVazia(pilha))
    {
        printf("Lista Vazia !!!");
        return 0;
    }
    else
    {
        nodo_que_sai_topo = pilha->topo;
        pilha->topo = nodo_que_sai_topo->link;

        valor_nodo_que_sai_topo = nodo_que_sai_topo->conteudo;

        free(nodo_que_sai_topo);
        pilha->tam--;
        return valor_nodo_que_sai_topo;
    }
}

int imprimir(TipoPilha *pilha)
{
    TipoNodo *paux;
    paux = pilha->topo;
    printf("PILHA ATUAL\n");
    while (paux)
    {
        printf("%d\n", paux->conteudo);
        paux = paux->link;
    }
}

int main()
{
    int i, numero;
    TipoPilha *pilha;
    pilha = (TipoPilha *)malloc(sizeof(TipoPilha));
    inicializar(pilha);

    empilhar(15, pilha);
    imprimir(pilha);
    getchar();
    empilhar(10, pilha);
    imprimir(pilha);
    getchar();
    empilhar(12, pilha);
    imprimir(pilha);
    getchar();
    empilhar(12, pilha);
    imprimir(pilha);
    getchar();
    desempilhar(pilha);
    imprimir(pilha);
    getchar();
    desempilhar(pilha);
    imprimir(pilha);
    getchar();
    desempilhar(pilha);
    imprimir(pilha);
    getchar();
    desempilhar(pilha);
    imprimir(pilha);
    getchar();
    desempilhar(pilha);
    imprimir(pilha);
    getchar();
    desempilhar(pilha);
    imprimir(pilha);
    getchar();

    return 0;
}
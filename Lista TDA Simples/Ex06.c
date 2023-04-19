#include <stdio.h>
#include <stdlib.h>

typedef struct bloco
{
    int valor;
    struct bloco *prox;
} Bloco;

typedef struct lista
{
    Bloco *inicio;
    Bloco *fim;
} Lista;

int inserir(Lista *l, int valor)
{
    Bloco *temp = (Bloco *)malloc(sizeof(Bloco)), *perc = l->inicio;
    if (temp == NULL)
        return 0;
    temp->prox = NULL;
    temp->valor = valor;
    if (l->inicio == NULL)
        l->inicio = l->fim = temp;
    else
    {
        for (; perc->prox != NULL; perc = perc->prox);
        perc->prox = temp;
        l->fim = temp;
    }
    return 1;
}

Lista *separa(Lista *l, int n)
{
    if (l == NULL)return 0;
    Bloco *perc = l->inicio;
    Lista *l2 = (Lista*)malloc(sizeof(Lista));
    for (; perc->prox != NULL && perc->prox->valor != n; perc = perc->prox);
    l2->inicio = perc->prox;
    perc->prox = NULL;
    l->fim = perc;
    perc = l2->inicio;
    for (; perc->prox != NULL; perc = perc->prox);
    l2->fim = perc;
    return l2;
}

Lista *concatena(Lista *l1, Lista *l2){
    Lista *concatenada = (Lista*)malloc(sizeof(Lista));
    Bloco *perc = l1->inicio;
    concatenada->inicio = l1->inicio;
    for(; perc->prox != NULL; perc = perc->prox);
    perc->prox = l2->inicio;
    perc = l2->inicio;
    for(; perc->prox != NULL; perc = perc->prox);
    concatenada->fim = perc;
    return concatenada;
}

int main()
{
    Lista l1, l3;
    Lista *l2;
    l1.inicio = l1.fim = l3.inicio = l3.fim = NULL;
    inserir(&l1, 3);
    inserir(&l1, 17);
    inserir(&l3, 5);
    inserir(&l3, 12);
    inserir(&l3, 11);
    l2 = concatena(&l1, &l3);
    return 0;
}
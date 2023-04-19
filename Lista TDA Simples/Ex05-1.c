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
        for (; perc->prox != NULL; perc = perc->prox)
            ;
        perc->prox = temp;
    }
    return 1;
}

Lista *separa(Lista *l, int n)
{
    if (l == NULL)return 0;
    Bloco *perc = l->inicio;
    Bloco *temp;
    for (; perc->prox != NULL && perc->prox->valor != n; perc = perc->prox);
    temp = perc->prox;
    perc->prox = NULL;
    return temp;
}

int main()
{
    Lista l;
    l.inicio = l.fim = NULL;
    inserir(&l, 3);
    inserir(&l, 17);
    inserir(&l, 5);
    inserir(&l, 12);
    inserir(&l, 1);
    Lista *l2 = separa(&l, 5);
}
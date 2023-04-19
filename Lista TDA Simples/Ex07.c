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
        l->fim = temp;
    }
    return 1;
}

Lista *constroi(int n, int *v)
{
    Lista *novalista = (Lista *)malloc(sizeof(Lista));
    Bloco *perc;
    novalista->inicio = novalista->fim = NULL;
    for (int i = 0; i < n; i++)
    {
        Bloco *temp = (Bloco *)malloc(sizeof(Bloco));
        temp->prox = NULL;
        temp->valor = v[i];
        if (i == 0)
        {
            novalista->inicio = novalista->fim = temp;
            perc = novalista->inicio;
        }
        else
        {
            for (; perc->prox != NULL; perc = perc->prox);
            perc->prox = temp;
        }
    }
    novalista->fim = perc->prox;
    return novalista;
}

int main()
{
    Lista *l1;
    int v[5] = {3, 8, 1, 7, 2};
    l1 = constroi(5, &v);
    return 0;
}
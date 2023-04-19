#include <stdio.h>
#include <stdlib.h>

typedef struct bloco
{
    int valor;
    struct bloco *prox;
    struct bloco *ant;
} Bloco;

typedef struct fila
{
    Bloco *inicio;
    Bloco *fim;
} Fila;

int inserir(Fila *f, int valor)
{
    Bloco *temp = (Bloco *)malloc(sizeof(Bloco)), *perc = f->inicio;
    if (temp == NULL)
        return 0;
    temp->prox = temp->ant = NULL;
    temp->valor = valor;
    if (f->inicio == NULL)
        f->inicio = f->fim = temp;
    else
    {
        for (; perc->ant != NULL; perc = perc->ant)
            ;
        perc->ant = f->fim = temp;
        temp->prox = perc;
    }
    return 1;
}

int remover(Fila *f)
{
    Bloco *perc = f->inicio, *temp;
    if (perc == NULL)return 0;
    for (; perc->ant != NULL && perc->valor != perc->ant->valor; perc = perc->ant);
    temp = perc->ant;
    if (perc->ant == NULL)return 0;

    else if (perc->ant->ant == NULL)
    {
        perc->ant = temp->prox = NULL;
        f->fim = perc;
    }

    else
    {
        perc->ant = perc->ant->ant;
        perc->ant->prox = perc;
        temp->prox = temp->ant = NULL;
    }
    free(temp);
    if (perc->ant != NULL)remover(f); // Recursividade me fudeo
    return 1;
}

int main()
{
    Fila f;
    f.inicio = f.fim = NULL;
    inserir(&f, 0);
    inserir(&f, 0);
    inserir(&f, 1);
    inserir(&f, 2);
    inserir(&f, 3);
    inserir(&f, 4);
    inserir(&f, 4);
    inserir(&f, 5);
    inserir(&f, 5);
    remover(&f);
}
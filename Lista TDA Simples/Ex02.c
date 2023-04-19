#include <stdio.h>
#include <stdlib.h>

typedef struct bloco
{
    int valor;
    struct bloco *prox;
} Bloco;

typedef struct
{
    Bloco *inicio;
    Bloco *fim;
} Fila;

int troca(Fila *f)
{
    Bloco *perc, *temp;
    perc = f->inicio;
    if (perc == NULL)
        return 0;
    if (f->inicio == f->fim)
        return 0;
    for (; perc->prox->prox != NULL; perc = perc->prox)
        ;
    f->fim->prox = f->inicio->prox;
    f->inicio->prox = NULL;
    temp = f->inicio;
    f->inicio = f->fim;
    f->fim = temp;
    perc->prox = f->fim;
    return 1;
}

int inserir(Fila *f, int valor)
{
    Bloco *temp = (Bloco *)malloc(sizeof(Bloco));
    Bloco *perc;
    if (temp == NULL)
        return 0;
    temp->valor = valor;
    temp->prox = NULL;
    if (f->inicio == NULL)
    {
        f->inicio = f->fim = temp;
    }
    else
    {
        f->fim->prox = temp;
        f->fim = temp;
    }
    return 1;
}

void print_inv(Fila *f)
{
    Bloco *temp = f->inicio;
    if (temp == NULL)
        return 0;
    if (temp->prox == NULL)
        printf("%d\n", temp->valor);
    else
    {
        print_inv(temp->prox);
        printf("%d\n", temp->valor);
    }
}

int misterio(Fila *f, int dado)
{
    struct bloco *aux;
    struct bloco *perc = f->inicio;
    aux = (struct bloco *)malloc(sizeof(struct bloco));
    if (aux == NULL) return 0;
    aux->valor = dado;
    aux->prox = NULL;
    if (f->inicio == NULL)
    {
        f->inicio = aux;
        return 1;
    }
    while ((perc->prox != NULL) && (perc->prox->valor <= dado)) perc = perc->prox;
    aux->prox = perc->prox;
    perc->prox = aux;
    return 1;
}

int main()
{
    Fila f;
    f.inicio = f.fim = NULL;
    inserir(&f, 8);
    inserir(&f, 11);
    inserir(&f, 12);
    inserir(&f, 15);
    inserir(&f, 17);
    misterio(&f, 2);
    return 1;
}
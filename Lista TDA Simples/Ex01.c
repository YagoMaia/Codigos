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
        print_inv(&(temp->prox));
        printf("%d\n", temp->valor);
    }
}

int main()
{
    Fila f;
    f.inicio = f.fim = NULL;
    inserir(&f, 10);
    inserir(&f, 3);
    inserir(&f, 5);
    troca(&f);
    print_inv(&f);
    return 1;
}
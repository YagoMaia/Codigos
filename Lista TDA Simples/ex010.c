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
    if (temp == NULL) return 0;
    temp->prox = NULL;
    temp->valor = valor;
    if (l->inicio == NULL)l->inicio = l->fim = temp;
    else
    {
        for (; perc->prox != NULL; perc = perc->prox);
        perc->prox = temp;
    }
    return 1;
}

void insereNC(Lista *l, int dado, int pos, int NrCopias){
    Bloco *perc=l->inicio;
    for(int i = 0; i < pos && perc != NULL; i++, perc = perc->prox);
    for(int i=0; i<NrCopias; i++){
        Bloco *temp = (Bloco*)malloc(sizeof(Bloco));
        temp->valor = dado;
        temp->prox = NULL;
        if(perc->prox != NULL) temp->prox = perc->prox;
        perc->prox = temp;
        perc = temp;
    }
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
    insereNC(&l, 10, 3, 5);
}
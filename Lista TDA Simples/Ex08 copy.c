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
    int tamanho;
} Lista;

int inserir(Lista *lista, int valor)
{
    Bloco *temp = (Bloco *)malloc(sizeof(Bloco)), *perc = lista->inicio;
    temp->valor = valor;
    temp->prox = NULL;
    if (temp == NULL)
        return 0;
    if (lista->inicio == NULL)
        lista->inicio = lista->fim = temp;
    else
    {
        for (; perc->prox != NULL; perc = perc->prox)
            ;
        perc->prox = temp;
        lista->fim = temp;
    }
    lista->tamanho++;
    return 1;
}

Lista *retira_prefixo(Lista *l, int n)
{
    Lista *novalista = (Lista *)malloc(sizeof(Lista));
    Bloco *temp = (Bloco *)malloc(sizeof(Bloco));
    novalista->inicio = l->inicio;
    novalista->fim = l->fim;
    novalista->tamanho = l->tamanho;
    for (int i = 0; i < n; i++)
    {
        if (n > novalista->tamanho)
        {
            novalista->inicio = novalista->fim = NULL;
            novalista->tamanho = 0;
            return novalista;
        }
        else
        {
            temp = novalista->inicio;
            novalista->inicio = novalista->inicio->prox;
            temp->prox = NULL;
            free(temp);
            novalista->tamanho--;
        }
    }
    return novalista;
}
int main()
{
    Lista l;
    Lista *l2;
    l.inicio = l.fim = NULL;
    l.tamanho = 0;
    inserir(&l, 1);
    inserir(&l, 2);
    inserir(&l, 3);
    inserir(&l, 4);
    inserir(&l, 5);
    inserir(&l, 6);
    l2 = retira_prefixo(&l, 3);
}
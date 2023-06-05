#include <stdio.h>
#include <stdlib.h>

// Questão 2

typedef struct no
{
    int valor;
    struct no *prox;
    struct no *esq;
    struct no *dir;
} No;

typedef struct lista
{
    No *inicio;
    No *fim;
} Lista;

int InsereLista(Lista *l, int valor)
{
    No *temp = (No *)malloc(sizeof(No));
    if (!temp)
        return 0;
    temp->dir = temp->esq = temp->prox = NULL;
    temp->valor = valor;
    if (l->inicio == NULL)
        l->inicio = l->fim = temp;
    else
    {
        l->fim->prox = temp;
        l->fim = temp;
    }
    return 1;
}

No *maior(No *v1, No *v2)
{
    if (v1->valor >= v2->valor)
        return v1;
    else
        return v2;
}

No *menor(No *v1, No *v2)
{
    if (v1->valor <= v2->valor)
        return v1;
    else
        return v2;
}

No *PrimeiroValor(Lista *l)
{
    int menor = l->inicio->valor;
    No *perc = l->inicio;
    No *menorNo = l->inicio;
    for (; perc->prox != NULL; perc = perc->prox)
    {
        if (perc->valor < menor)
            menorNo = perc;
    }
    return menorNo;
}

No *SegundoValor(Lista *l, No *menor1)
{
    int menor2 = l->inicio->valor;
    No *perc = l->inicio;
    No *menorNo = l->inicio;
    for (; perc->prox != NULL; perc = perc->prox)
    {
        if (menorNo == menor1)
            continue;
        else if (perc->valor < menor2)
            menorNo = perc;
    }
    return menorNo;
}

int TransformaArvore(Lista *l)
{
    No *perc;
    if (l->inicio == l->fim)return 1;
    No *v1 = l->inicio;
    No *v2 = l->inicio->prox;
    int soma = v1->valor + v2->valor;
    printf("%d ", soma);
    No *temp = (No *)malloc(sizeof(No));
    if (!temp)return 0;
    temp->dir = v2;
    temp->esq = v1;
    temp->valor = soma;
    for(perc=l->inicio; perc->prox!=NULL && perc->valor < soma; perc=perc->prox);
    if(v2->prox != NULL)l->inicio = v2->prox;
    else l->inicio = temp;
    temp->prox = perc->prox;
    if(perc->prox == NULL)l->fim = temp;
    perc->prox = temp;
    v1->prox = v2->prox = NULL;
    return TransformaArvore(l);
}

int printvalores(No *no)
{
    if(no->esq != NULL && no->dir != NULL){
        printf("Pai: %d\n", no->valor);
        if(no->esq != NULL)printf("Filho Esq: %d\n", no->esq->valor);
        if(no->dir != NULL)printf("Filho Dir: %d\n", no->dir->valor);
        printf("\n");
    }
    if (no->esq != NULL)printvalores(no->esq);
    if (no->dir != NULL)printvalores(no->dir);
    return 1;
}
    
void mostraHierarquia(No *r, int nivel){
    int n;
    if(r == NULL) return;
    for(n = 0; n < nivel ; n++) printf("\t");

    printf("%d\n",r->valor);
    if(r->esq != NULL)
    mostraHierarquia(r->esq, nivel + 1);
    if(r->dir != NULL)
    mostraHierarquia(r->dir,nivel+1);
}

int main()
{
    Lista l;
    l.inicio = l.fim = NULL;
    InsereLista(&l, 1);
    InsereLista(&l, 2);
    InsereLista(&l, 3);
    InsereLista(&l, 4);
    InsereLista(&l, 5);
    InsereLista(&l, 6);
    InsereLista(&l, 7);
    InsereLista(&l, 8);
    InsereLista(&l, 9);
    InsereLista(&l, 10);
    TransformaArvore(&l);
    printf("\n\n");
    printvalores(l.inicio);
    printf("\n");
    mostraHierarquia(l.inicio, 0);
    return 0;
}
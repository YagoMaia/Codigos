#include <stdlib.h>
#include <stdio.h>

typedef struct bloco
{
    int dado;
    struct bloco *esq;
    struct bloco *dir;
} No;

int insereNo(No **raiz, int dado)
{
    No *aux;
    if (*raiz == NULL)
    {
        aux = (No *)malloc(sizeof(No));
        if (aux == NULL)return 0;
        aux->esq = aux->dir = NULL;
        aux->dado = dado;
        *raiz = aux;
    }
    else if (dado < (*raiz)->dado) return insereNo(&(*raiz)->esq, dado);
    else if (dado > (*raiz)->dado) return insereNo(&(*raiz)->dir, dado);
    return 1;
}

void imprimiPreOrder(No **raiz)
{
    if (*raiz != NULL)
    {
        printf("%d ", (*raiz)->dado);
        imprimiPreOrder(&(*raiz)->esq);
        imprimiPreOrder(&(*raiz)->dir);
    }
}

void imprimiPosOrder(No **raiz)
{
    if (*raiz != NULL)
    {
        printf("%d ", (*raiz)->dado);
        imprimiPosOrder(&(*raiz)->dir);
        imprimiPosOrder(&(*raiz)->esq);
    }
}

void imprimiInOrderC(No **raiz)
{
    if (*raiz != NULL)
    {
        imprimiInOrderC(&(*raiz)->esq);
        printf("%d ", (*raiz)->dado);
        imprimiInOrderC(&(*raiz)->dir);
    }
}

void imprimiInOrderD(No **raiz)
{
    if (*raiz != NULL)
    {
        imprimiInOrderD(&(*raiz)->dir);
        printf("%d ", (*raiz)->dado);
        imprimiInOrderD(&(*raiz)->esq);
    }
}

int NivelArvore(No **raiz)
{

    if (*raiz == NULL || ((*raiz)->dir == NULL && (*raiz)->esq == NULL))
        return 0;
    else
    {
        int esq = NivelArvore(&(*raiz)->esq);
        int dir = NivelArvore(&(*raiz)->dir);
        if (esq > dir)
            return esq + 1; // HUMMMMMMMM
        else
            return dir + 1; // HUMMMMMMM
    };
}

int busca(No **raiz, int valor)
{
    if (*raiz == NULL)
        return 0;
    else
    {
        if ((*raiz)->dado == valor)
        {
            return 1;
        }
        else
        {
            if (valor < (*raiz)->dado)
                return busca(&(*raiz)->esq, valor);
            else
                return busca(&(*raiz)->dir, valor);
        }
    }
}

No **buscaNo(No **raiz, int valor)
{
    if (*raiz == NULL)
        return NULL;
    else
    {
        if ((*raiz)->dado == valor)
        {
            return raiz;
        }
        else
        {
            if (valor < (*raiz)->dado)
                return buscaNo(&(*raiz)->esq, valor);
            else
                return buscaNo(&(*raiz)->dir, valor);
        }
    }
}

int AlturaSubArvore(No **raiz, int elemento)
{
    No **no = buscaNo(raiz, elemento);
    if (no != NULL)
        return NivelArvore(no);
    else
        return -1;
}

//void PorAltura(No **raiz)
//{
//    if (*raiz != NULL)
//    {
//        printf("%d\n", (*raiz)->dado);
//        printf(" ");
//        PorAltura(&(*raiz)->esq);
//        printf(" ");
//        PorAltura(&(*raiz)->dir);
//    }
//}

int main()
{
    No *raiz = NULL;
    insereNo(&raiz, 5);
    insereNo(&raiz, 2);
    insereNo(&raiz, 3);
    insereNo(&raiz, 7);
    insereNo(&raiz, 8);
    insereNo(&raiz, 1);
    insereNo(&raiz, 4);
    insereNo(&raiz, 6);
    imprimiPreOrder(&raiz);
    printf("\n");
    imprimiPosOrder(&raiz);
    printf("\n");
    imprimiInOrderC(&raiz);
    printf("\n");
    imprimiInOrderD(&raiz);
    printf("\n");
    printf("%d", NivelArvore(&raiz));
    printf("\n");
    printf("%d", AlturaSubArvore(&raiz, 5));
    printf("\n");
    return 0;
}
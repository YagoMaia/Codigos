#include <stdlib.h>
#include <stdio.h>

typedef struct bloco
{
    int dado;
    struct bloco *esq;
    struct bloco *dir;
}No;

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
    else if (dado < (*raiz)->dado)return insereNo(&(*raiz)->esq, dado);
    else if (dado > (*raiz)->dado)return insereNo(&(*raiz)->dir, dado);
    return 1;
}

void imprimiPreOrder(No **raiz){
    if(*raiz != NULL){
        printf("%d ", (*raiz)->dado);
        imprimiPreOrder(&(*raiz)->esq);
        imprimiPreOrder(&(*raiz)->dir);
    }
}

void imprimiPosOrder(No **raiz){
    if(*raiz != NULL){
        printf("%d ", (*raiz)->dado);
        imprimiPosOrder(&(*raiz)->dir);
        imprimiPosOrder(&(*raiz)->esq);
    }
}

void imprimiInOrderC(No **raiz){
    if(*raiz != NULL){
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

int NivelArvore(No **raiz){
    
    if(*raiz != NULL){
        int esq = NivelArvore(&(*raiz)->esq);
        int dir = NivelArvore(&(*raiz)->dir);
        if(esq > dir) return esq + 1; //HUMMMMMMMM
        else return dir + 1; // HUMMMMMMM
    }
    else return -1;
}

int NivelElemento(No **raiz, int elemento){
    
    if(*raiz != NULL){
        if((*raiz)->dado != elemento){
            int esq = NivelArvore(&(*raiz)->esq);
            int dir = NivelArvore(&(*raiz)->dir);
            if(esq > dir) return esq + 1; //HUMMMMMMMM
            else return dir + 1; // HUMMMMMMM
        }
    }
    else return -1;
}

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
    return 0;
}
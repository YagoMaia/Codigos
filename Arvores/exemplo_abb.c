#include<stdio.h>
#include<stdlib.h>

typedef struct bloco {
    int chave;
    struct bloco *esq;
    struct bloco *dir;
}No;

int insere(No **raiz, int dado) {
    No *temp;
    if(*raiz == NULL){
        temp = (No*)malloc(sizeof(No));
        if(temp == NULL) return 0;
        temp->esq = temp->dir = NULL;
        temp->chave = dado;
        *raiz = temp;
    }
    else if(dado < (*raiz)->chave) return insere(&(*raiz)->esq, dado);
    else if(dado > (*raiz)->chave) return insere(&(*raiz)->dir, dado);
    return 1;
}

void imprimeEmOrdem(No *perc){
    if(perc != NULL){
        imprimeEmOrdem(perc->esq);
        printf("%d ", perc->chave);
        imprimeEmOrdem(perc->dir);
    }
}

int main(){
    No *raiz = NULL;

    insere(&raiz, 5);
    insere(&raiz, 2);
    insere(&raiz, 3);
    insere(&raiz, 7);
    insere(&raiz, 4);
    insere(&raiz, 1);
    insere(&raiz, 8);
    insere(&raiz, 6);

    imprimeEmOrdem(raiz);

    return 0;
}

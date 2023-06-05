#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    int fb;
    int altura;
    struct no *esq;
    struct no *dir;
}No;

int alturano(No *raiz){
    int esq = alturano(raiz->esq);
    int dir = alturano(raiz->dir);
    
}


int insere(No **raiz, int valor){
    No *temp = (No*)malloc(sizeof(No));
    if(temp == NULL) return 0;
    temp->valor = valor;
    temp->altura = temp->fb = 0;
    temp->dir = temp->esq = NULL;
    if(*raiz != NULL){
        if(valor > (*raiz)->valor) return insere(&(*raiz)->dir, valor);
        else if (valor < (*raiz)->valor) return insere(&(*raiz)->esq, valor);
        else return -1;
    }
    else{
        *raiz = temp;
    }

    return 1;
}

int main(){
    No *raiz = NULL;
    insere(&raiz, 10);
    insere(&raiz, 7);
    insere(&raiz, 3);
    insere(&raiz, 2);
    return 0;
}
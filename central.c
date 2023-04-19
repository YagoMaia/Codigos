#include <stdio.h>
#include <stdlib.h>

typedef struct bloco{
    int valor;
    struct bloco *cima;
    struct bloco *baixo;
    struct bloco *esquerda;
    struct bloco *direita;
}Bloco;

typedef struct lista{
    Bloco *central;
}Lista;

int inserir(Lista *l, int valor){
    Bloco *temp = (Bloco *)malloc(sizeof(Bloco));
    if(temp == NULL) return 0;
    temp->cima = temp->baixo = temp->direita = temp->esquerda = NULL;
    temp->valor = valor;
    if(l == NULL){
        l->central = temp;
    }
    else if(valor == l->central->valor){
        temp->cima = l->central->cima;
        l->central->cima = temp;
        temp->baixo = l->central;
        temp->(*cima)->baixo = temp;
    }
}

int main(){
    Lista l;
    inserir(&l, 10);
    inserir(&l, 10);
}
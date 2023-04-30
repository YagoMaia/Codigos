#include <stdio.h>
#include <stdlib.h>

// Descreva a pilha resultante da seguinte série de operações: push(5), push(3), pop(), push(2), push(8), pop(), pop(), push(9), push(1), pop(), push(7), push(6), pop(), pop(), push(4), pop(), pop().

//5 ->resultado final

typedef struct bloco{
    int valor;
    struct bloco *prox;
    struct bloco *ant;
}Bloco;

typedef struct lista{
    Bloco *inicio;
    Bloco *fim;
}Lista;

int push(Lista *l, int valor){
    Bloco *temp = (Bloco*)malloc(sizeof(Bloco));
    if(!temp) return 0;
    temp->valor = valor;
    temp->prox = NULL;
    temp->ant = NULL;
    if(l->inicio == NULL) l->inicio = l->fim = temp;
    else{
        l->inicio->prox = temp;
        temp->ant = l->inicio;
        l->inicio = temp;
    }
    return 1;
}

int pop(Lista *l){
    if(!(l->inicio)) return 0;
    Bloco *temp;
    temp = l->inicio;
    l->inicio = l->inicio->ant;
    temp->prox = temp->ant = NULL;
    l->inicio->prox = NULL;
    free(temp);
    return 1;
}

void printar_pilha(Lista *l){
    Bloco *perc;
    for(perc = l->fim; perc != NULL; perc = perc->prox) printf("%d ", perc->valor);
}

int remocao(Lista *l){
    Bloco *temp;
    temp = l->inicio;
    if(!(l->inicio)) return 0;
    if(l->inicio != l->fim){
    l->inicio = l->inicio->ant;
    l->inicio->prox = NULL;
    temp->prox = temp->ant = NULL;
    free(temp);
    return remocao(l);
    }
    else{
    l->inicio = l->fim = NULL;
    free(temp);
    }
    return 1;
}

int main(){
    Lista pilha;
    pilha.fim = pilha.inicio = NULL;
    push(&pilha, 5);
    push(&pilha, 3);
    push(&pilha, 2);
    push(&pilha, 8);
    push(&pilha, 9);
    push(&pilha, 1);
    push(&pilha, 7);
    push(&pilha, 6);
    push(&pilha, 4);
    printar_pilha(&pilha);
    remocao(&pilha);
    printar_pilha(&pilha);
}
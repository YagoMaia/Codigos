// Um TAD Deque é uma estrutura de dados similar a uma fila que suporta inserção e remoção tanto em seu final, quanto em seu início.Também chamado de fila com dois finais

#include <stdio.h>
#include <stdlib.h>

typedef struct bloco{
    int valor;
    struct bloco *prox;
    struct bloco *ant;
}Bloco;

typedef struct lista{
    Bloco *inicio;
    Bloco *fim;
    int tamanho;
}Lista;

int addFirst(Lista *l, int valor){
    Bloco *temp = (Bloco*)malloc(sizeof(Bloco));
    if(!temp) return 0;
    temp->valor = valor;
    temp->prox = temp->ant = NULL;
    if(l->inicio == NULL) l->inicio = l->fim = temp;
    l->inicio->prox = temp;
    temp->ant = l->inicio;
    l->inicio = temp;
    l->tamanho++;
    return 1;
}   

int addLast(Lista *l, int valor){
    Bloco *temp = (Bloco*)malloc(sizeof(Bloco));
    if(!temp) return 0;
    temp->valor = valor;
    temp->prox = temp->ant = NULL;
    if(!(l->fim)) l->fim = l->inicio = temp;
    l->fim->ant = temp;
    temp->prox = l->fim;
    l->fim = temp;
    l->tamanho++;
    return 1;
}

int removeFirst(Lista *l){
    Bloco *temp = l->inicio;
    if(!(l->inicio)) return 0;
    if(l->inicio == l->fim) l->fim = l->inicio = NULL;
    else{
        l->inicio = l->inicio->ant;
        l->inicio->prox = NULL;
    }
    temp->ant = temp->prox = NULL;
    free(temp);
    l->tamanho--;
    return 1;
}

int removeLast(Lista *l){
    Bloco *temp = l->fim;
    if(!(l->fim)) return 0;
    if(l->fim == l->inicio) l->fim = l->inicio = NULL;
    else{
        l->fim = l->fim->prox;
        l->fim->ant = NULL;
    }
    temp->prox = temp->ant = NULL;
    free(temp);
    l->tamanho--;
    return 1;
}

int getFirst(Lista *l){
    return l->inicio->valor;
}

int getlast(Lista *l){
    return l->fim->valor;
}

int size(Lista *l){
    return l->tamanho;
}

void printar_pilha(Lista *l){
    Bloco *perc;
    for(perc = l->fim; perc != NULL; perc = perc->prox) printf("%d ", perc->valor);
    printf("\n");
}

int main(){
    Lista deque;
    deque.fim = deque.inicio = NULL;
    deque.tamanho = 0;
    addFirst(&deque, 10);
    addFirst(&deque, 3);
    addLast(&deque, 7);
    addLast(&deque, 4);
    printar_pilha(&deque);
    removeFirst(&deque);
    removeLast(&deque);
    printar_pilha(&deque);
    printf("%d\n", getFirst(&deque));
    printf("%d\n", getlast(&deque));
    printf("%d\n", size(&deque));
    return 0;
}
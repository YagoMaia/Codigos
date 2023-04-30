#include <stdio.h>
#include <stdlib.h>

//Estrutura basica do bloco;
typedef struct bloco{
    int valor;
    struct bloco *prox;
    struct bloco *ant;
}Bloco;

//Estrutura basica da lista
typedef struct{
    Bloco *inicio;
    Bloco *fim;
    int tamanho;
}Lista;

int inserir(Lista *l, int valor){
    Bloco *temp = (Bloco*)malloc(sizeof(Bloco));
    if(temp==NULL) return 0;
    temp->valor = valor;
    temp->prox = temp->ant = NULL;
    if(l->inicio == NULL)l->inicio = l->fim = temp;
    else{
        l->fim->prox = temp;
        temp->ant = l->fim;
        l->fim = temp;
    }
    l->tamanho++;
    return 1;
}

void printar_lista(Lista *l){
    Bloco *perc = l->inicio;
    for(;perc != NULL; perc = perc->prox) printf("%d ",perc->valor);
    printf("\n");
}

int troca(Lista *l, int pos1, int pos2){
    Bloco *perc1, *perc2;
    Bloco *aux1, *aux2;
    perc1 = perc2 = l->inicio;
    if(pos1 > l->tamanho-1 && pos2 > l->tamanho-1){
        for(int i=1; i < pos1 && perc1 != NULL; i++, perc1 = perc1->prox);
        for(int j=1; j < pos2 && perc2 != NULL; j++, perc2 = perc2->prox);
        aux1 = perc1->prox;
        aux2 = perc2->prox;
        //
        perc1->prox = aux1->prox;
        perc2->prox = aux2->prox;
        //
        perc1->prox->ant = aux2;
        aux2->prox = perc1->prox;
        aux2->ant = perc1;
        perc1->prox = aux2;
        //
        perc2->prox->ant = aux1;
        aux1->ant = perc2;
        aux1->prox = perc2->prox;
        perc2->prox = aux1;
        return 1;
    }
    return 0;
}

int main(){
    Lista l;
    l.tamanho = 0;
    l.inicio = l.fim = NULL;
    inserir(&l, 5);
    inserir(&l, 4);
    inserir(&l, 2);
    inserir(&l, 8);
    inserir(&l, 9);
    inserir(&l, 10);
    printar_lista(&l);
    troca(&l, 1, 4);
    printar_lista(&l);
}


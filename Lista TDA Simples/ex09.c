// Construa uma pilha que seja capaz de armazenar um valor que pode ser de três tipos: int, float ou string.Escreva uma função principal que faça testes de inserção, remoção e impressão de conteúdo a cada operação(inserção ou remoção) .Defina também a struct Bloco.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef enum{
    INT,
    FLOAT,
    STRING
}Tipo;

typedef union dado
{
    int inteiro;
    float flutuante;
    char *string;
}Dados;

typedef struct bloco{
    Dados dado;
    struct bloco *prox;
    Tipo tipo;
}Bloco;

typedef struct lista{
    Bloco *inicio;
    Bloco *fim;
}Lista;

int insercao(Lista *l, Tipo tipo, int i, float f, char *s){
    Bloco *temp = (Bloco*)malloc(sizeof(Bloco));
    if(temp==NULL) return 0;
    temp->prox = NULL;
    temp->tipo = tipo;
    if(tipo == INT)temp->dado.inteiro = i;
    if(tipo == FLOAT) temp->dado.flutuante = f;
    if(tipo == STRING) temp->dado.string = s;
    if(l->inicio == NULL)l->inicio = l->fim = temp;
    else{
        l->inicio->prox = temp;
        l->inicio = temp;
    }
    return 1;
}

void imprimir(Lista *l){
    Bloco *perc = l->fim;
    for(; perc != NULL; perc = perc->prox){
        if(perc->tipo == INT) printf("%d", perc->dado.inteiro);
        if(perc->tipo == FLOAT) printf("%f", perc->dado.flutuante);
        if(perc->tipo == STRING)puts(perc->dado.string);
        printf("\n");
    }
}

int main(){
    Lista l;
    l.inicio = l.fim = NULL;
    insercao(&l, INT, 1, 1, "teste");
    insercao(&l, FLOAT, 1, 5.0, "teste");
    insercao(&l, STRING, 1, 5.0, "string");
    imprimir(&l);

}
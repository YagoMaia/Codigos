#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    TERMO,
    PARENTESE
} TipoBloco;

typedef struct
{
    int coef;
    int exp;
} Termo;

typedef struct bloco
{
    TipoBloco tipo;
    union
    {
        Termo termo;
        char parentese;
    }dado;
    struct bloco *prox;
    struct bloco *ant;
} Bloco;

typedef struct{
    Bloco *inicio;
    Bloco *fim;
}Lista;

int inserir (Lista *l, TipoBloco tipo, int coef, int exp){
    Bloco *temp = (Bloco*)malloc(sizeof(Bloco)), *perc;
    if(temp == NULL) return 0;
    if(tipo == TERMO){
        temp->prox = temp->ant = NULL;
        temp->tipo = TERMO;
        temp->dado.termo.coef = coef;
        temp->dado.termo.exp = exp;
    }
    if(l->inicio == NULL) l->inicio = l->fim = temp;
    else{
        for (perc = l->inicio; perc->prox != NULL; perc = perc->prox);
        perc->prox = temp;
        temp->ant = perc;
        if(temp->prox == NULL) l->fim = temp;
    }
    return 1;
}

int inserir2(Lista *l, TipoBloco tipo, int coef, int exp)
{
    Bloco *temp = (Bloco *)malloc(sizeof(Bloco)), *perc;
    if (temp == NULL)
        return 0;
    if (tipo == TERMO)
    {
        temp->prox = temp->ant = NULL;
        temp->tipo = TERMO;
        temp->dado.termo.coef = coef;
        temp->dado.termo.exp = exp;
    }
    if (l->inicio == NULL)
        l->inicio = l->fim = temp;
    else
    {
        for (perc = l->inicio; perc->prox != NULL; perc = perc->prox)
            ;
        perc->prox = temp;
        temp->ant = perc;
        if (temp->prox == NULL)
            l->fim = temp;
    }
    return 1;
}

int main(){
    Lista l;
    l.inicio = l.fim = NULL;
    inserir(&l, TERMO,10, 3);
    inserir(&l, TERMO, 3, 4);
    inserir(&l, TERMO, 2, 6);
}
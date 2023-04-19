#include <stdio.h>
#include <stdlib.h>

typedef union{
    int x;
    char y;
}Meutipo; //Junta todos os tipos e reserva na memória o tipo com maior espaço ocupado

typedef enum{
    OPERADOR,
    OPERANDO,
    PARENTESE,
}Tipo;


typedef struct bloco{
    Tipo tipo;
    union{
        char operador;
        char parentese;
        int operando;
    }dado;
    struct bloco *prox;
}Bloco;

int main(){
    Bloco b1, b2, b3, b4, b5;
    Bloco *perc;
    b1.tipo = PARENTESE;
    b1.dado.parentese = '(';
    b1.prox = &b2;

    b2.tipo = OPERANDO;
    b2.dado.operando = 1;
    b2.prox = &b3;

    b3.tipo = OPERADOR;
    b3.dado.operador = '+';
    b3.prox = &b4;

    b4.tipo = OPERANDO;
    b4.dado.operando = 2;
    b4.prox = &b5;

    b5.tipo = PARENTESE;
    b5.dado.parentese = ')';
    b5.prox = NULL;

    for(perc=&b1; perc!=NULL; perc = perc->prox){
        switch (perc->tipo)
        {
            case OPERADOR:
                printf("%c ", perc->dado.operador);
                break;
            case PARENTESE:
                printf("%c ", perc->dado.parentese);
                break;
            case OPERANDO:
                printf("%d ", perc->dado.operando);
                break;
        }
    }
    return 0;
}
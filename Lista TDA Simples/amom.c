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
    };
    struct bloco *proximo;
    struct bloco *anterior;
} Bloco;

typedef struct lista
{
    Bloco *inicio;
    Bloco *fim;
} Lista;

int insere_bloco(TipoBloco verificador, char p, Lista *t, int coeficiente, int expoente)
{
    Bloco *temp = (Bloco *)malloc(sizeof(Bloco));
    if (temp == NULL)return 0;
    if (verificador == TERMO)
    {
        temp->termo.coef = coeficiente;
        temp->termo.exp = expoente;
        t->inicio = temp;
        return 1;
    }
    else if (verificador == PARENTESE)
    {
        temp->parentese = p;
        t = temp;
    }
    return 1;
}

int main()
{
    Lista teste;
    teste.fim = teste.inicio = NULL;
    insere_bloco(1, '(', &teste, NULL, NULL);
    insere_bloco(0, NULL, &teste, 2, 2);
    insere_bloco(0, NULL, &teste, 5, 1);
    insere_bloco(1, ')', &teste, NULL, NULL);
    return 0;
}
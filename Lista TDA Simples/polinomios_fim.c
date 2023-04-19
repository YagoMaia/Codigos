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

typedef union
{
    Termo termo;
    char parentese;
} Dado;

typedef struct bloco
{
    TipoBloco tipo;
    Dado dado;
    char sinal;
    struct bloco *prox, *ant;
} Bloco;

typedef struct
{
    Bloco *inicio;
    Bloco *fim;
} Lista;

int inserir(Lista *l, TipoBloco tipo, int coef, int exp, char parentese)
{
    Bloco *temp = (Bloco *)malloc(sizeof(Bloco)), *perc, *limite;
    if (temp == NULL)
        return 0;
    temp->prox = temp->ant = NULL;
    temp->tipo = tipo;
    if (tipo == TERMO)
    {
        temp->dado.termo.coef = coef;
        if (coef > 0)
            temp->sinal = '+';
        temp->sinal = '-';
        temp->dado.termo.exp = exp;
        if (l->inicio == NULL)
            l->inicio = l->fim = temp;
        else
        {
            for (limite = l->fim; limite->ant != NULL; limite = limite->ant)
            {
                if (limite->tipo == PARENTESE)
                    break;
            }
            for (perc = limite; perc->prox != NULL && perc->prox->dado.termo.exp > exp; perc = perc->prox)
                ;
            temp->ant = perc;
            temp->prox = perc->prox;
            perc->prox = temp;
            if (temp->prox != NULL)
                temp->prox->ant = temp;
        }
    }
    else
    {
        temp->dado.parentese = parentese;
        if (l->inicio == NULL)
            l->inicio = l->fim = temp;
        else
        {
            for (limite = l->fim; limite->ant != NULL; limite = limite->ant)
            {
                if (limite->tipo == PARENTESE)
                    break;
            }
            for (perc = limite; perc->prox != NULL; perc = perc->prox)
                ;
            perc->prox = temp;
            temp->ant = perc;
        }
    }
    if (temp->prox == NULL)
        l->fim = temp;
    return 1;
}

int remocao(Lista *l, int posicao)
{
    Bloco *perc = l->inicio;
    for (int i = 0; i < posicao; i++)
    {
        while (perc->prox->tipo == TERMO)
        {
            perc = perc->prox;
        }
    }
    perc->prox->ant = perc->ant;
    perc->ant->prox = perc->prox;
    perc->prox = perc->ant = NULL;
    free(perc);
    return 1;
}

int exlusao(Lista *l)
{
    Bloco *temp, *perc = l->inicio;
    if (perc == NULL)
        return 0;
    for (; perc->prox != NULL; perc = temp)
    {
        temp = perc->prox;
        temp->ant = NULL;
        perc->prox = perc->ant = NULL;
        free(perc);
    }
    free(l->fim);
    l->inicio = l->fim = NULL;
    return 1;
}

void imprimir(Lista *l)
{
    Bloco *perc = l->inicio;
    for (; perc != NULL; perc = perc->prox)
    {
        if (perc->tipo == PARENTESE)
        {
            printf("%c ", perc->dado.parentese);
        }
        else
        {
            if (perc->dado.termo.exp > 0)
            {
                printf("%dx^%d ", perc->dado.termo.coef, perc->dado.termo.exp);
                if (perc->prox->tipo == TERMO)
                {
                    if (perc->prox->dado.termo.coef > 0)
                        printf("+ ");
                }
            }
            else
            {
                printf("%d ", perc->dado.termo.coef);
            }
        }
    }
    printf("\n");
}

int main()
{
    Lista l;
    l.inicio = l.fim = NULL;
    inserir(&l, PARENTESE, 1, 2, '(');
    inserir(&l, TERMO, -10, 2, ' ');
    inserir(&l, TERMO, 5, 1, ' ');
    inserir(&l, TERMO, 2, 3, ' ');
    inserir(&l, TERMO, 7, 0, ' ');
    inserir(&l, PARENTESE, 1, 2, ')');
    inserir(&l, PARENTESE, 1, 2, '+');
    inserir(&l, PARENTESE, 1, 2, '(');
    inserir(&l, TERMO, 10, 2, ' ');
    inserir(&l, TERMO, 3, 3, ' ');
    inserir(&l, TERMO, 1, 1, ' ');
    inserir(&l, PARENTESE, 1, 2, ')');
    inserir(&l, PARENTESE, 1, 2, '+');
    inserir(&l, PARENTESE, 1, 2, '(');
    inserir(&l, TERMO, 1, 1, ' ');
    inserir(&l, PARENTESE, 1, 2, ')');
    imprimir(&l);
    remocao(&l, 2);
    imprimir(&l);
    return 0;
}
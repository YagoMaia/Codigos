#include <stdlib.h>
#include <stdio.h>

typedef struct bloco
{
    int valor;
    struct bloco *proximo;
} Bloco;

int insere_ordenado(Bloco **primeiro_bloco, int valor)
{
    Bloco *ponteiro_temporario, *percorrer;
    ponteiro_temporario = (Bloco *)malloc(sizeof(Bloco));
    ponteiro_temporario->proximo = NULL;
    ponteiro_temporario->valor = valor;
    if (*primeiro_bloco == NULL)
    {
        if (ponteiro_temporario == NULL)
            return 0;
        *primeiro_bloco = ponteiro_temporario;
    }
    else
    {
        if (ponteiro_temporario->valor < (*primeiro_bloco)->valor)
        {
            ponteiro_temporario->proximo = *primeiro_bloco;
            *primeiro_bloco = ponteiro_temporario;
        }
        else
        {
            percorrer = *primeiro_bloco;
            while (percorrer->proximo != NULL && ponteiro_temporario->valor > percorrer->proximo->valor)
            {
                percorrer = percorrer->proximo;
            }
            ponteiro_temporario->proximo = percorrer->proximo;
            percorrer->proximo = ponteiro_temporario;
        }
    }
    return 1;
}

int tamanho(Bloco *primeiro_bloco)
{
    int contador;
    if (primeiro_bloco == NULL)
        return 0;
    for (contador = 1; primeiro_bloco->proximo != NULL; primeiro_bloco = primeiro_bloco->proximo, contador++)
        ;
    return contador;
}

int remover(Bloco **primeiro_bloco, int posicao)
{
    Bloco *percorrer = *primeiro_bloco, *ponteiro_temporario;
    if (*primeiro_bloco == NULL)
        return 0;
    else
    {
        if (posicao > tamanho(percorrer))
            return 0;
        for (int contador = 0; contador < posicao - 1; contador++, percorrer = percorrer->proximo)
            ;
        ponteiro_temporario = percorrer->proximo;
        percorrer->proximo = percorrer->proximo->proximo;
        ponteiro_temporario->proximo = NULL;
        free(ponteiro_temporario);
    }
    return 1;
}

int main()
{
    Bloco *primeiro_bloco = NULL;
    insere_ordenado(&primeiro_bloco, 2);
    insere_ordenado(&primeiro_bloco, 1);
    insere_ordenado(&primeiro_bloco, 8);
    insere_ordenado(&primeiro_bloco, 6);
    remover(&primeiro_bloco, 5);
}
#include <stdio.h>
#include <stdlib.h>

typedef struct bloco
{                       // bloco com b minúsculo é um nome temporario
    struct bloco *prox; // criada uma struct auto-referencial, um ponteiro que recebe endereços do tipo do próprio bloco em que se encontra
    int valor;
} Bloco; // nome da struct

int add_bloco_ordenado(Bloco **head, int value)
{                       //**head é o endereço do ponteiro *head da função main que está sendo passado como parâmetro. Logo é um ponteiro que aponta pra outro ponteiro
    Bloco *temp, *perc; // valor temporario e valor que percorrerá os blocos
    temp = (Bloco *)malloc(sizeof(Bloco));
    temp->valor = value; // o valor de temp será comparado

    if (*head == NULL)
    { // verificação para saber se já existe algum bloco na função

        if (temp != NULL)
        {
            temp->prox = NULL;
            *head = temp; // só adiciona
        }
        else
        {
            return 0;
        }
    }

    else if ((*head)->valor > temp->valor)
    {                       // se o valor inserido for menor do que o valor no ínicio
        temp->prox = *head; // o próximo de temp recebe o que antes era o primeiro
        *head = temp;       // o primeiro recebe temp, sendo seu valor anterior agora o segundo valor
    }

    else
    {                 // encaixar na ordem
        perc = *head; // percorrer a partir do primeiro bloco

        while (perc->prox != NULL && perc->prox->valor < temp->valor)
        {                      // enquanto o próximo for nulo e o valor do próximo bloco de perc for menor que o valor de temp
            perc = perc->prox; // perc avança até o ponto descrito acima
        }

        temp->prox = perc->prox;   // o proximo valor depois de temp recebe o proximo valor depois de perc
        perc->prox = temp;         // o proximo valor de perc vai ser alterado, porque se percorresemos até o valor de perc não poderíamos mexer no bloco anterior para fazer seu prox apontar para o lugar certo
        perc->prox->valor = value; // recebe o valor, agora encaixado na posição correta
    }
    return 1;
}

int remove_bloco(Bloco **head, int posicao)
{
    Bloco *perc, *temp;
    temp = (Bloco *)malloc(sizeof(Bloco));

    if (temp == NULL || *head == NULL)
    {
        return 0;
    }

    else
    {
        perc = *head;
        int count = 0;

        while (perc->prox != NULL && count + 1 != posicao)
        {
            perc = perc->prox; // percorre
            count++;
        }

        temp = perc->prox;             // temp vai receber o valor a ser deletado
        perc->prox = perc->prox->prox; // o proximo valor de perc vai receber o que seria o 2° proximo, e o primeiro próximo antigo é apagado;
        return 1;
    }

    return 1;
}

int main(void)
{
    Bloco *head;
    head = NULL;
    add_bloco_ordenado(&head, 2);
    add_bloco_ordenado(&head, 3);
    add_bloco_ordenado(&head, 5);
    add_bloco_ordenado(&head, 4);
    add_bloco_ordenado(&head, 1);
    add_bloco_ordenado(&head, 7);
    remove_bloco(&head, 1); // remove o segundo valor (no caso seria o 2)
    return 0;
}
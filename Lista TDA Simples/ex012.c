// Você foi contratado pela Google para refazer o Orkut. A sua primeira tarefa é implementar uma estrutura de dados para representar as relações de amizade dentro do Orkut. Ou seja, para cada pessoa cadastrada você tem que armazenar a sua lista de amigos. Considere que cada pessoa no Orkut tem um identificador único que é um número inteiro.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

typedef struct
{
    int dia;
    int mes;
    int ano;
} Nasc;

typedef struct amigos{
    int id_amigo;
    struct amigos *prox;
}Amigos;


typedef struct user
{
    int id;
    char *nome;
    char *sobrenome;
    Nasc nascimento;
    Amigos *lista;
    struct user *prox;
} User;

typedef struct
{
    User *inicio;
    User *fim;
} Orkut;

int cadastro(Orkut *cadastro, int ident, char *n, char *s, int d, int m, int a)
{
    User *temp = (User *)malloc(sizeof(User)), *perc = cadastro->inicio;
    if (temp == NULL)return 0;
    temp->id = ident;
    temp->nome = n;
    temp->sobrenome = s;
    temp->nascimento.dia = d;
    temp->nascimento.mes = m;
    temp->nascimento.ano = a;
    temp->prox = NULL;
    temp->lista = NULL;
    if (cadastro->inicio == NULL)cadastro->inicio = cadastro->fim = temp;
    else
    {
        for (; perc->prox != NULL; perc = perc->prox);
        perc->prox = temp;
    }
    if (temp->prox == NULL)cadastro->fim = temp;
    return 1;
}

void print_user(Orkut *pessoa)
{
    User *perc = pessoa->inicio;
    for (; perc != NULL; perc = perc->prox)
    {
        printf("Id: %d\n", perc->id);
        puts(perc->nome);
        puts(perc->sobrenome);
        printf("Dia: %d\n", perc->nascimento.dia);
        printf("Mes: %d\n", perc->nascimento.mes);
        printf("Ano: %d\n", perc->nascimento.ano);
    }
}

void relaciona(int amigo1, int amigo2, Orkut *pOrkut)
{
    Amigos *p1, *p2;
    User *perc = pOrkut->inicio;
    p1 = (Amigos *)malloc(sizeof(Amigos));
    p1->id_amigo = amigo1;
    p1->prox = NULL;
    p2 = (Amigos *)malloc(sizeof(Amigos));
    p2->id_amigo = amigo2;
    p2->prox = NULL;
    for(;perc!=NULL && perc->id != amigo1; perc=perc->prox);
    if (perc->lista == NULL) perc->lista = p2;
    else{
        for(;perc->lista->prox != NULL; perc = perc->lista->prox);
        perc->lista->prox = p2;
    }
    for(perc=pOrkut->inicio;perc!=NULL && perc->id != amigo2; perc=perc->prox);
    if (perc->lista == NULL)perc->lista = p1;
    else{
        for(;perc->lista->prox != NULL; perc = perc->lista->prox);
        perc->lista->prox = p1;
    }
    return 1;
}

int main()
{
    Orkut orkut;
    orkut.inicio = orkut.fim = NULL;
    cadastro(&orkut, 10, "yago", "henrique", 2, 11, 2003);
    cadastro(&orkut, 5, "Alex", "Versiane", 5, 10, 2003);
    cadastro(&orkut, 7, "Wayne", "Lucas", 25, 2, 2000);
    print_user(&orkut);
    relaciona(10, 5, &orkut);
    relaciona(5, 7, &orkut);
    return 1;
}
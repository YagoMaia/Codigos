#include <stdlib.h>
#include <stdio.h>

typedef struct bloco
{
	int valor;
	struct bloco *proximo;
} Bloco;

Bloco *aloca_bloco(int quantidade)
{
	Bloco *percorrer = (Bloco *)malloc(sizeof(Bloco)), *primeiro_bloco;
	int i;
	primeiro_bloco = percorrer;
	for (i = 1; i < quantidade; i++)
	{
		percorrer->proximo = (Bloco *)malloc(sizeof(Bloco));
		percorrer = percorrer->proximo;
	}
	percorrer->proximo = NULL;
	return primeiro_bloco;
}

void preencher_bloco(Bloco *primeiro_bloco, int posicao, int valor)
{
	Bloco *perc;
	int cont;
	perc = primeiro_bloco;
	for (cont = 0; cont < posicao; cont++)
	{
		perc = perc->proximo;
	}
	perc->valor = valor;
}

void imprimir(Bloco *primeiro_bloco)
{
	for (; primeiro_bloco != NULL; primeiro_bloco = primeiro_bloco->proximo)
	{
		printf("%d ", primeiro_bloco->valor);
	}
}

void add_bloco(Bloco *primeiro_bloco, int valor)
{
	while (primeiro_bloco->proximo != NULL)
	{
		primeiro_bloco = primeiro_bloco->proximo;
	}
	primeiro_bloco->proximo = aloca_bloco(1);
	primeiro_bloco = primeiro_bloco->proximo;
	primeiro_bloco->valor = valor;
}

int insere_ordenado(Bloco **primeiro_bloco, int valor)
{
	Bloco *ponteiro_temporario, *percorrer;
	ponteiro_temporario = (Bloco *)malloc(sizeof(Bloco));
	ponteiro_temporario->proximo = NULL;
	ponteiro_temporario->valor = valor;
	if (*primeiro_bloco == NULL)
	{
		if (ponteiro_temporario == NULL)
		{
			return 0;
		}
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
	for (contador = 1; primeiro_bloco->proximo != NULL; primeiro_bloco = primeiro_bloco->proximo, contador++)
		;
	return contador;
}

int busca(Bloco *primeiro_bloco, int valor)
{
	for (; primeiro_bloco != NULL; primeiro_bloco = primeiro_bloco->proximo)
	{
		if (primeiro_bloco->valor == valor)
			return 1;
	}
	return 0;
}

int remover(Bloco **primeiro_bloco, int posicao){
	Bloco *percorrer = *primeiro_bloco, *ponteiro_temporario;
	if(*primeiro_bloco == NULL){
		return 0;
	}
	else{
		if(posicao > tamanho(percorrer)) return 0;
		for(int contador = 0; contador < posicao - 1; contador++, percorrer = percorrer->proximo);
		ponteiro_temporario = percorrer->proximo;
		percorrer->proximo = percorrer->proximo->proximo;
		ponteiro_temporario->proximo = NULL;
		free(ponteiro_temporario);
	}
	return 1;
}

int main(){
	Bloco *primeiro_bloco = NULL;
	insere_ordenado(&primeiro_bloco, 2);
	insere_ordenado(&primeiro_bloco, 1);
	insere_ordenado(&primeiro_bloco, 8);
	insere_ordenado(&primeiro_bloco, 6);
	remover(&primeiro_bloco, 5);
	printf("%d\n", tamanho(primeiro_bloco));
	printf("%d\n", busca(primeiro_bloco, 0));
}
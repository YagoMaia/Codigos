#include<stdio.h>
#include<stdlib.h>

typedef struct bloco {
    int chave;
    struct bloco *esq;
    struct bloco *dir;
}No;

int insere(No **raiz, int dado) {
    No *temp;
    if(*raiz == NULL){
        temp = (No*)malloc(sizeof(No));
        if(temp == NULL) return 0;
        temp->esq = temp->dir = NULL;
        temp->chave = dado;
        *raiz = temp;
    }
    else if(dado < (*raiz)->chave) return insere(&(*raiz)->esq, dado);
    else if(dado > (*raiz)->chave) return insere(&(*raiz)->dir, dado);
    return 1;
}

void imprimeEmOrdem(No *perc){
    if(perc != NULL){
        imprimeEmOrdem(perc->esq);
        printf("%d ", perc->chave);
        imprimeEmOrdem(perc->dir);
    }
}

int altura(No *r, int nivel){
  int esq = -1, dir = -1;
  if(r->dir == r->esq) return nivel;
  if(r->esq != NULL) esq = altura(r->esq, nivel + 1);
  if(r->dir != NULL) dir = altura(r->dir, nivel + 1);
  if(esq > dir) return esq;
  return dir;
}

int NivelValor(No *r, int nivel, int valor){
  if(r->chave == valor) return nivel;
  if(valor < r->chave) return NivelValor(r->esq, nivel + 1, valor);
  if(valor > r->chave) return NivelValor(r->dir, nivel + 1, valor);
  return -1;
  
}

int PrintarNivel(No *r, int nivel, int x){
  if(r == NULL) return 0;
  if(x == nivel) printf("%d\n",r->chave);
  PrintarNivel(r->esq, nivel, x+1);
  PrintarNivel(r->dir, nivel, x+1);
  return 1;
}

int PrintarNiveis(No *r, int x){
  if(r == NULL) return 0;
  for(int i =0; i < x; i++)printf(" ");
  printf("%d\n", r->chave);
  PrintarNiveis(r->esq, x+1);
  PrintarNiveis(r->dir, x+1);
  return 1;
}

int RetAltura(No *r){
  return altura(r, 0);
}

int Retnivel(No *r, int valor){
  return NivelValor(r, 0, valor);
}

int main(){
    No *raiz = NULL;

    insere(&raiz, 5);
    insere(&raiz, 2);
    insere(&raiz, 3);
    insere(&raiz, 7);
    insere(&raiz, 4);
    insere(&raiz, 1);
    insere(&raiz, 8);
    insere(&raiz, 6);
    PrintarNivel(raiz, 2, 0);
    printf("\n");
    PrintarNiveis(raiz, 0);
    return 0;
}
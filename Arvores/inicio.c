#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *dir;
    struct no *esq;
    int altura;
    int fb;
}No;

int altura(No ** pont_arv){
    if((*pont_arv)->esq == (*pont_arv)->dir){ // Quer dizer que os dois ponteiros são nulos, logo é um folha;
        return 0;
    }
    else{
        int esq = altura(&(*pont_arv)->esq);
        int dir = altura(&(*pont_arv)->dir);
        if(esq > dir) return esq+1;
        else return dir+1;
    }
}

int insere(No **pont_arv, int valor){ //Mexendo com ponteiro de ponteiros
    No *temp;
    if(*pont_arv == NULL){ //Analisa se o ponteiro, do tipo nó, que ele está apotando é nulo.
        temp = (No*)malloc(sizeof(No));
        if(!temp) return 0;
        temp->valor = valor;
        temp->altura = temp->fb = 0;
        temp->dir = temp->esq = NULL; 
        *pont_arv = temp; //O ponteiro que estava com NULL passa a apontar pra temp
    }
    else{
        if(valor < (*pont_arv)->valor) return insere(&(*pont_arv)->esq, valor); //Chamada recursiva passando o ponteiro esquerdo do ponteiro que estava sendo referenciado antes
        else if(valor > (*pont_arv)->altura) return insere(&(*pont_arv)->dir, valor); //Chamada recursiva passando o ponteiro direito do ponteiro que estava sendo referenciado antes
        else return -1; // Caso seja um número já existente na arvore;
    }
    (*pont_arv)->altura = altura(pont_arv);
    return 1;
}

void EmOrder(No **arv){
    if(*arv != NULL){
    EmOrder(&(*arv)->esq);
    printf("%d ", (*arv)->valor);
    EmOrder(&(*arv)->dir);
    }
}

void PreOrder(No **arv){
    if(*arv != NULL){
        printf("%d ", (*arv)->valor);
        PreOrder(&(*arv)->esq);
        PreOrder(&(*arv)->dir);
    }
}

void PosOrder(No **arv){
    if(*arv != NULL){
        PreOrder(&(*arv)->esq);
        PreOrder(&(*arv)->dir);
        printf("%d ", (*arv)->valor);
    }
}

int main(){
    No *arvore = NULL;
    insere(&arvore, 10);
    insere(&arvore, 7);
    insere(&arvore, 1);
    insere(&arvore, 4);
    insere(&arvore, 8);
    insere(&arvore, 3);
    insere(&arvore, 5);
    insere(&arvore, 2);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *dir;
    struct no *esq;
    int altura;
    int fb;
}No;

int AlturaNo(No *r){
    if(r == NULL) return -1;
    return r->altura;
}

int maior(int dir, int esq){
    if(dir > esq) return dir + 1;
    else return esq + 1;
}


int insere(No **raiz, int valor){ //Mexendo com ponteiro de ponteiros
    No *temp;
    if(*raiz == NULL){ //Analisa se o ponteiro, do tipo nó, que ele está apotando é nulo.
        temp = (No*)malloc(sizeof(No));
        if(!temp) return 0;
        temp->valor = valor;
        temp->fb = 0;
        temp->dir = temp->esq = NULL; 
        *raiz = temp; //O ponteiro que estava com NULL passa a apontar pra temp
    }
    else{
        if(valor < (*raiz)->valor){ 
            if(insere(&(*raiz)->esq, valor)){
                (*raiz)->fb = AlturaNo((*raiz)->dir) - AlturaNo((*raiz)->esq);
            }
        } // Chamada recursiva passando o ponteiro esquerdo do ponteiro que estava sendo referenciado antes
        else if(valor > (*raiz)->altura){ 
            if(insere(&(*raiz)->dir, valor)){
                (*raiz)->fb = AlturaNo((*raiz)->dir) - AlturaNo((*raiz)->esq);
            }
        } // Chamada recursiva passando o ponteiro direito do ponteiro que estava sendo referenciado antes
    }
    (*raiz)->altura = maior(AlturaNo((*raiz)->esq), AlturaNo((*raiz)->dir));
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

No **ProcuraMenor(No **raiz){
    if((*raiz)->esq == NULL) return raiz;
    else ProcuraMenor(&(*raiz)->esq);
}

int MenorValor(No **raiz)
{
    return (*raiz)->valor;
}

No ** ProcuraMaior(No **raiz){
    if((*raiz)->dir == NULL) return raiz;
    else ProcuraMaior(&(*raiz)->dir);
}

int MaiorValor(No **raiz){
    return (*raiz)->valor;
}

void mostraHierarquia(No *r, int nivel){
    int n;
    if(r == NULL) return;
    for(n = 0; n < nivel ; n++) printf("\t");

    printf("%d\n",r->valor);
    if(r->esq != NULL)
    mostraHierarquia(r->esq, nivel + 1);
    if(r->dir != NULL)
    mostraHierarquia(r->dir,nivel+1);
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
    mostraHierarquia(arvore, 0);
    return 0;
}
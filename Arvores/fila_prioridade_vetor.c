#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

void troca(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void max_heap(int v[], int i, int tamanho){
    int e = (i*2) + 1;
    int d = (i*2) + 2;
    int maior = i;
    if(e<tamanho && v[e] > v[maior]) maior = e;
    if(d<tamanho && v[d] > v[maior]) maior = d;
    if(maior != i){
        troca(&v[i], &v[maior]);
        max_heap(v, maior, tamanho);
    }
}

void constroi_max_heap(int v[], int tamanho){
    for(int i = tamanho/2; i >= 0; i--) max_heap(v, i, tamanho);

}

void print_vetor(int v[], int tamanho){
    for(int i=0; i<tamanho; i++)printf("%d ",v[i]);
    printf("\n");
}

int inserir(int v[], int tamanho, int numero){
    int i = tamanho, pai;
    v[i] = numero;
    tamanho++;
    pai = (i-1)/2;
    while(v[pai] < v[i]){
        troca(&v[pai], &v[i]);
        i = pai;
        pai = (i-1)/2;
    }
    return tamanho;
}

int maximo(int v[]){
    return v[0];
}

int extrai_max(int v[], int tamanho){
    v[0] = v[tamanho - 1];
    tamanho--;
    constroi_max_heap(v, tamanho);
    return tamanho;
}

void incrementa(int v[], int tamanho, int i, int x, int k){
    int d = i*2 + 2;
    int e = i*2 + 1;
    if(v[i] == x) v[i]= k;
    else
    {
        incrementa(v, tamanho, e, x, k);
        incrementa(v, tamanho, d, x, k);
    }
}

int main(){
    int v[MAX] = {4, 1, 3, 8, 7, 2, 0};
    int tamanho = 7;
    print_vetor(v, tamanho);
    constroi_max_heap(v, tamanho);
    print_vetor(v, tamanho);
    tamanho = inserir(v,tamanho, 9 );
    print_vetor(v, tamanho);
    tamanho = extrai_max(v, tamanho);
    print_vetor(v, tamanho);
    incrementa(v, tamanho, 0, 1, 5);
    print_vetor(v, tamanho);
}
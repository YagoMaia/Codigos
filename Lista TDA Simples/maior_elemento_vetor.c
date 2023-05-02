#include <stdlib.h>
#include <stdio.h>

int maior_elemento(int v[], int pos, int tamanho){
    int maior = 0;
    if(tamanho == pos) return v[pos];
    if(v[pos] > maior_elemento(v, pos+1, tamanho)) maior = v[pos];
    else maior = maior_elemento(v, pos+1, tamanho);
    return maior;
}

int main(){
    int v[7] = {10, 5, 8, 15, 3, 9, 12};
    int tamanho = 7;
    printf("%d\n", tamanho);
    printf("%d\n", maior_elemento(v, 0, tamanho));
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maior(int tamanho, int v[]){
    int x;
    if(tamanho == 1) x = v[0];
    else{
        x = maior(tamanho - 1, v);
        if(v[tamanho - 1] > x) return v[tamanho - 1];
        else return x;
    }
}

int soma(int tamanho, int v[])
{
    int x, somat=0;
    if(tamanho == 1) x=v[0];
    else{
        x = soma(tamanho -1, v);
        return x + v[tamanho];
    }
    somat += x;
}

int main(){
    int v[9] = {0,0,0,1,2,3,4,5,6};
    printf("%d\n", maior(9, v));
    printf("Soma = %d", soma(9, v));
}
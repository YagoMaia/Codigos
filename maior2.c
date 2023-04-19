#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int maior(int n, int v[]){
    int valor;
    if(n == 1) valor = v[0];
    else{
        valor = maior(n-1, v);
        if(v[n-1] > valor) valor = v[n-1];
    }
    return valor;
}

int main(){
    int v[] = {0, 1, 2, 3, 10, 5, 6, 7, 8, 9};
    printf("%d\n", maior(10, v));
}
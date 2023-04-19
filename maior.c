#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int maior(int inicio, int fim, int v[]){
    int m, n, k, l, meio = (inicio + fim)/2;
    printf("Meio = %d\n", meio);
    printf("Inicio = %d, %d\n", inicio, v[inicio]);
    printf("fim = %d\n, %d\n", fim, v[fim]);
    if(fim - inicio <= 1 ){
        if(v[fim] > v[inicio]) return v[fim];
        else return v[inicio];
    }
    else{
        l = maior(inicio, meio, v);
        k = maior(meio + 1, fim, v);
        if(l > k) return l;
        else return k;
    }
}

int main(){
    int v[] = {0,1,2,3,4,5,6,7,8,9};
    int c = maior(0, 10, v);
    printf("%d", c);
}
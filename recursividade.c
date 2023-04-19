#include <stdio.h>
#include <stdlib.h>

//Menor problema de somar os elementos é o elemento na primeira posição

int soma(int tamanho, int v[]){
    int x;
    if(tamanho == 1){
        x = v[0];
        printf("v[0] = %d\n", v[0]);
        return x;
    }
    else{
        x = v[tamanho] + soma(tamanho-1, v);
        printf("v[%d] = %d\n", tamanho, v[tamanho]);
        return x;
    }
}

int main()
{
    int v[9] = {0, 0, 0, 1, 2, 3, 4, 5, 6};
    printf("Soma = %d", soma(8, v));
}
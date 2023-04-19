#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int soma(int inicio, int final, int v[]){
    int meio = (inicio + final)/2;
    if(final - inicio == 1){
        return v[meio] + v[inicio];
    }
    else{
        soma(inicio, meio, v);
        soma(meio+1, final, v);
    }

}

int main(){
    int v[8] = {1,2,3,4,5,6,7,8};
    int c = soma(0, 7, v);
    printf("%d", c);
}
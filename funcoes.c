#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cabecalho(void){
    printf("=================Calculadora==============\n");
    printf("[1] - Somar\n");
    printf("[2] - Subtrair\n");
    printf("[3] - Multiplicar\n");
    printf("[4] - Dividir\n");
    printf("[5] - Sair\n");
    printf("==========================================\n");
    printf("Qual opção você deseja? ");
}

float soma(float a, float b)
{
    return a+b;
}

float subtracao(float a, float b)
{
    return a - b;
}

float divisao(float a, float b)
{
    return a/b;
}

float multiplicacao(float a, float b)
{
    return a * b;
}

int main(){
    int opcao;
    float x, y;
    do{
        cabecalho();
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                printf("digite um número: ");
                scanf("%f", &x);
                printf("digite outro número: ");
                scanf("%f", &y);
                printf("O valor da soma é: %.2f\n", soma(x, y));
                break;
            case 2:
                printf("digite um número: ");
                scanf("%f", &x);
                printf("digite outro número: ");
                scanf("%f", &y);
                printf("O valor da subtracao é: %.2f\n", subtracao(x, y));
                break;
            case 3:
                printf("digite um número: ");
                scanf("%f", &x);
                printf("digite outro número: ");
                scanf("%f", &y);
                printf("O valor da multiplicacao é: %.2f\n", multiplicacao(x, y));
                break;
            case 4:
                printf("digite um número: ");
                scanf("%f", &x);
                printf("digite outro número: ");
                scanf("%f", &y);
                printf("O valor da divisao é: %.2f\n", divisao(x, y));
                break;
        }
    }while (opcao != 5);
     return 0;
}
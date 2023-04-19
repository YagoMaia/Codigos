#include <stdio.h>
#include <stdlib.h>
struct Bloco
{
    int x;
    struct Bloco *ant, *prox, *cima, *baixo;
};
typedef struct Bloco No;
void dificil(No *****d)
{
    (*****d).prox = (****d);
    (****d)->prox->ant->x = 2;
    (****d)->ant->x = 3;
}
void confusa(No ****c)
{
    (***c)->x = 4;
    (****c).prox = NULL;
    (****c).ant = (No *)malloc(sizeof(No));
    (***c)->ant->x = (***c)->x;
    (***c)->ant->prox = (***c);
    dificil(&c);
}
void pirapirou(No **pc, No **pb, int valor)
{
    *pc = (No *)malloc(sizeof(No) * valor);
    *pb = (*pc) + 3;
    (*pc)->x = (*pb)->x = 1;
    ((*pc) + 1)->x = ((*pb) - 1)->x = 2;
    ((*pb) - 1)->x++;
    (*pb)->x += 3;
}
void misterio(No ***m, int valor)
{
    **m = (No *)malloc(sizeof(No));
    (**m)->x = valor;
    (***m).ant = NULL;
    (***m).prox = NULL;
    (***m).cima = NULL;
    (***m).baixo = NULL;
    confusa(&m);
    pirapirou(&(***m).cima, &(***m).baixo, (**m)->x);
}
int main(void)
{
    int i;
    No *pont, **pont2;
    pont2 = &pont;
    *pont2 = NULL;
    misterio(&pont2, 6);
    printf("%d\n", pont->ant->prox->ant->prox->prox->x);
    printf("%d\n", pont->ant->x);
    for (i = 0; i < 4; i++)
        printf("%d\n", ((*pont).cima + i)->x);
    getchar();
    return 0;
}
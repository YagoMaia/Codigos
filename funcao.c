#include <stdio.h>
#include <stdlib.h>
void c(){
    printf("c() inicia\n");
    printf("c() retorna\n");
}
void b(){
    printf("b() inicia\n");
    c();
    printf("b() retorna\n");
}
void a(){
    printf("a() inicia\n");
    b();
    c();
    printf("a() retorna\n");
}
void conta(void)
{
    static int i = 0;
    printf("% d\n", i++);
}
int main(void)
{
    conta();
    conta();
    conta();
}
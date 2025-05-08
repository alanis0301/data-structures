#include <stdio.h>

void troca_valores(int *x, int *y){
    int aux;
    aux = *x;
    *x = *y;
    *y = aux;
}

int main(){
    int a, b;

    printf("Insira o valor de a e b\n");
    scanf("%d %d", &a, &b);

    troca_valores(&a, &b);

    printf("Os valores trocados ficam\nA = %d\nB = %d", a, b);

}
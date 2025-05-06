
//1. Cria uma estrutura e typedef da estrutura para manipular um 
//ponto 2D que tem as coordenadas x e y floats.
//2. Crie uma funçao que tenha como parametros dois ponteiros da
//estruturas do tipo Ponto 2D e retorne a distancia entre eles.
//3. Crie uma funçao que calcule o ponto médio de dois pontos 2D
//retornando um ponto 2D.
//4. Faça que a funçao anterior retorne um ponteiro com uma area
//alocada dinamicamente para a resposta da funçao.

#include <stdio.h>
#include <math.h>
#include <stdlib.h>


typedef struct Ponto{
    float x;
    float y;
}Ponto;

float distancia(Ponto *p1, Ponto *p2){
    float dx = pow((p2->x - p1->x), 2);
    float dy = pow((p2->y - p1->y), 2);

    float resultado = sqrt(dx + dy);
    return resultado;
}

Ponto ponto_medio(Ponto *p1, Ponto *p2){
    float mediaX = (p2->x + p1->x)/2;
    float mediaY = (p2->y + p1->y)/2;

    Ponto p3;
    p3.x = mediaX;
    p3.y = mediaY;

    return p3;
}

Ponto* ponto_medio_pont(Ponto *p1, Ponto *p2){
    Ponto *ponto = (Ponto*)malloc(sizeof(Ponto));

    if(ponto != NULL){
        ponto->x = (p2->x + p1->x)/2;
        ponto->y = (p2->y + p1->y)/2;
    }

    return ponto;
}


int main()
{
    Ponto p1, p2;
    
    printf("Insira o valor de x e y do ponto 1");
    scanf("%f %f", &p1.x, &p1.y);
    printf("Insira o valor de x e y do ponto 2");
    scanf("%f %f", &p2.x, &p2.y);
    
    float resultado = distancia(&p1, &p2);
    Ponto p3 = ponto_medio(&p1, &p2);
    Ponto *p4 = ponto_medio_pont(&p1, &p2);


    printf("Distancia entre p1 e p2\n%.2f\n", resultado);
    printf("Valor do ponto medio\nX = %.2f\nY = %.2f\n", p3.x, p3.y);
    if(p4 != NULL){
        printf("Valor do ponto medio utilizando alocacao dinamica\nX = %.2f\nY = %.2f", p4->x, p4->y);
        free(p4);
    }
    return 0;
}
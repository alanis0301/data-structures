#include <stdio.h>

int soma_vetor(int *vetor, int tamanho){
    int soma = 0;
    int *fim = vetor + tamanho;

    while (vetor < fim) {
        soma += *vetor;
        vetor++;
    }

    return soma;
}

int main(){
    int quant;

    printf("Insira a quantidade de elementos do vetor: ");
    scanf("%d", &quant);
    
    int V[quant];

    for(int i = 0; i < quant; i++){
        printf("Insira o %dº elemento: ", i + 1);
        scanf("%d", &V[i]);
    }

    int resultado = soma_vetor(V, quant);

    printf("Soma dos valores do vetor = %d\n", resultado);

    return 0;
}

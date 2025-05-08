#include <stdio.h>
#include <stdlib.h>

int main(){

    int tam, *vetor;

    printf("Insira o tamanho do vetor de inteiros\n");
    scanf("%d", &tam);

    vetor = (int *) malloc(tam*sizeof(int));

    if (vetor == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    for(int i = 0; i < tam; i++){
        printf("Insira o %dº elemento: ", i + 1);
        scanf("%d", (vetor + i));
    }

    for(int i = 0; i < tam; i++){
        printf("%d ", *(vetor + i));
    }

    free(vetor);

    return 0;
}
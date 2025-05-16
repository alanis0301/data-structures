#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef unsigned char byte;

typedef struct No{
    byte *data;
    void *prox;
}No;

typedef struct Lista{
    int nElementos;
    int tamElemento;
    No *first;
    No *current;
    No *last;
}Lista;

void criar_lista(Lista *lista, int tamElemento); // Feito
void destruir_lista(Lista *lista);  // Feito
bool inserir_lista(Lista *lista, byte *data);   // Feito
bool remover_ultimo(Lista *lista); // Feito
int buscar_valor(Lista *lista, int valor);
void imprimir_lista(Lista *lista); // Feito


void criar_lista(Lista *lista, int tamElemento) {
    lista->nElementos = 0;
    lista->tamElemento = tamElemento;
    lista->first = NULL;
    lista->current = NULL;
    lista->last = NULL;
}

void destruir_lista(Lista *lista) {
    No *atual = lista->first;
    No *proximo;
    while (atual != NULL) {
        proximo = atual->prox;
        free(atual->data);
        free(atual);
        atual = proximo;
    }
    lista->nElementos = 0;
    lista->tamElemento = 0;
    lista->first = NULL;
    lista->current = NULL;
    lista->last = NULL;
}

bool inserir_lista(Lista *lista, byte *data) {
    No *item = malloc(sizeof(No));
    if (item == NULL) return false;

    item->data = malloc(lista->tamElemento);
    if (item->data == NULL) {
        free(item);
        return false;
    }

    memcpy(item->data, data, lista->tamElemento);
    item->prox = NULL;

    if (lista->nElementos == 0) {
        lista->first = item;
        lista->last = item;
    } else {
        lista->last->prox = item;
        lista->last = item;
    }

    lista->current = item;
    lista->nElementos++;
    return true;
}

bool remover_ultimo(Lista *lista) {
    if (lista->nElementos == 0) return false;

    No *item;

    if (lista->nElementos == 1) {
        item = lista->first;
        free(item->data);
        free(item);
        lista->first = NULL;
        lista->current = NULL;
        lista->last = NULL;
        lista->nElementos = 0;
        return true;
    }

    item = lista->first;
    while (item->prox != lista->last) {
        item = item->prox;
    }

    free(lista->last->data);
    free(lista->last);

    lista->last = item;
    lista->current = item;
    lista->last->prox = NULL;
    lista->nElementos--;

    return true;
}

void imprimir_lista(Lista *lista){
    No *item = lista->first;

    while(item != NULL){
        int valor;
        memcpy(&valor, item->data, sizeof(int));
        printf("%d ", valor);
        item = item->prox;
    }
    printf("\n");
}

int buscar_valor(Lista *lista, int valor){
    No *item = lista->first;
    int posicao = 0;

    while(item != NULL){
        int conteudo;
        memcpy(&conteudo, item->data, sizeof(int));
        if(conteudo == valor){
            printf("Valor presente na %dª posição da lista.\n", posicao);
            return posicao;
        }
        posicao++;
        item = item->prox;
    }

    printf("Valor não presente na lista.\n");
    return -1;
}


int main() {
    int valor, op;
    Lista lista;
    criar_lista(&lista, sizeof(int));

    do {
        printf("\nMENU\n");
        printf("0 - Encerrar programa\n");
        printf("1 - Inserir valor\n");
        printf("2 - Remover último\n");
        printf("3 - Buscar valor\n");
        printf("4 - Imprimir lista\n");
        printf("Opção: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                if (!inserir_lista(&lista, (byte *)&valor)) {
                    printf("Erro ao inserir valor.\n");
                }
                break;
            case 2:
                if (!remover_ultimo(&lista)) {
                    printf("Lista já está vazia.\n");
                } else {
                    printf("Ultimo elemento removido com sucesso.\n");
                }
                break;
            case 3:
            printf("Insira o valor a ser buscado.");
            scanf("%d", &valor);
            buscar_valor(&lista, valor);
            break;
            case 4:
            imprimir_lista(&lista);
            break;
            case 0:
                printf("Encerrando...\n");
                destruir_lista(&lista);
                break;
            default:
                printf("Opção inválida.\n");
        }

    } while (op != 0);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>


// Criação da lista vazia
ListaEncadeada* criarLista() {
    ListaEncadeada* lista = (ListaEncadeada*)malloc(sizeof(ListaEncadeada));
    lista->cabeca = NULL;
    lista->tamanho = 0;
    return lista;
}

// Verificar se a lista está vazia
int estaVazia(ListaEncadeada* lista) {
    return lista->tamanho == 0;
}

// Obter o tamanho da lista
int obterTamanho(ListaEncadeada* lista) {
    return lista->tamanho;
}

// Obter o valor do elemento de uma determinada posição
int obterElemento(ListaEncadeada* lista, int posicao) {
    if (posicao < 1 || posicao > lista->tamanho) {
        printf("Posição inválida!\n");
        return -1;
    }
    No* atual = lista->cabeca;
    for (int i = 1; i < posicao; i++) {
        atual = atual->proximo;
    }
    return atual->dado;
}

// Modificar o valor do elemento de uma determinada posição
void definirElemento(ListaEncadeada* lista, int posicao, int valor) {
    if (posicao < 1 || posicao > lista->tamanho) {
        printf("Posição inválida!\n");
        return;
    }
    No* atual = lista->cabeca;
    for (int i = 1; i < posicao; i++) {
        atual = atual->proximo;
    }
    atual->dado = valor;
}

// Inserir um elemento em uma determinada posição
void inserirElemento(ListaEncadeada* lista, int posicao, int valor) {
    if (posicao < 1 || posicao > lista->tamanho + 1) {
        printf("Posição inválida!\n");
        return;
    }
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->dado = valor;
    if (posicao == 1) {
        novoNo->proximo = lista->cabeca;
        lista->cabeca = novoNo;
    } else {
        No* atual = lista->cabeca;
        for (int i = 1; i < posicao - 1; i++) {
            atual = atual->proximo;
        }
        novoNo->proximo = atual->proximo;
        atual->proximo = novoNo;
    }
    lista->tamanho++;
}

// Retirar um elemento de uma determinada posição
void removerElemento(ListaEncadeada* lista, int posicao) {
    if (posicao < 1 || posicao > lista->tamanho) {
        printf("Posição inválida!\n");
        return;
    }
    No* temp;
    if (posicao == 1) {
        temp = lista->cabeca;
        lista->cabeca = lista->cabeca->proximo;
    } else {
        No* atual = lista->cabeca;
        for (int i = 1; i < posicao - 1; i++) {
            atual = atual->proximo;
        }
        temp = atual->proximo;
        atual->proximo = temp->proximo;
    }
    free(temp);
    lista->tamanho--;
}

// Imprimir os elementos de toda a lista
void imprimirLista(ListaEncadeada* lista) {
    No* atual = lista->cabeca;
    while (atual != NULL) {
        printf("%d -> ", atual->dado);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

// Liberação da memória alocada pela lista
void liberarLista(ListaEncadeada* lista) {
    No* atual = lista->cabeca;
    No* proximoNo;
    while (atual != NULL) {
        proximoNo = atual->proximo;
        free(atual);
        atual = proximoNo;
    }
    free(lista);
}

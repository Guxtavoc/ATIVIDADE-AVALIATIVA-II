#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"
no* criarNo(char nomePresente[], char Loja[], char nomePessoa[], char dataCompra[], float valor) {
    no* novo = (no*)malloc(sizeof(no));
    strcpy(novo->nomePresente, nomePresente);
    strcpy(novo->Loja, Loja);
    strcpy(novo->nomePessoa, nomePessoa);
    strcpy(novo->dataCompra, dataCompra);
    novo->valor = valor;
    novo->proximo = NULL;
    return novo;
}
void inserir(no **lista){
    char nomePresente[20], Loja[20], nomePessoa[20], dataCompra[10];
    float valor;
    // Coleta de dados dentro da função
    printf("Digite o nome do presente: ");
    scanf("%s", nomePresente);
    printf("Digite o nome da loja: ");
    scanf("%s", Loja);
    printf("Digite o nome da pessoa: ");
    scanf("%s", nomePessoa);
    printf("Digite a data da compra (DD/MM/AAAA): ");
    scanf("%s", dataCompra);
    printf("Digite o valor: ");
    scanf("%f", &valor);
    no* novo = criarNo(nomePresente, Loja, nomePessoa, dataCompra, valor);
    // Inserir no início se a lista estiver vazia ou se o nomePresente do novo for menor
    if (*lista == NULL || strcmp(novo->nomePresente, (*lista)->nomePresente) < 0) {
        novo->proximo = *lista;
        *lista = novo;
        return;
    }
}
void excluir(no **lista, char nomePresente[]) {
    if (*lista == NULL) {
        printf("Lista vazia!\n");
        return;
    }
    no* temp = *lista;
    if (strcmp((*lista)->nomePresente, nomePresente) == 0) {
        *lista = (*lista)->proximo;
        free(temp);
        return;
    }
    no* prev = NULL;
    while (temp != NULL && strcmp(temp->nomePresente, nomePresente) != 0) {
        prev = temp;
        temp = temp->proximo;
    }
    if (temp == NULL) {
        printf("Presente não encontrado!\n");
        return;
    }
    prev->proximo = temp->proximo;
    free(temp);
}
void imprimir(no *lista) {
    if (lista == NULL) {
        printf("Lista vazia!\n");
        return;
    }
    no* atual = lista;
    while (atual != NULL) {
        printf("Presente: %s, Loja: %s, Pessoa: %s, Data: %s, Valor: %.2f\n",
               atual->nomePresente, atual->Loja, atual->nomePessoa, atual->dataCompra, atual->valor);
        atual = atual->proximo;
    }
}
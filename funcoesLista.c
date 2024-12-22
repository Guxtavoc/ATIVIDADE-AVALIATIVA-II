#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoesLista.h"
no* criarNo(char nomePresente[],char Loja[],float valor){
    no* novo=(no*)malloc(sizeof(no));
    strcpy(novo->nomePresente,nomePresente);
    strcpy(novo->Loja,Loja);
    novo->valor=valor;
    novo->proximo=NULL;
    novo->status=0;
    return novo;
}
void inserir(no **lista){
    char nomePresente[20],Loja[20];
    float valor;
    printf("Digite o nome do presente: ");
    scanf("%s",nomePresente);
    printf("Digite o nome da loja: ");
    scanf("%s",Loja);
    printf("Digite o valor: ");
    scanf("%f",&valor);
    no* novo=criarNo(nomePresente,Loja,valor);
    if (*lista==NULL||strcmp(novo->nomePresente,(*lista)->nomePresente)<0){
        novo->proximo=*lista;
        *lista=novo;
        return;
    }
    no* atual=*lista;
    while(atual->proximo!=NULL&&strcmp(atual->proximo->nomePresente,novo->nomePresente)<0){
        atual=atual->proximo;
    }
    novo->proximo=atual->proximo;
    atual->proximo=novo;
}
void excluir(no **lista){
    char nomePresente[20];
    if (*lista==NULL) {
        printf("Lista vazia!\n");
        return;
    }
    printf("Digite o nome do presente para Retirar da lista: ");
    scanf("%s",nomePresente);
    no* temp=*lista;
    if (strcmp((*lista)->nomePresente,nomePresente)==0){
        *lista=(*lista)->proximo;
        free(temp);
        return;
    }
    no* prev=NULL;
    while(temp!=NULL&&strcmp(temp->nomePresente,nomePresente)!=0){
        prev=temp;
        temp=temp->proximo;
    }
    if(temp==NULL){
        printf("Presente nao encontrado!\n");
        return;
    }
    prev->proximo=temp->proximo;
    free(temp);
}
void exlcuirLista(no **lista){
    while(*lista!=NULL) {
        no* temp=*lista;
        *lista=(*lista)->proximo;
        free(temp);
    }
}
void imprimir(no *lista){
    if (lista==NULL) {
        printf("Lista vazia!\n");
        return;
    }
    no *atual=lista;
    while(atual!=NULL){
        if(atual->status==1){
            printf("Presente: %s, Loja: %s, Presenteador: %s, Data da entrega: %s, Valor: R$%.2f\n",atual->nomePresente,atual->Loja,atual->nomePessoa,atual->dataCompra,atual->valor);
        }else{
            printf("Presente: %s, Loja: %s, Valor: R$%.2f\n",atual->nomePresente,atual->Loja,atual->valor);
        }
        atual=atual->proximo;
    }
}
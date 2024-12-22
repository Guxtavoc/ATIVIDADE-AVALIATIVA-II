#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"
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
void exlcuirLista(no **lista){
    while(*lista!=NULL) {
        no* temp=*lista;
        *lista=(*lista)->proximo;
        free(temp);
    }
}
void atribuirPessoa(no *lista){
    if(lista==NULL){
        printf("Lista vazia!\n");
        return;
    }
    char nomePresente[20];
    printf("Digite o nome do presente que deseja atualizar: ");
    scanf("%s",nomePresente);
    no *atual=lista;
    while(atual!=NULL&&strcmp(atual->nomePresente,nomePresente)!= 0){
        atual=atual->proximo;
    }
    if(atual==NULL){
        printf("Presente '%s' nao encontrado na lista!\n",nomePresente);
        return;
    }
    if(atual->status==1){
        printf("Opa, parece que alguem ja comprou esse presente!\n");
        printf("Caso tenha sido um erro, recomenda-se que exclua essa entrada!\n");
        return;
    }
    printf("Digite o nome da pessoa que presenteou: ");
    scanf("%s",atual->nomePessoa);
    printf("Digite a data do presente (DD/MM/AAAA): ");
    scanf("%10s",atual->dataCompra);
    atual->status=1;
}
void editarPresente(no *lista){
    char nomePresente[20];
    int op,v;
    float valor;
    if(lista==NULL){
        printf("Lista vazia!\n");
        return;
    }
    printf("Digite o nome do presente que deseja atualizar: ");
    scanf("%s",nomePresente);
    no *atual=lista;
    while(atual!=NULL&&strcmp(atual->nomePresente,nomePresente)!= 0){
        atual=atual->proximo;
    }
    if(atual==NULL){
        printf("Presente '%s' nao encontrado na lista!\n",nomePresente);
        return;
    }
    printf("Presente: %s, Loja: %s, Valor: R$%.2f\n",atual->nomePresente,atual->Loja,atual->valor);
    do{
        v=0;
        printf("1 - Nome do presente\n2 - Loja\n3 - Valor\n0 - Retornar ao menu Principal\n");
        printf("Digite o que deseja editar: ");
        scanf("%d",&op);
        switch (op){
        case 1:
            printf("Digite o novo nome para o presente: ");
            scanf("%s",nomePresente);
            while(v==0){
                if(strcmp(atual->nomePresente,nomePresente)==0){
                    printf("nome selecionado igual ao anterior, tente novamente\n");
                    scanf("%s",nomePresente);
                }else{
                    strcpy(atual->nomePresente,nomePresente);
                    v=1;
                }
            }
            break;
        case 2:
            printf("Digite a nova loja onde encontrar o presente: ");
            scanf("%s",nomePresente);
            while(v==0){
                if(strcmp(atual->Loja,nomePresente)==0){
                    printf("Loja selecionada igual a anterior, tente novamente\n");
                    scanf("%s",nomePresente);
                }else{
                    strcpy(atual->Loja,nomePresente);
                    v=1;
                }
            }
            break;
        case 3:
            printf("Digite o novo valor para o presente: ");
            scanf("%f",&valor);
            while(v==0){
                if(valor==atual->valor){
                    printf("Valor selecionado igual ao anterior, tente novamente\n");
                    scanf("%f",&valor);
                }else{
                    atual->valor=valor;
                    v=1;
                }
            }
            break;
        case 0:
        printf("Retornando ao menu principal...\n");
            break;        
        default:
            printf("Opcao invalida! Tente novamente\n");
            break;
        }
    }while (op!=0);
}
void buscar(no *lista){
    if(lista==NULL){
        printf("Lista vazia!\n");
        return;
    }
    char nomePresente[20];
    printf("Digite o nome do presente que deseja atualizar: ");
    scanf("%s",nomePresente);
    no *atual=lista;
    while(atual!=NULL&&strcmp(atual->nomePresente,nomePresente)!= 0){
        atual=atual->proximo;
    }
    if(atual==NULL){
        printf("Presente '%s' nao encontrado na lista!\n",nomePresente);
        return;
    }
    if(atual->status==1){
            printf("Presente: %s, Loja: %s, Presenteador: %s, Data da entrega: %s, Valor: R$%.2f\n",atual->nomePresente,atual->Loja,atual->nomePessoa,atual->dataCompra,atual->valor);
        }else{
            printf("Presente: %s, Loja: %s, Valor: R$%.2f\n",atual->nomePresente,atual->Loja,atual->valor);
        }
}
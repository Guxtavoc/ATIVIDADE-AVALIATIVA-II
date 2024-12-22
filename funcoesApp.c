#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoesLista.h"
#include "funcoesApp.h"
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
    printf("Digite o nome do presente que deseja buscar: ");
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
void listarData(no *lista){
    if(lista==NULL){
        printf("Lista vazia!\n");
        return;
    }
    char dataLimite[10];
    printf("Digite a data limite (DD/MM/AAAA): ");
    scanf("%10s",dataLimite);
    printf("Listando presentes ganhos ate a data %s:\n",dataLimite);
    int encontrou=0;
    no *atual=lista;
    while(atual!=NULL){
        if(strcmp(atual->dataCompra,dataLimite)<=0&&atual->status==1){
            if(atual->status==1){
                printf("Presente: %s, Loja: %s, Presenteador: %s, Data da entrega: %s, Valor: R$%.2f\n",atual->nomePresente,atual->Loja,atual->nomePessoa,atual->dataCompra,atual->valor);
            }else{
                printf("Presente: %s, Loja: %s, Valor: R$%.2f\n",atual->nomePresente,atual->Loja,atual->valor);
            }
            encontrou=1;
        }
        atual=atual->proximo;
    }
    if(encontrou==0)
        printf("Nenhum presente foi ganho ate a data %s.\n",dataLimite);
}
void listarStatus(no *lista){
    if (lista==NULL) {
        printf("Lista vazia!\n");
        return;
    }
    no *atual=lista;
    while(atual!=NULL){
        if(atual->status==0)
            printf("Presente: %s, Loja: %s, Valor: R$%.2f\n",atual->nomePresente,atual->Loja,atual->valor);
        atual=atual->proximo;
    }
}
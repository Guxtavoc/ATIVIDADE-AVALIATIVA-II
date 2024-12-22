#include <stdio.h>
#include "funcoes.h"
void menuEdicao(no *lista){
    int op;
    do{
        printf("1 - Para editar dados do presente\n2 - Para adicionar um presenteador\n0 - Retornar ao menu principal\n");
        printf("digite a opcao que deseja: ");
        scanf("%d",&op);
        switch(op){
        case 1:
            editarPresente(lista);
            break;
        case 2:
            atribuirPessoa(lista);
            break;
        case 0:
            printf("Retornando ao menu princial...\n");     
            break;
        default:
            printf("Opcao invalida! Por favor tente novamente\n");
            break;
        }
    }while(op!=0);
        
    
}
void menu(no **lista){
    int op;
    char nomePresente[20];
    do{
        printf("1 - Inserir presentes na lista\n2 - Retirar presentes da lista\n3 - Opcoes de listagem\n");
        printf("4 - Editar dados/status de um presente\n5 - Buscar presente\n0 - Encerrar Aplicacao\n");
        printf("Digite a opcao que deseja: ");
        scanf("%d",&op);
        switch (op){
        case 1:
            inserir(lista);
            break;
        case 2:
                printf("Digite o nome do presente para Retirar da lista: ");
                scanf("%s", nomePresente);
                excluir(lista, nomePresente);
            break;
        case 3:
            imprimir(*lista);
            break;
        case 4:
            menuEdicao(*lista);
            break;
        case 5:
            break;
        case 0:
            printf("Encerrando aplicacao...\n");
            break;      
        default:
            printf("Opcao invalida! Tente Novamente...\n");
            break;
        }
    }while(op!=0);
}
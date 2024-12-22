#include <stdio.h>
#include "funcoesLista.h"
#include "funcoesApp.h"
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
void menuListagem(no *lista){
    int op;
    do{
        printf("1 - Para listar presentes ate determinada data\n2 - Para listar presentes nao ganhos\n3 - Listar todos os presentes\n0 - Retornar ao menu principal\n");
        printf("digite a opcao que deseja: ");
        scanf("%d",&op);
        switch(op){
        case 1:
            listarData(lista);
            break;
        case 2:
            listarStatus(lista);
            break;
        case 3:
            imprimir(lista);
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
            excluir(lista);
            break;
        case 3:
            menuListagem(*lista);
            break;
        case 4:
            menuEdicao(*lista);
            break;
        case 5:
        buscar(*lista);
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
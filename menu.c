#include <stdio.h>
#include "funcoes.h"

void menu(){
    int op;
    do{
        printf("1 - Inserir presentes na lista\n2 - Retirar presentes da lista\n3 - Opcoes de listagem\n");
        printf("4 - Editar dados de um presente\n5 - Buscar presente\n0 - Encerrar Aplicacao\n");
        scanf("%d",&op);
        switch (op){
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
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
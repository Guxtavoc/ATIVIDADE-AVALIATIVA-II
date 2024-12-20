#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
int main(){
    printf("Bem vind@, ao sistema de gerenciamento presentes!\n");
    no *lista=NULL;
    menu(&lista);
    exlcuirLista(&lista);
    return 0;
}
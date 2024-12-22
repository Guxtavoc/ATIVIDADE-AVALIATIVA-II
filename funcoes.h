typedef struct modulo{
    char nomePresente[20],Loja[20],nomePessoa[20],dataCompra[10];
    float valor;
    int status;
    struct modulo *proximo;
}no;
no *criarNo(char nomePresente[], char Loja[], float valor);
void inserir(no **lista);
void excluir(no **lista,char nomePresente[]);
void imprimir(no *lista);
void exlcuirLista(no **lista);
void imprimirDebug(no *lista);//Função de debug, excluir assim que possivel!!!
void atribuirPessoa(no *lista);
void editarPresente(no *lista);
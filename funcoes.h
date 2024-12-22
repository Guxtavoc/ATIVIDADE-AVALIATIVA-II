typedef struct modulo{
    char nomePresente[20],Loja[20],nomePessoa[20],dataCompra[10];
    float valor;
    int status;
    struct modulo *proximo;
}no;
no *criarNo(char nomePresente[], char Loja[], float valor);//Função da lista
void inserir(no **lista);//Função da lista
void excluir(no **lista);//Função da lista
void exlcuirLista(no **lista);//Função da lista
void atribuirPessoa(no *lista);//Função da aplicação
void editarPresente(no *lista);//Função da aplicação
void buscar(no *lista);//Função da aplicação
void listarData(no *lista);//Função da aplicação
void listarStatus(no *lista);//Função da aplicação
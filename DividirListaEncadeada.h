typedef struct celula Cell;
typedef struct lista ListaEncadeada;

Cell* criar_nova_celula(int num);
ListaEncadeada* criar_nova_lista_encadeada();
int verifica_se_lista_vazia(ListaEncadeada *a);
int verifica_se_item_existe_na_lista(ListaEncadeada *a, int num);
int inserir_novo_item_no_inicio_da_lista(ListaEncadeada *a, int num);
int inserir_novo_item_no_final_da_lista(ListaEncadeada *a, int num);
int remover_item_da_lista(ListaEncadeada *a, int num);
void imprimir_conteudo_da_lista(ListaEncadeada *a);
int liberar_lista(ListaEncadeada *a);
int tamanho_da_lista(ListaEncadeada *a);
void teste_imprimir_lista(ListaEncadeada *a);
int remover_item_do_inicio_da_lista(ListaEncadeada *a);
ListaEncadeada* dividir_lista(ListaEncadeada *a);

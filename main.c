#include <stdio.h>
#include <stdlib.h>
#include "DividirListaEncadeada.h"

int main()
{
    int i=0;
    ListaEncadeada *teste, *testeB;

    teste = criar_nova_lista_encadeada();

    while(1){
        scanf("%d", &i);
        if(i==-1){
            break;
        }
        else{
            inserir_novo_item_no_final_da_lista(teste, i);
        }
    }

    testeB = dividir_lista(teste);

    imprimir_conteudo_da_lista(testeB);
    printf("\n");
    imprimir_conteudo_da_lista(teste);

    liberar_lista(teste);
    liberar_lista(testeB);

    return 0;
}

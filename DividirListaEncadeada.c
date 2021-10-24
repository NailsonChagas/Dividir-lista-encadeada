#include <stdio.h>
#include <stdlib.h>
#include "DividirListaEncadeada.h"

struct celula{
    int item;
    Cell *next;
};

struct lista{
    Cell *head;
};

Cell* criar_nova_celula(int num){
    Cell *a;

    a = (Cell*) malloc(sizeof(Cell));

    a->item = num;
    a->next = NULL;

    return a;
}

ListaEncadeada* criar_nova_lista_encadeada(){
    ListaEncadeada *a;

    a = (ListaEncadeada*) malloc(sizeof(ListaEncadeada));

    a->head = NULL;

    return a;
}

int verifica_se_lista_vazia(ListaEncadeada *a){
    if(a == NULL){
        return -1;
    }
    else if(a->head ==  NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int verifica_se_item_existe_na_lista(ListaEncadeada *a, int num){
    Cell *aux;

    if(verifica_se_lista_vazia(a)!=1 && verifica_se_lista_vazia(a)!=-1){
        aux = a->head;

        while(aux!=NULL){
            if(aux->item == num){
                return 1;
            }
            aux = aux->next;
        }
    }
    return 0;
}

int inserir_novo_item_no_inicio_da_lista(ListaEncadeada *a, int num){
    Cell *nova;

    if(a!=NULL){
        nova = criar_nova_celula(num);

        nova->next = a->head;
        a->head = nova;

        return 1;
    }
    return 0;
}

int inserir_novo_item_no_final_da_lista(ListaEncadeada *a, int num){
    Cell *aux, *nova;

    if(a!=NULL){
        if(verifica_se_lista_vazia(a)==1){
            inserir_novo_item_no_inicio_da_lista(a, num);
            return 1;
        }
        else{
            aux = a->head;

            while(aux->next!=NULL){
                aux = aux->next;
            }

            nova = criar_nova_celula(num);
            aux->next = nova;

            return 1;
        }
    }
    return 0;
}

int remover_item_da_lista(ListaEncadeada *a, int num){
    Cell *auxA, *auxB;

    if(verifica_se_lista_vazia(a)!=1 && verifica_se_lista_vazia(a)!=-1){
        auxA = a->head;

        if(auxA->item == num){
            a->head = a->head->next;
        }
        else{
            auxB = auxA;

            while(auxA!=NULL && auxA->item!=num){
                auxB = auxA;
                auxA = auxA->next;
            }
            if(auxA!=NULL){
                auxB->next = auxA->next;
                free(auxA);
                return 1;
            }
        }
    }
    return 0;
}

void imprimir_conteudo_da_lista(ListaEncadeada *a){
    Cell *aux;

    if(a!=NULL && verifica_se_lista_vazia(a)!=1){
        aux = a->head;

        while(aux!=NULL){
            printf("%d ", aux->item);
            aux = aux->next;
        }
    }
}

int liberar_lista(ListaEncadeada *a){
    Cell *aux;

    if(a!=NULL){
        if(verifica_se_lista_vazia(a)==1){
            free(a);
            return 1;
        }
        else{
            aux = a->head;
            while(aux!=NULL){
                a->head = aux->next;

                free(aux);

                aux = a->head;
            }
            free(a);
            return 1;
        }
    }
    return 0;
}

int tamanho_da_lista(ListaEncadeada *a){
    int cont = 0;
    Cell *aux;

    if(verifica_se_lista_vazia(a)!=1){
        if(verifica_se_lista_vazia(a)==1){
            return cont;
        }
        else{
            aux = a->head;
            while(aux!=NULL){
                cont += 1;

                aux = aux->next;
            }
            return cont;
        }
    }
    return -1; //erro
}

void teste_imprimir_lista(ListaEncadeada *a){
    Cell *aux;
    int i = 0;

    if(verifica_se_lista_vazia(a)!=1 && verifica_se_lista_vazia(a)!=-1){
        aux = a->head;

        while(aux != NULL){
            printf("Elemento[%d]: Endereco: %d / Conteudo: %d\n", i, aux->next, aux->item);

            aux = aux->next;
            i += 1;
        }
    }
}

int remover_item_do_inicio_da_lista(ListaEncadeada *a){
    Cell *aux;

    if(verifica_se_lista_vazia(a)!=1 && verifica_se_lista_vazia(a)!=-1){
        aux = a->head;
        a->head = aux->next;

        free(aux);

        return 1;
    }
    return 0;
}

ListaEncadeada* dividir_lista(ListaEncadeada *a){
    Cell *aux;
    int tam = tamanho_da_lista(a)/2, cont = 0;
    ListaEncadeada *lista;

    if(a!=NULL && verifica_se_lista_vazia(a)!=1){
        aux = a->head;

        lista = criar_nova_lista_encadeada();

        if(tamanho_da_lista(a)%2 == 0){
            while(cont < tam){
                inserir_novo_item_no_final_da_lista(lista, aux->item);
                remover_item_do_inicio_da_lista(a);

                aux = a->head;
                cont += 1;
            }
        }
        else{
            while(cont <(tam+1)){
                inserir_novo_item_no_final_da_lista(lista, aux->item);
                remover_item_do_inicio_da_lista(a);

                aux = a->head;
                cont += 1;
            }
        }
    }
    return lista;
}


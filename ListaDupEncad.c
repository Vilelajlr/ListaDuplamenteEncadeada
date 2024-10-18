#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaDupEncad.h"

// Função para inicializar a lista
void inicializar_lista(Lista* lista) {
    lista->head = NULL;
    lista->tail = NULL;
}

// Função para criar um novo nó de ingresso
Ingresso* criar_ingresso(int numero_assento,  char* filme) {
    Ingresso* novo_ingresso = (Ingresso*)malloc(sizeof(Ingresso));
    novo_ingresso->numero_assento = numero_assento;
    strcpy(novo_ingresso->filme, filme);
    novo_ingresso->prev = NULL;
    novo_ingresso->next = NULL;
    return novo_ingresso;
}

// Função para adicionar um ingresso ao final da lista
void adicionar_ingresso(Lista* lista, Ingresso* ingresso) {
    if (lista->head == NULL) {
        lista->head = ingresso;
        lista->tail = ingresso;
    } else {
        lista->tail->next = ingresso;
        ingresso->prev = lista->tail;
        lista->tail = ingresso;
    }
}

// Função para remover um ingresso da lista
void remover_ingresso(Lista* lista, Ingresso* ingresso) {
    if (ingresso == lista->head && ingresso == lista->tail) {
        lista->head = NULL;
        lista->tail = NULL;
    } else if (ingresso == lista->head) {
        lista->head = ingresso->next;
        lista->head->prev = NULL;
    } else if (ingresso == lista->tail) {
        lista->tail = ingresso->prev;
        lista->tail->next = NULL;
    } else {
        ingresso->prev->next = ingresso->next;
        ingresso->next->prev = ingresso->prev;
    }
    free(ingresso);
}

// Função para vender um ingresso
void vender_ingresso(Lista* disponiveis, Lista* vendidos,  char* filme) {
    int assento;
    printf("Escolha o número do assento (1 a 10): ");
    scanf("%d", &assento);

    // Procurar o ingresso disponível na lista
    Ingresso* temp = disponiveis->head;
    while (temp != NULL) {
        if (temp->numero_assento == assento && strcmp(temp->filme, filme) == 0) {
            // Remover da lista de disponíveis
            remover_ingresso(disponiveis, temp);
            // Adicionar à lista de vendidos
            adicionar_ingresso(vendidos, criar_ingresso(assento, filme));
            printf("Ingresso vendido com sucesso!\n");
            return;
        }
        temp = temp->next;
    }
    printf("Assento não disponível.\n");
}

// Função para cancelar um ingresso
void cancelar_ingresso(Lista* disponiveis, Lista* vendidos,  char* filme) {
    int assento;
    printf("Insira o número do assento para cancelar: ");
    scanf("%d", &assento);

    // Procurar o ingresso vendido na lista
    Ingresso* temp = vendidos->head;
    while (temp != NULL) {
        if (temp->numero_assento == assento && strcmp(temp->filme, filme) == 0) {
            // Remover da lista de vendidos
            remover_ingresso(vendidos, temp);
            // Adicionar de volta à lista de disponíveis
            adicionar_ingresso(disponiveis, criar_ingresso(assento, filme));
            printf("Ingresso cancelado com sucesso!\n");
            return;
        }
        temp = temp->next;
    }
    printf("Ingresso não encontrado.\n");
}

// Função para listar ingressos disponíveis
void listar_ingressos_disponiveis(Lista* disponiveis,  char* filme) {
    printf("Ingressos disponíveis para o filme %s:\n", filme);
    Ingresso* temp = disponiveis->head;
    while (temp != NULL) {
        if (strcmp(temp->filme, filme) == 0) {
            printf("Assento: %d\n", temp->numero_assento);
        }
        temp = temp->next;
    }
}

// Função para exibir ingressos vendidos
void exibir_ingressos_vendidos(Lista* vendidos) {
    printf("Ingressos vendidos em ordem de compra:\n");
    Ingresso* temp = vendidos->head;
    while (temp != NULL) {
        printf("Filme: %s, Assento: %d\n", temp->filme, temp->numero_assento);
        temp = temp->next;
    }
}

void exibir_todos_os_ingressos(Lista* disponiveis){
    Ingresso* temp = disponiveis->head;
    while (temp != NULL) {
        printf("Filme: %s, Assento: %d\n", temp->filme, temp->numero_assento);
        temp = temp->next;
    }
}

void exibir_filmes_disponiveis(Lista* disponiveis){
    Ingresso* temp = disponiveis->head;
    while (temp != NULL) {
        printf("Filme: %s\n", temp->filme);
        temp = temp->next;
    }
}


void exibir_lugares_disponiveis(Lista* disponiveis,  char* filme){
    Ingresso* temp = disponiveis->head;
    while (temp != NULL) {
        if (strcmp(temp->filme, filme) == 0) {
            printf("Filme: %s, Assento: %d\n", temp->filme, temp->numero_assento);
        }
        temp = temp->next;
    }
}

// Função para liberar a memória alocada para a lista
void libera_lista(Lista* lista){
    Ingresso* temp = lista->head;
    while (temp != NULL) {
        Ingresso* next = temp->next;
        free(temp);
        temp = next;
    }
    lista->head = NULL;
    lista->tail = NULL;
}





void exibirMenu(){
    printf("============ CINEMARK ============\n");
    printf("1 -> Vender ingresso.\n");
    printf("2 -> Cancelar ingresso.\n");
    printf("3 -> Listar ingressos disponiveis.\n");
    printf("4 -> Exibir ingressos vendidos.\n");
    printf("5 -> Sair.\n");
    printf("====================================\n");
}
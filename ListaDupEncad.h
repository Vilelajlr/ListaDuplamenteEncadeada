#ifndef INGRESSOS_H
#define INGRESSOS_H

// Definindo a estrutura para um ingresso
typedef struct Ingresso {
    int numero_assento;
    char filme[50];
    struct Ingresso* prev;
    struct Ingresso* next;
} Ingresso;


// Definindo a estrutura para a lista duplamente encadeada
typedef struct Lista {
    Ingresso* head;
    Ingresso* tail;
} Lista;

// Funções para gerenciar ingressos
void inicializar_lista(Lista* lista);
Ingresso* criar_ingresso(int numero_assento,  char* filme);
void adicionar_ingresso(Lista* lista, Ingresso* ingresso);
void remover_ingresso(Lista* lista, Ingresso* ingresso);
void vender_ingresso(Lista* disponiveis, Lista* vendidos,  char* filme);
void cancelar_ingresso(Lista* disponiveis, Lista* vendidos,  char* filme);
void listar_ingressos_disponiveis(Lista* disponiveis, char* filme);
void exibir_ingressos_vendidos(Lista* vendidos);
void exibirMenu();
void exibir_lugares_disponiveis(Lista* disponiveis,  char* filme);
void exibir_filmes_disponiveis(Lista* disponiveis);
void libera_lista(Lista* lista);


#endif

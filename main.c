#include <stdio.h>
#include <stdlib.h>
#include "ListaDupEncad.c"


int main(){


    Lista disponiveis;
    Lista vendidos;

    inicializar_lista(&disponiveis);
    inicializar_lista(&vendidos);


    
        adicionar_ingresso(&disponiveis, criar_ingresso(1, "Matrix"));
        adicionar_ingresso(&disponiveis, criar_ingresso(2, "Matrix"));
        adicionar_ingresso(&disponiveis, criar_ingresso(3, "Matrix"));
        adicionar_ingresso(&disponiveis, criar_ingresso(4, "Matrix"));
        adicionar_ingresso(&disponiveis, criar_ingresso(5, "Matrix"));
        adicionar_ingresso(&disponiveis, criar_ingresso(6, "Matrix"));
        adicionar_ingresso(&disponiveis, criar_ingresso(7, "Matrix"));
        adicionar_ingresso(&disponiveis, criar_ingresso(8, "Matrix"));
        adicionar_ingresso(&disponiveis, criar_ingresso(9, "Matrix"));
        adicionar_ingresso(&disponiveis, criar_ingresso(10, "Matrix"));


        adicionar_ingresso(&disponiveis, criar_ingresso(1, "Mad Max"));
        adicionar_ingresso(&disponiveis, criar_ingresso(2, "Mad Max"));
        adicionar_ingresso(&disponiveis, criar_ingresso(3, "Mad Max"));
        adicionar_ingresso(&disponiveis, criar_ingresso(4, "Mad Max"));
        adicionar_ingresso(&disponiveis, criar_ingresso(5, "Mad Max"));
        adicionar_ingresso(&disponiveis, criar_ingresso(6, "Mad Max"));
        adicionar_ingresso(&disponiveis, criar_ingresso(7, "Mad Max"));
        adicionar_ingresso(&disponiveis, criar_ingresso(8, "Mad Max"));
        adicionar_ingresso(&disponiveis, criar_ingresso(9, "Mad Max"));
        adicionar_ingresso(&disponiveis, criar_ingresso(10, "Mad Max"));


        adicionar_ingresso(&disponiveis, criar_ingresso(1, "Harry Potter"));
        adicionar_ingresso(&disponiveis, criar_ingresso(2, "Harry Potter"));
        adicionar_ingresso(&disponiveis, criar_ingresso(3, "Harry Potter"));
        adicionar_ingresso(&disponiveis, criar_ingresso(4, "Harry Potter"));
        adicionar_ingresso(&disponiveis, criar_ingresso(5, "Harry Potter"));


        adicionar_ingresso(&disponiveis, criar_ingresso(1, "Bob Esponja"));
        adicionar_ingresso(&disponiveis, criar_ingresso(2, "Bob Esponja"));
        adicionar_ingresso(&disponiveis, criar_ingresso(3, "Bob Esponja"));
        adicionar_ingresso(&disponiveis, criar_ingresso(4, "Bob Esponja"));
    




    int controle = 0;
   
   
   
   do{
    exibirMenu();

    scanf("%d", &controle);

    switch (controle)
    {
        case 1:
            printf("Filmes disponiveis!");
            exibir_filmes_disponiveis(&disponiveis);
            printf("Escolha um filme da lista.\n-> ");
            char filme[100];
            scanf("%s", filme);
            printf("Lugares disponiveis para o filme %s\n", filme);
            exibir_lugares_disponiveis(&disponiveis, filme);
            vender_ingresso(&disponiveis, &vendidos, filme);
            
            break;
        
        case 2:
            printf("Escolha o filme para cancelar.\n");
            exibir_ingressos_vendidos(&vendidos);
            printf("Digite o nome do filme que deseja cancelar.\n-> ");
            char filme_cancelar[100];
            scanf("%s", filme_cancelar);
            cancelar_ingresso(&disponiveis, &vendidos, filme_cancelar);
            break;
        
        case 3:
            printf("Ingressos disponiveis.\n");
            exibir_filmes_disponiveis(&disponiveis);
            break;

        case 4:
            printf("Ingresos Vendidos.\n");
            exibir_ingressos_vendidos(&vendidos);
            break;
        
        default:
            break;
    }

   }while(controle != 5);




    libera_lista(&disponiveis);
    libera_lista(&vendidos);



    return 0;
}
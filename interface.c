// Interface
// 17/12/2024

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    printf("PROGRAMA QUE CONVERTE DIFERENTES UNIDADES.\n");
    sleep(1);
    printf("ESCOLHA UMA DAS OPÇÕES:\n");
    sleep(1);
    printf("1. Unidades de comprimento (metro, centímetro, milímetro):\n");
    printf("2. Unidades de massa (quilograma, grama, tonelada): \n");
    printf("3. Unidades de temperatura (celsius, fahrenheit, kelvin): \n");

    int opcao;
    printf("Qual opção deseja? (1/2/3): ");
    scanf("%d", &opcao);

    switch(opcao)
    {
        case 1:
            system("~/Desktop/repos/tarefa-embarcatech/out/1comprimento.c");
            break;
        case 2:
            system("~/Desktop/repos/tarefa-embarcatech/out/2massa");
            break;
        case 3:
        system("~/Desktop/repos/tarefa-embarcatech/out/3temperatura");
            break;
        default:
            printf("Opção inválida.\n");
            printf("Encerrando...\n");
            sleep(1);
            exit(EXIT_FAILURE);
    }
    
    return 0;
}
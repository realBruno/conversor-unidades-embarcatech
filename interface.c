// Interface
// 17/12/2024

#include <stdio.h>
#include <unistd.h>
#include "./src/comprimento.h"
#include "./src/massa.h"
#include "./src/temperatura.h"

int main(void)
{   
    #ifdef _WIN32
    system("chcp 65001>NULL");
    #endif

    printf("PROGRAMA QUE CONVERTE DIFERENTES UNIDADES\n");
    sleep(1);
    printf("ESCOLHA UMA DAS OPÇÕES:\n");
    sleep(1);
    printf("1. Unidades de comprimento (metro, centímetro, milímetro):\n");
    printf("2. Unidades de massa (quilograma, grama, tonelada): \n");
    printf("4. Unidades de temperatura (celsius, fahrenheit, kelvin): \n");

    int opcao;
    printf("Qual opção deseja? (1/2/4): ");
    scanf("%d", &opcao);

    printf("\n");

    switch(opcao)
    {
        case 1:
            comprimento();
            break;
        case 2:
            massa();
            break;
        case 4:
            temperatura();
            break;
        default:
            printf("Opção inválida.\n");
            printf("Encerrando...\n");
            sleep(1);
            exit(EXIT_FAILURE);
    }
    
    return 0;
}
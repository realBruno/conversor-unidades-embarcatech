// Conversor de massa
// 17/12/2024

#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <stdlib.h>

// PROTÓTIPO DAS FUNÇÕES
double quilo(double x, char y);
double grama(double x, char y);
double ton(double x, char y);

int main(void)
{
    printf("PROGRAMA PARA CONVERTER PARA QUILO, GRAMA OU TONELADA\n");
    sleep(1); // delay de um segundo
    printf("Exemplos de entradas válidas: 30kg | 70.8g | 10.2T\n");
    sleep(1);

    double massa_original;
    char u_original;
    printf("Insira o comprimento com a formatação especificada: ");
    scanf("%lf%1c", &massa_original, &u_original);
    u_original = tolower(u_original);

    char c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    double massa_convertida;
    char u_convertida;
    
    switch(u_original)
    {
        case 'k':
            printf("Deseja converter para Gramas ou Toneladas? (G/T): ");
            scanf("%c", &u_convertida);
            u_convertida = tolower(u_convertida);
            massa_convertida = quilo(massa_original, u_convertida);
            break;
        case 'g':
            printf("Deseja converter para Quilos ou Toneladas? (K/T): ");
            scanf("%c", &u_convertida);
            u_convertida = tolower(u_convertida);
            massa_convertida = grama(massa_original, u_convertida);
            break;
        case 't':
            printf("Deseja converter para Quilos ou Gramas? (K/G): ");
            scanf("%c", &u_convertida);
            u_convertida = tolower(u_convertida);
            massa_convertida = ton(massa_original, u_convertida);
            break;
        default:
            printf("Entrada inválida.\n");
            printf("Encerrando...\n");
            sleep(1);
            exit(EXIT_FAILURE); // encerra o programa
    }

    printf("%.2lf%s equivale a %.2lf%s", 
            massa_original, 
            u_original == 'k' ? "kg" : (char[2]){u_original, '\0'}, 
            massa_convertida,
            u_convertida == 'k' ? "kg" : (char[2]){u_convertida, '\0'}
        );
    
    return 0;
}

// DEFINIÇÃO DAS FUNÇÕES
double quilo(double x, char y)
{   
    double convertido;

    if (y == 'g') // quilo para grama
    {
        convertido = x * 1000;
    }
    else // quilo para tonelada
    {
        convertido = x/1000.0f;
    }

    return convertido;
}

double grama(double x, char y)
{   
    double convertido;

    if (y == 'k') // grama para quilo
    {
        convertido = x/1000.0f;
    }
    else // grama para tonelada
    {
        convertido = x/1000000.0f;
    }
    
    return convertido;
}

double ton(double x, char y)
{   
    double convertido;
    
    if (y == 'k') // tonelada para quilo
    {
        convertido = x * 1000;
    }
    else // tonelada para grama
    {
        convertido = x * 1000000;
    }

    return convertido;
}
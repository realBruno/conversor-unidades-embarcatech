// Conversor de comprimento
// 17/12/2024

#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <stdlib.h>

// PROTÓTIPO DAS FUNÇÕES
double metros(double x, int y);
double centimetros(double x, int y);
double milimetros(double x, int y);

int comprimento(void)
{
    printf("CONVERSOR DE COMPRIMENTO\n");
    sleep(1); // delay de um segundo
    printf("Exemplos de entradas válidas: 30M | 70.8cm | 10.2MM\n");
    sleep(1);

    double comp_original;
    char unidade_original;
    printf("Insira o comprimento com a formatação especificada: ");
    scanf("%lf%1c", &comp_original, &unidade_original);
    unidade_original = tolower(unidade_original);

    char c;
    int mm = 0;
    while ((c = getchar()) != '\n' && c != EOF)
    {   
        // se houver m no buffer, usuário inputou mm
        if (c == 'm')
        {
            mm = 1;
        } 
    }

    double comp_convertido;
    int unidade_convertida;
    
    if (unidade_original == 'm' && mm != 1) // metro
    {
        printf("Deseja converter para centímetro (1) ou milímetro (2)? ");
        scanf("%d", &unidade_convertida);
        comp_convertido = metros(comp_original, unidade_convertida);
    }
    else if (unidade_original == 'c') // centímetro
    {
        printf("Deseja converter para metro (1) ou milímetro (2)? ");
        scanf("%d", &unidade_convertida);
        comp_convertido = centimetros(comp_original, unidade_convertida);
    }
    else if (unidade_original == 'm' && mm == 1) // milímetro
    {
        printf("Deseja converter para metro (1) ou centímetro (2)? ");
        scanf("%d", &unidade_convertida);
        comp_convertido = milimetros(comp_original, unidade_convertida);
    }
    else
    {
        printf("Entrada inválida.\n");
        printf("Encerrando...\n");
        sleep(1);
        exit(EXIT_FAILURE); // encerra o programa
    }

    printf("%.2lf%c equivale a %.2lf", 
            comp_original, 
            unidade_original, 
            comp_convertido
        );

    if (unidade_original == 'm' && mm != 1)
    {
        if (unidade_convertida == 1)
            printf("%s\n", "cm");
        else
            printf("%s\n", "mm");
    }
    else if (unidade_original == 'c')
    {
        if (unidade_convertida == 1)
            printf("%c\n", 'm');
        else
            printf("%s\n", "mm");
    }
    else if(unidade_original == 'm')
    {
        if (unidade_convertida == 1)
            printf("%c\n", 'm');
        else
            printf("%s\n", "cm");
    }
    
    return 0;
}

// DEFINIÇÃO DAS FUNÇÕES
double metros(double x, int y)
{   
    double convertido;

    if (y == 1) // metro para centímetro
    {   
        convertido = x * 100;
    }
    else // metro para milimetro
    {
        convertido = x * 1000;
    }

    return convertido;
}

double centimetros(double x, int y)
{   
    double convertido;

    if (y == 1) // centimetro para metro
    {
        convertido = x/100.0f;
    }
    else // centimetro para milimetro
    {
        convertido = x * 10;
    }

    return convertido;
}

double milimetros(double x, int y)
{   
    double convertido;
    
    if (y == 1) // milimetro para metro
    {
        convertido = x/1000.0f;
    }
    else // milimetro para centimetro
    {
        convertido = x/10.0f;
    }

    return convertido;
}
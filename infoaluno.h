#include <stdio.h>
#include <locale.h>
#ifndef INFOALUNO_H
#define INFOALUNO_H

void exibirInformacoes()
{
    setlocale(LC_ALL, "Portuguese");
    printf("\n\t\t\t***                             INFORMAÇÕES DO ALUNO                      ***");
    printf("\n\t\t\t+---------------------------------------------------------------------------+");
    printf("\n\t\t\t| Nome            - Lucas Cano Puerta                                       |");
    printf("\n\t\t\t| Prontuário      - PE3009777                                               |");
    printf("\n\t\t\t| Curso           - Bacharelado em Ciências da Computação                   |");
    printf("\n\t\t\t| Ano de Ingresso - 2021                                                    |");
    printf("\n\t\t\t+---------------------------------------------------------------------------+");

    printf("\n\n\n\t\t\t Pressione ESC para voltar ao editor");

    int tecla;
    while (1)
    {
        tecla = getch();
        if (tecla == 27)   // Verifica se a tecla pressionada é o "Esc" (código 27)
        {
            break; // Sai do loop quando o "Esc" é pressionado
        }
    }
}

#endif // INFOALUNO_H

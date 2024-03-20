#include <stdio.h>
#include <locale.h>
#ifndef LUCASPUERTA_AJUDA_H
#define LUCASPUERTA_AJUDA_H

void exibirAjuda()
{
    setlocale(LC_ALL, "Portuguese");
    printf("\n\t\t\t***                             FUNÇÕES DO EDITOR                         ***");
    printf("\n\t\t\t+---------------------------------------------------------------------------+");
    printf("\n\t\t\t| F1          - Exibe este texto de ajuda                                   |");
    printf("\n\t\t\t| F2          - Salvar o arquivo atual                                      |");
    printf("\n\t\t\t| F10         - Ler um arquivo de texto                                     |");
    printf("\n\t\t\t| F12         - Exibe as informações do aluno                               |");
    printf("\n\t\t\t| ESC         - Sai da aplicação / fecha a tela de ajuda                    |");
    printf("\n\t\t\t| SETAS       - Navegam pelo texto que esta sendo editado                   |");
    printf("\n\t\t\t| INSERT      - Sobrescreve o texto anteriormente digitado                  |");
    printf("\n\t\t\t| PGUP e PGDW - Troca entre a página de cima e a de baixo                   |");
    printf("\n\t\t\t| HOME        - Posiciona o cursor no inicio da linha que está posicionado  |");
    printf("\n\t\t\t| HOME        - Posiciona o cursor no fim da linha que está posicionado     |");
    printf("\n\t\t\t| DELETE      - Apaga o conteúdo aonde o cursor está posicionado            |");
    printf("\n\t\t\t| BACKSPACE   - Apaga o elemento anterior ao posicionamento do cursor       |");
    printf("\n\t\t\t| ENTER       - Salta para a próxima linha                                  |");
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

#endif // LUCASPUERTA_AJUDA_H

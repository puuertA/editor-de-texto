void carregarTexto(NoLinha** cabecaTexto, int* linha_cursor, int* coluna_cursor)
{
    NoLinha* textoCarregado = carregarTextoDoArquivo("LucasPuerta_texto.txt");
    animacaoCarregar();
    if (textoCarregado != NULL)
    {
        *cabecaTexto = textoCarregado;
        moverCursorParaUltimaPosicao(*cabecaTexto, linha_cursor, coluna_cursor);
        moverCursorFim(*cabecaTexto, linha_cursor, coluna_cursor);
        exibirTexto(*cabecaTexto);
    }
}

int editor(NoLinha* cabecaTexto)
{
    estilizarTela(); // Configura a estilização da tela/console
    int cursor_visivel = 0; // Define se o cursor está visível (0 = invisível)
    int ch; // Variável para armazenar o caractere digitado

    if (cabecaTexto == NULL)
    {
        cabecaTexto = criarNovaLinha();
        // Restante do seu código para inicializar a estrutura cabecaTexto
    }
    // Inicializa a lista de linhas com uma linha vazia

    exibirTexto(cabecaTexto); // Exibe o texto vazio na tela

    // Variáveis para controlar a posição do cursor, modo de escrita e mudanças no texto
    int linha_cursor = 0;
    int coluna_cursor = 0;
    int modoEscrita = 1; // 1 = modo de inserção, 0 = modo de sobreescrita
    int texto_mudado = 1; // variavel que indica se o texto foi alterado
    int continuar_execucao = 1; // variavel para continuar/parar a execução do loop principal
    int cursor_atualizado = 0; // variavel para indicar se o cursor foi atualizado

    while (continuar_execucao)
    {
        if (kbhit()) // Verifica se há entrada disponível
        {
            ch = getch(); // Captura a entrada do teclado

            // Processamento das teclas pressionadas
            if (ch == 27) // Tecla Esc
            {
                teclaEsc(cabecaTexto, &continuar_execucao);
            }
            else if (ch >= 32 && ch <= 183) // Letras, números e símbolos imprimíveis
            {
                if (modoEscrita)
                {
                    modoInsercao(&cabecaTexto, &linha_cursor, &coluna_cursor, ch);
                }
                else
                {
                    modoSobreescrita(obterLinha(cabecaTexto, linha_cursor), coluna_cursor, ch);
                }
            }
            else if (ch == 13) // Tecla Enter
            {
                teclaEnter(&cabecaTexto, &linha_cursor, &coluna_cursor);
            }
            else if (ch == 8) // Tecla Backspace
            {
                teclaBackspace(&cabecaTexto, &linha_cursor, &coluna_cursor);
            }
            else if (ch == 224) // Teclas especiais
            {
                cursor_atualizado = 1;
                ch = getch(); // Leitura do segundo caractere

                if (ch == 71) // Tecla Home
                {
                    moverCursorInicio(&coluna_cursor);
                }
                else if (ch == 79) // Tecla End
                {
                    moverCursorFim(cabecaTexto, &linha_cursor, &coluna_cursor);
                }
                else if (ch == 72) // Tecla Seta para cima
                {
                    moverCursorCima(&linha_cursor);
                }
                else if (ch == 80) // Tecla Seta para baixo
                {
                    moverCursorBaixo(&linha_cursor);
                }
                else if (ch == 75) // Tecla Seta para a esquerda
                {
                    moverCursorEsquerda(&coluna_cursor);
                }
                else if (ch == 77) // Tecla Seta para a direita
                {
                    moverCursorDireita(&coluna_cursor);
                }
                else if (ch == 134) // F12
                {
                    exibirInformacoes();
                }
                else if (ch == 83) // Tecla Delete
                {
                    teclaDelete(&cabecaTexto, &linha_cursor, &coluna_cursor);
                }
                else if (ch == 82) // Tecla Insert
                {
                    alternarModoInsercao(&modoEscrita); // Chama a função para alternar entre os modos
                }
                else if (ch == 73)   // Tecla Page Up
                {
                    moverCursorPaginaAcima(&linha_cursor);
                }
                else if (ch == 81)   // Tecla Page Down
                {
                    moverCursorPaginaAbaixo(&linha_cursor);
                }
            }
            else if (ch == 0) // Teclas de função
            {
                ch = getch(); // Leitura do segundo caractere

                if (ch == 59) // F1
                {
                    exibirAjuda();
                }
                else if (ch == 60) // F2
                {
                    salvarTextoEmArquivo(cabecaTexto, "LucasPuerta_texto.txt");
                    animacaoSalvar();
                    exibirTexto(cabecaTexto);
                }
                else if (ch == 68) // F10
                {
                    carregarTexto(&cabecaTexto, &linha_cursor, &coluna_cursor);
                }
            }
            texto_mudado = 1;
        }

        if (cursor_atualizado || texto_mudado)
        {
            exibirTextoSeModificado(cabecaTexto, &texto_mudado, &cursor_atualizado);
        }

        int linha_atual = 0;
        int coluna_atual = 0;
        NoLinha *linhaTemp = cabecaTexto;

        while (linhaTemp != NULL && linha_atual < linha_cursor)
        {
            linha_atual++;
            linhaTemp = linhaTemp->proxLinha;
        }

        if (linhaTemp != NULL)
        {
            No *colunaTemp = linhaTemp->cabecaColuna;
            while (colunaTemp != NULL && coluna_atual < coluna_cursor)
            {
                coluna_atual++;
                colunaTemp = colunaTemp->prox;
            }
        }

        if (linha_atual == linha_cursor && coluna_atual == coluna_cursor)
        {
            gotoxy(coluna_cursor, linha_cursor);
        }

        Sleep(5);
    }
    return 0;
}

void menuPrincipal()
{
    estilizarTela();
    animacaoInicio();
    limparTela();
    setlocale(LC_ALL, "Portuguese");
    int op = 0;
    NoLinha* cabecaTexto = NULL;
    int linha_cursor = 0;
    int coluna_cursor = 0;
    limparTela();
    do
    {
        cabecaTexto = NULL;
        printf("\n\t\t\t\t\t***      BEM VINDO AO MATRIX 4!     ***");
        printf("\n\t\t\t\t\t+----------------OPÇÕES---------------+");
        printf("\n\t\t\t\t\t| 1 - Criar um novo arquivo           |");
        printf("\n\t\t\t\t\t| 2 - Abrir o arquivo salvo           |");
        printf("\n\t\t\t\t\t| 3 - Sair                            |");
        printf("\n\t\t\t\t\t+-------------------------------------+");
        printf("\n\n Selecione uma opção \n\n>>> ");
        scanf("%d", &op);
        if(op == 1 || op == 2 || op == 3)
        {
            if(op == 1)
            {
                editor(NULL);
            }
            else if(op == 2)
            {
                carregarTexto(&cabecaTexto, &linha_cursor, &coluna_cursor);
                editor(cabecaTexto);
            }
            else if(op == 3)
            {
                liberarMemoria(&cabecaTexto);
                break;
            }
        }
        else
        {
            limparTela();
            printf("\nOpção inválida!");
        }
    }
    while(op != 3);
}

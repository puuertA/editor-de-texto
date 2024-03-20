void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void moverCursorCima(int *linha_cursor)
{
    if (*linha_cursor > 0)
    {
        (*linha_cursor)--;
    }
}

void moverCursorBaixo(int *linha_cursor)
{
    if (*linha_cursor < MAX_LINHAS - 1)
    {
        (*linha_cursor)++;
    }
}

void moverCursorDireita(int *coluna_cursor)
{
    if (*coluna_cursor < MAX_COLUNAS - 1)
    {
        (*coluna_cursor)++;
    }
}

void moverCursorEsquerda(int *coluna_cursor)
{
    if (*coluna_cursor > 0)
    {
        (*coluna_cursor)--;
    }
}

void moverCursorInicio(int *coluna_cursor)
{
    *coluna_cursor = 0;
}

void moverCursorFim(NoLinha *cabecaTexto, int *linha_cursor, int *coluna_cursor)
{
    // Encontrar o fim da linha atual
    NoLinha *linhaTemp = obterLinha(cabecaTexto, *linha_cursor);
    if (linhaTemp != NULL)
    {
        No *colunaTemp = linhaTemp->cabecaColuna;
        int fimLinha = 0;
        int coluna = 0;
        while (coluna < MAX_COLUNAS && colunaTemp != NULL)
        {
            if (colunaTemp->dado != ' ')
            {
                fimLinha = coluna + 1;
            }
            colunaTemp = colunaTemp->prox;
            coluna++;
        }
        if (fimLinha > 0)
        {
            *coluna_cursor = fimLinha;
        }
    }
}

void moverCursorParaUltimaPosicao(NoLinha* cabecaTexto, int* linha_cursor, int* coluna_cursor)
{
    NoLinha* linhaTemp = cabecaTexto;
    int ultimaLinha = 0;

    while (linhaTemp->proxLinha != NULL)
    {
        ultimaLinha++;
        linhaTemp = linhaTemp->proxLinha;
    }
    ultimaLinha--;
    *linha_cursor = ultimaLinha;
    *coluna_cursor = contarColunas(linhaTemp);
}

void moverCursorPaginaAcima(int *linha_cursor)
{
    if (*linha_cursor >= 25)
    {
        for (int i = 0; i < 25; i++)
        {
            moverCursorCima(linha_cursor);
        }
    }
    else
    {
        *linha_cursor = 0; // Define o cursor para a primeira linha se não houver 25 linhas para cima
    }
}

void moverCursorPaginaAbaixo(int *linha_cursor)
{
    if (*linha_cursor + 25 < MAX_LINHAS - 1)
    {
        for (int i = 0; i < 25; i++)
        {
            moverCursorBaixo(linha_cursor);
        }
    }
    else
    {
        *linha_cursor = MAX_LINHAS - 1; // Define o cursor para a última linha se não houver 25 linhas para baixo
    }
}


#include <stdio.h>
#include "ui.h"

void ui_title(const char *title)
{

    if (title == NULL)
    {
        ui_error("Titulo nao fornecido.");
        return;
    }

    printf("%s %s %s\n", COLOR_BLUE, title, COLOR_RESET);

    printf("\n%s========================================%s\n", COLOR_CYAN, COLOR_RESET);
    printf("%s         %s           %s\n", COLOR_BOLD, title, COLOR_RESET);
    printf("%s========================================%s\n", COLOR_CYAN, COLOR_RESET);
}

void ui_error(const char *msg)
{

    if (msg == NULL)
    {
        printf("%sERRO:%s Ocorreu um erro desconhecido (mensagem nula).\n", COLOR_RED, COLOR_RESET);

        return;
    }

    printf("%sERRO:%s %s\n", COLOR_RED, COLOR_RESET, msg);
}

void ui_success(const char *msg)
{

    if (msg == NULL)
    {
        printf("%sSucesso:%s Operacao concluida com sucesso.\n", COLOR_GREEN, COLOR_RESET);

        return;
    }

    printf("%sSucesso:%s %s\n", COLOR_GREEN, COLOR_RESET, msg);
}

int ui_show_menu()
{

    ui_title("CATÁLOGO DE JOGOS");

    printf("  %s[1]%s Listar Jogos do Catálogo\n", COLOR_YELLOW, COLOR_RESET);
    printf("  %s[2]%s Cadastrar Novo Jogo\n", COLOR_YELLOW, COLOR_RESET);
    printf("  %s[3]%s Atualizar Jogo\n", COLOR_YELLOW, COLOR_RESET);
    printf("  %s[4]%s Remover Jogo\n", COLOR_YELLOW, COLOR_RESET);
    printf("  %s[5]%s Ver Ranking Pessoal\n", COLOR_YELLOW, COLOR_RESET);
    printf("  %s[6]%s  Ver Milestone Tracker (Progresso)\n", COLOR_YELLOW, COLOR_RESET);
    printf("  %s[0]%s Sair do Sistema\n", COLOR_RED, COLOR_RESET);

    printf("%s========================================%s\n", COLOR_CYAN, COLOR_RESET);

    int choice;
    printf("%sEscolha uma opção:%s ", COLOR_BOLD, COLOR_RESET);

    if (scanf("%d", &choice) != 1)
    {
        int c;

        while ((c = getchar()) != '\n' && c != EOF)
            ;

        choice = -1;
    }

    return choice;
}

int ui_show_sort_menu(void)
{
    ui_title("MENU DE ORDENAÇÃO");

    printf("  %s[1]%s Nota Pessoal\n", COLOR_YELLOW, COLOR_RESET);
    printf("  %s[2]%s Preço Crescente\n", COLOR_YELLOW, COLOR_RESET);
    printf("  %s[3]%s Horas Jogadas Decrescente\n", COLOR_YELLOW, COLOR_RESET);
    printf("  %s[4]%s Recomendado pelo sistema (Score Ponderado)\n", COLOR_YELLOW, COLOR_RESET);
    printf("  %s[0]%s Voltar\n", COLOR_RED, COLOR_RESET);

    printf("%s========================================%s\n", COLOR_CYAN, COLOR_RESET);

    int choice;
    printf("%sEscolha uma opção de ordenação:%s ", COLOR_BOLD, COLOR_RESET);

    if (scanf("%d", &choice) != 1)
    {
        int c;
        while ((c = getchar()) != '\n' && c != EOF)
            ;

        choice = -1;
    }

    return choice;
}

float clamp(float valor, float minimo, float maximo)
{
    // Se o valor for menor que o mínimo, retorna o mínimo.
    // Se for maior que o máximo, retorna o máximo.
    // Caso contrário, retorna o valor.
    return (valor < minimo)   ? minimo
           : (valor > maximo) ? maximo
                              : valor;
}

void ui_progress_bar(float percentage, int width)
{
    float progress;

    // Calcula o progresso
    progress = clamp(percentage, 0.0f, 100.0f);

    int filled, empty;

    // Calcula os blocos vazios e preenchidos do unicode
    filled = (int)((progress / 100.0f * width));
    empty = width - filled;

    int color;

    // Define a cor que será usada a depender do progresso
    if (progress < 40)
    {
        color = 1;
    }
    else if (progress >= 75)
    {
        color = 3;
    }
    else
    {
        color = 2;
    }

    // Display da barra de progresso

    printf("[ %s ", (color == 1) ? COLOR_RED : (color == 2) ? COLOR_YELLOW
                                                            : COLOR_GREEN);

    for (int i = 0; i < filled; i++)
    {
        printf("\u2588");
    }
    printf("%s", COLOR_GRAY);

    for (int i = 0; i < empty; i++)
    {
        printf("\u2591");
    }

    printf("] %s %.1f%% %s\n ", COLOR_BOLD, percentage, COLOR_RESET);
}

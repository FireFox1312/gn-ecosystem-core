
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
    printf("  %s[3]%s Atualizar Instância\n", COLOR_YELLOW, COLOR_RESET);
    printf("  %s[4]%s Remover (Hard Delete)\n", COLOR_YELLOW, COLOR_RESET);
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

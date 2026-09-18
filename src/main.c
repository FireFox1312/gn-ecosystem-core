#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

#include "game.h"
#include "user.h"
#include "ui.h"

int main(void)
{
    SetConsoleOutputCP(65001);

    ui_title("Sistema Inicializado");

    User *user = create_user(1, "Cadu");

    display_user_info(user);

    int capacity = 4;
    int size = 0;

    Game *catalog = game_create_catalog(capacity);

    if (catalog == NULL)
    {
        return 1;
    }

    int option;

    do
    {
        option = ui_show_menu();

        switch (option)
        {
        case 1:
            game_list_all(catalog, size);
            ui_success("Listagem completa");
            break;

        case 2:
            game_create(&catalog, &size, &capacity);
            ui_success("Jogo cadastrado.");
            break;

        case 3:
            game_update(catalog, size);
            ui_success("Jogo atualizado com sucesso!");
            break;

        case 4:
            game_delete(&catalog, &size);
            break;

        case 0:
            ui_success("Saindo do sistema. Até logo!");
            break;

        default:
            ui_error("Opção inválida! Por favor, tente novamente.");
            break;
        }

    } while (option != 0);

    free(catalog);
    free(user);
    return 0;
}

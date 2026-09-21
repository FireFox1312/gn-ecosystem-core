#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

#include "game.h"
#include "user.h"
#include "ui.h"
#include "recommender.h"

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

        case 5:
        {
            int sort_option = ui_show_sort_menu();
            switch (sort_option)
            {
            case 1:
                game_ordenation(catalog, size);
                game_list_all(catalog, size);
                ui_success("Catálogo ordenado por Nota Pessoal.");
                break;
            case 2:
                if (size > 0)
                    recommender_quicksort(catalog, 0, size - 1, compare_by_price_asc);
                game_list_all(catalog, size);
                ui_success("Catálogo ordenado por Preço Crescente.");
                break;
            case 3:
                if (size > 0)
                    recommender_quicksort(catalog, 0, size - 1, compare_by_hours_desc);
                game_list_all(catalog, size);
                ui_success("Catálogo ordenado por Horas Jogadas.");
                break;
            case 0:
                break;
            default:
                ui_error("Opção de ordenação inválida.");
                break;
            }
            break;
        }

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

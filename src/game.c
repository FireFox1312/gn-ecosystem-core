#include <stdio.h>
#include <stdlib.h>
#include "game.h"

Game* game_create_catalog(int initial_capacity)
{
    Game *catalog = malloc(initial_capacity * sizeof(*catalog));

    if (catalog == NULL)
    {
        fprintf(stderr, "Erro: falha na alocacao de memoria.\n");
    }

    return catalog;
}

Game* game_resize_catalog(Game *catalog, int *capacity)
{
    int new_capacity = (*capacity) * 2;

    Game *temp = realloc(catalog, new_capacity * sizeof(*temp));

    if (temp == NULL)
    {
        fprintf(stderr, "Erro: falha na expansao de memoria.\n");
        return catalog;
    }

    *capacity = new_capacity;

    return temp;
}

void game_register(Game *game)
{
    printf("Digite o ID do jogo: ");
    scanf("%d", &game->id);

    printf("Digite o nome do jogo: ");
    scanf("%s", game->title);

    printf("Digite o genero do jogo: ");
    scanf("%s", game->genre);

    printf("Digite o preco do jogo: ");
    scanf("%f", &game->price);

    return;
}

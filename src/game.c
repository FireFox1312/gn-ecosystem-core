#include <stdio.h>
#include <stdlib.h>
#include "game.h"

Game* game_create_catalog(int initial_capacity)
{
    Game *catalog = malloc(initial_capacity * sizeof(*catalog));

    if (catalog == NULL)
    {
        fprintf(stderr, "Error: memory allocation failed.\n");
    }

    return catalog;
}

Game* game_resize_catalog(Game *catalog, int *capacity)
{
    int new_capacity = (*capacity) * 2;

    Game *temp = realloc(catalog, new_capacity * sizeof(*temp));

    if (temp == NULL)
    {
        fprintf(stderr, "Error: memory reallocation failed.\n");
        return catalog;
    }

    *capacity = new_capacity;

    return temp;
}

void game_register(Game *game)
{
    printf("Enter game ID: ");
    scanf("%d", &game->id);

    printf("Enter game title: ");
    scanf("%s", game->title);

    printf("Enter game genre: ");
    scanf("%s", game->genre);

    printf("Enter game price: ");
    scanf("%f", &game->price);

    return;
}

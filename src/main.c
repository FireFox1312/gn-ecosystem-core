#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "game.h"

int main(void)
{
    int capacity = 4;
    int size = 0;

    Game *catalog = game_create_catalog(capacity);

    if (catalog == NULL)
    {
        return 1;
    }

    catalog[0].id = 1;
    catalog[0].status_flags = FLAG_INSTALLED | FLAG_COMPLETED;
    strcpy(catalog[0].title, "The Legend of Zelda: Breath of the Wild");
    size++;

    if (size == capacity)
    {
        printf("Capacity exhausted (%d). Expanding...\n", capacity);
        catalog = game_resize_catalog(catalog, &capacity);
        printf("New capacity: %d\n", capacity);
    }

    catalog[1].id = 2;
    catalog[1].status_flags = FLAG_INSTALLED | FLAG_FAVORITE;
    strcpy(catalog[1].title, "Super Mario Odyssey");
    size++;

    if (size == capacity)
    {
        printf("Capacity exhausted (%d). Expanding...\n", capacity);
        catalog = game_resize_catalog(catalog, &capacity);
        printf("New capacity: %d\n", capacity);
    }

    catalog[2].id = 3;
    catalog[2].status_flags = FLAG_INSTALLED | FLAG_MULTIPLAYER;
    strcpy(catalog[2].title, "Fortnite");
    size++;

    if (size == capacity)
    {
        printf("Capacity exhausted (%d). Expanding...\n", capacity);
        catalog = game_resize_catalog(catalog, &capacity);
        printf("New capacity: %d\n", capacity);
    }

    catalog[3].id = 4;
    catalog[3].status_flags = FLAG_INSTALLED | FLAG_CLOUD;
    strcpy(catalog[3].title, "Minecraft");
    size++;

    if (size == capacity)
    {
        printf("Capacity exhausted (%d). Expanding...\n", capacity);
        catalog = game_resize_catalog(catalog, &capacity);
        printf("New capacity: %d\n", capacity);
    }

    catalog[4].id = 5;
    catalog[4].status_flags = FLAG_INSTALLED | FLAG_COMPLETED | FLAG_FAVORITE;
    strcpy(catalog[4].title, "The Witcher 3: Wild Hunt");
    size++;

    if (size == capacity)
    {
        printf("Capacity exhausted (%d). Expanding...\n", capacity);
        catalog = game_resize_catalog(catalog, &capacity);
        printf("New capacity: %d\n", capacity);
    }

    for (int i = 0; i < size; i++)
    {
        printf("Game %d: %s\n", catalog[i].id, catalog[i].title);
    }

    free(catalog);

    return 0;
}

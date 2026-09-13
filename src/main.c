#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "game.h"
#include "user.h"

int main(void)
{

    User *user = create_user(1, "Cadu");

    display_user_info(user);

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

    

    for (int i = 0; i < size; i++)
    {
        printf("Jogo %d: %s\n", catalog[i].id, catalog[i].title);
    }

    free(catalog);
    free(user);
    return 0;
}

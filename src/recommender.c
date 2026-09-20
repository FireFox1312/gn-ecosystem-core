
#include "game.h"
#include "recommender.h"
#include "ui.h"

void game_ordenation(Game *catalog, int size)
{
    Game *c = catalog;

    for(int i = 0; i < size - 1; i++)
    {
        int swapped = 0;

        for (int j = 0; j < size - i - 1; j++)
        {
            if (c[j].user_rating < c[j + 1].user_rating)
            {
                Game swap_game = c[j];

                c[j] = c[j + 1];
                
                c[j + 1] = swap_game;

                swapped++;
            }
            if (swapped == 0)
            {
                break;
            }
            
        }
    }
}

#include <stdlib.h>

#include "game.h"
#include "recommender.h"
#include "ui.h"

void swap_game(Game *a, Game *b)
{
    Game temp = *a;

    *a = *b;
    *b = temp;
}

void game_ordenation(Game *catalog, int size)
{
    Game *c = catalog;

    for (int i = 0; i < size - 1; i++)
    {
        int swapped = 0;

        for (int j = 0; j < size - i - 1; j++)
        {
            if (c[j].user_rating < c[j + 1].user_rating)
            {
                swap_game(&c[j], &c[j + 1]);

                swapped++;
            }
        }

        if (swapped == 0)
        {
            break;
        }
    }
}

int compare_by_price_asc(const Game *a, const Game *b)
{
    if (a->price > b->price)
        return 1;
    if (a->price < b->price)
        return -1;
    return 0;
}

int compare_by_hours_desc(const Game *a, const Game *b)
{
    if (a->hours_played > b->hours_played)
        return -1;
    if (a->hours_played < b->hours_played)
        return 1;
    return 0;
}

int recommender_partition(Game *catalog, int low, int high, GameComparator cmp)
{
    Game *c = catalog;

    const Game *pivot = &c[high];

    int i = low - 1; // Índice de fronteira (último menor ou igual ao pivô)

    for (int j = low; j < high; j++) // Índice de varredura que varre até o penúltimo elemento
    {
        if (cmp(&c[j], pivot) < 0) // Se a comparação com o pivot retornar menor que 0
        {
            i++;
            swap_game(&c[i], &c[j]); // Troca com o índice de fronteira
        }
    }

    swap_game(&c[i + 1], &c[high]); // Coloca o pivô na fronteira entre os menores e maiores que ele
    return (i + 1);                 // Retorna o índice final do pivô
}

void recommender_quicksort(Game *catalog, int low, int high, GameComparator cmp)
{

    if (low < high)
    {
        int pi = recommender_partition(catalog, low, high, cmp);

        // Chamada recursiva para esquerda e direita do pivô
        recommender_quicksort(catalog, low, pi - 1, cmp);
        recommender_quicksort(catalog, pi + 1, high, cmp);
    }
}

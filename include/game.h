// Header guards to prevent multiple inclusions

#ifndef GAME_H
#define GAME_H

#include <stdint.h>

#define FLAG_INSTALLED   (1 << 0) // 0000 0001
#define FLAG_COMPLETED   (1 << 1) // 0000 0010
#define FLAG_FAVORITE    (1 << 2) // 0000 0100
#define FLAG_MULTIPLAYER (1 << 3) // 0000 1000
#define FLAG_CLOUD       (1 << 4) // 0001 0000

typedef struct
{
    int id;
    uint8_t status_flags;       // Bitwise-packed game status
    char title[100];
    char genre[50];
    int release_year;
    float price;
    int hours_played;
    int metacritic_score;
} Game;

// Allocates a Game array on the heap with the given initial capacity.
// Returns a pointer to the array, or NULL on allocation failure.
Game* game_create_catalog(int initial_capacity);

// Resizes the catalog by doubling its capacity.
// Returns the new pointer, or the original on realloc failure.
Game* game_resize_catalog(Game *catalog, int *capacity);

// Reads game data from stdin and fills the given Game struct.
void game_register(Game *game);

#endif // GAME_H

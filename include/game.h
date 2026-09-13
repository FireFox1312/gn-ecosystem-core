// Guardas de cabeçalho para evitar múltiplas inclusões

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
    uint8_t status_flags;       // Status do jogo compactado em bits
    char title[100];
    char genre[50];
    int release_year;
    float price;
    int hours_played;
    int metacritic_score;
} Game;

// Aloca um vetor de Game na heap com a capacidade inicial fornecida.
// Retorna um ponteiro para o array, ou NULL em caso de falha na alocação.
Game* game_create_catalog(int initial_capacity);

// Redimensiona o catálogo dobrando sua capacidade.
// Retorna o novo ponteiro, ou o original em caso de falha no realloc.
Game* game_resize_catalog(Game *catalog, int *capacity);

// Lê os dados de um jogo a partir da entrada padrão (stdin).
void game_register(Game *game);

#endif // GAME_H

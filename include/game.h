// Guardas de cabeçalho para evitar múltiplas inclusões

#ifndef GAME_H
#define GAME_H

#include <stdint.h>

#define FLAG_INSTALLED   (1 << 0) // 0000 0001
#define FLAG_COMPLETED   (1 << 1) // 0000 0010
#define FLAG_FAVORITE    (1 << 2) // 0000 0100
#define FLAG_MULTIPLAYER (1 << 3) // 0000 1000
#define FLAG_CLOUD       (1 << 4) // 0001 0000
#define FLAG_DELETED     (1 << 5) // 0010 0000

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

/**
 * @brief Adiciona um novo jogo interativamente ao catalogo.
 * @details Realiza leituras via terminal e expande a memoria dinamicamente usando realloc
 *          caso a capacidade limite do array seja atingida.
 * @param catalog Ponteiro duplo para o array (permite atualizar a raiz alocada no Heap em caso de resize).
 * @param size Ponteiro da variavel que monitora a contagem de games registrados (sera incrementado).
 * @param capacity Ponteiro da variavel que denota o espaco real reservado na memoria.
 */

void game_create(Game **catalog, int *size, int *capacity);

/**
 * @brief Lista todos os jogos cadastrados no catalogo de forma tabulada.
 * @details Decodifica as flags bitwise em retornos de string booleanos legiveis para o terminal (Sim/Nao).
 * @param catalog Ponteiro constante para o array raiz (Garante integridade de leitura).
 * @param size Quantidade atual de jogos registrados no array.
 */

void game_list_all(const Game *catalog, int size);

/**
 * @brief Realiza uma busca linear e sequencial no array procurando uma instancia de Game pelo ID.
 * @param catalog Ponteiro constante para o array raiz (Garante integridade de leitura).
 * @param size Quantidade atual de jogos registrados no array.
 * @param id Identificador exato e unico do jogo a ser rastreado.
 * @return O indice numerico da posicao array do jogo caso localizado; -1 caso nao exista.
 */

int game_find_by_id(const Game *catalog, int size, int id);

void game_update(Game *catalog, int size);

void game_delete(Game **catalog, int *size);

#endif // GAME_H

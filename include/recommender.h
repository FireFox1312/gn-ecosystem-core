#ifndef RECOMMENDER_H
#define RECOMMENDER_H

#include "game.h"

// Define a função de comparação para ordenação (Qualquer função que receba dois ponteiros para Game e retorne um int)
typedef int (*GameComparator)(const Game *a, const Game *b);

/**
 * @brief Ordena o catálogo in-place utilizando o algoritmo Bubble Sort.
 * @details A ordenação é feita de forma decrescente utilizando o campo 'user_rating'.
 * @param catalog Ponteiro para o array de jogos.
 * @param size Quantidade atual de elementos preenchidos.
 */

void game_ordenation(Game *catalog, int size);

/**
 * @brief Ordena o catálogo in-place utilizando o algoritmo Quicksort.
 * @details Utiliza a estratégia de particionamento de Lomuto e permite a injeção
 *          de uma função comparadora (GameComparator) para determinar a ordem.
 *          A função comparadora (cmp) deve retornar:
 *          - Negativo (< 0) se o elemento 'a' vier antes de 'b'
 *          - Positivo (> 0) se o elemento 'a' vier depois de 'b'
 *          - 0 se forem equivalentes em ordem.
 * @param catalog Ponteiro para o array de jogos.
 * @param low Índice inicial da partição (geralmente 0).
 * @param high Índice final da partição (geralmente size - 1).
 * @param cmp Ponteiro para a função comparadora.
 */
void recommender_quicksort(Game *catalog, int low, int high, GameComparator cmp);

int compare_by_price_asc(const Game *a, const Game *b);

int compare_by_hours_desc(const Game *a, const Game *b);

#endif // RECOMMENDER_H
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

/**
 * @brief Calcula a pontuação de um jogo com base em seus atributos.
 * @param game Ponteiro para o jogo.
 * @return A pontuação calculada.
 */

float recommender_calculate_score(const Game *game);

/**
 * @brief Compara dois jogos por pontuação em ordem decrescente.
 * @param a Ponteiro para o primeiro jogo.
 * @param b Ponteiro para o segundo jogo.
 * @return Valor negativo se 'a' tiver pontuação maior que 'b', positivo se 'a' tiver pontuação menor que 'b', 0 se forem iguais.
 */

int compare_by_score_desc(const Game *a, const Game *b);

#endif // RECOMMENDER_H

#ifndef RECOMMENDER_H
#define RECOMMENDER_H

#include "game.h"

/**
 * @brief Ordena o catálogo in-place utilizando o algoritmo Bubble Sort.
 * @details A ordenação é feita de forma decrescente utilizando o campo 'user_rating'.
 * @param catalog Ponteiro para o array de jogos.
 * @param size Quantidade atual de elementos preenchidos.
 */

void game_ordenation(Game *catalog, int size);

#endif // RECOMMENDER_H
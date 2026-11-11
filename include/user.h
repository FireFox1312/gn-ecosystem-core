#ifndef USER_H
#define USER_H

#include <stdint.h>
#include "game.h"

typedef struct
{
    int id;
    char username[50];
    int xp_level;
    int achievements_count;
} User;

User *create_user(int id, char *username);

void display_user_info(const User *user);

/**
 * @brief Exibição dos dados da conta do respectivo usuário.
 * @details Ideal para ter um overview dos dados de progresso do usuário e milestone tracker.
 * @param user Ponteiro para a variável que contém os dados do usuário.
 * @param catalog Ponteiro para o catálogo de jogos do usuário.
 * @param size Quantidade de jogos registrados no catálogo.
 */
void user_display_milestone_tracker(User *user, const Game *catalog, int size);

#endif // USER_H

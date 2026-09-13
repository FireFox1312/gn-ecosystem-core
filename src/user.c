
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"

User* create_user( int id, char *username){

    User *user = malloc(sizeof(User));

    if (user == NULL)
    {
        fprintf(stderr, "Erro: falha na alocacao de memoria\n");
        return NULL;
    }
    
    user->id = id;
    strncpy(user->username, username, sizeof(user->username) - 1); // Preencher o nome de usuário
    user->username[sizeof(user->username) - 1] = '\0'; // Garantir que a string seja terminada com '\0' (Pra caso o nome de usuário seja maior que 49 caracteres)
    user->xp_level = 1;
    user->achievements_count = 0;

    printf("Usuario cadastrado com sucesso!\n");
    printf("ID: %d\n", user->id);
    printf("Username: %s\n", user->username);
    printf("XP Level: %d\n", user->xp_level);
    printf("Achievements Count: %d\n", user->achievements_count);

    return user;

}

void display_user_info(const User *user){

    if (user == NULL)
    {
        return;
    }
    
    printf("=== User Information ===\n");
    printf("ID: %d\n", user->id);
    printf("Username: %s\n", user->username);
    printf("XP Level: %d\n", user->xp_level);
    printf("Achievements Count: %d\n", user->achievements_count);

}

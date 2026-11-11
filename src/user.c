
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"
#include "ui.h"

User *create_user(int id, char *username)
{

    User *user = malloc(sizeof(User));

    if (user == NULL)
    {
        fprintf(stderr, "Erro: falha na alocacao de memoria\n");
        return NULL;
    }

    user->id = id;
    strncpy(user->username, username, sizeof(user->username) - 1); // Preencher o nome de usuário
    user->username[sizeof(user->username) - 1] = '\0';             // Garantir que a string seja terminada com '\0' (Pra caso o nome de usuário seja maior que 49 caracteres)
    user->xp_level = 1;
    user->achievements_count = 0;

    printf("Usuario cadastrado com sucesso!\n");
    printf("ID: %d\n", user->id);
    printf("Username: %s\n", user->username);
    printf("XP Level: %d\n", user->xp_level);
    printf("Achievements Count: %d\n", user->achievements_count);

    return user;
}

void display_user_info(const User *user)
{

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

void user_display_milestone_tracker(User *user, const Game *catalog, int size)
{
    if (user == NULL || catalog == NULL)
    {
        ui_error("Usuário ou catálogo inválido.");
        return;
    }

    if (size == 0)
    {
        ui_error("Catálogo vazio. Adicione jogos ao catálogo para iniciar o progresso.");
        return;
    }

    int completed_games = 0;
    int total_unlock_achivenents = 0;
    int total_possible_achivements = 0;
    int total_hours = 0;

    for (int i = 0; i < size; i++)
    {
        if (catalog[i].status_flags & FLAG_COMPLETED)
        {
            completed_games++;
        }

        total_unlock_achivenents += catalog[i].current_achievements;
        total_possible_achivements += catalog[i].total_achievements;
        total_hours += catalog[i].hours_played;
    }

    // Atualiza o perfil do usuário
    user->achievements_count = total_unlock_achivenents;
    user->xp_level = 1 + completed_games * 2 + (int)(total_hours / 10.0f);

    // Display das informações do usuário
    ui_title("MILESTONE TRACKER & PROGRESSÃO");

    printf("  %sJogador:%s %s (ID: %d)\n", COLOR_BOLD, COLOR_RESET, user->username, user->id);
    printf("  %sNível de XP:%s %d\n", COLOR_BOLD, COLOR_RESET, user->xp_level);
    printf("  %sTempo Total Dedicado:%s %d horas\n", COLOR_BOLD, COLOR_RESET, total_hours);
    printf("  %sConquistas Totais:%s %d desbloqueadas\n", COLOR_BOLD, COLOR_RESET, user->achievements_count);
    printf("%s----------------------------------------%s\n", COLOR_CYAN, COLOR_RESET);

    // Barra 1: Jogos Zerados
    float percent_games = ((float)completed_games / size) * 100.0f;
    printf("\n %sProgresso do Backlog (Jogos Concluídos: %d / %d):%s\n", COLOR_BOLD, completed_games, size, COLOR_RESET);
    ui_progress_bar(percent_games, 25);

    // Barra 2: Conquistas da Conta
    float percent_achivements = 0.0f;
    if (total_possible_achivements > 0)
    {
        percent_achivements = ((float)total_unlock_achivenents / total_possible_achivements) * 100.0f;
    }
    printf("\n %sProgresso de Conquistas (%d / %d):%s\n", COLOR_BOLD, total_unlock_achivenents, total_possible_achivements, COLOR_RESET);
    ui_progress_bar(percent_achivements, 25);

    // Conquista Mestre
    if (completed_games == size && size > 0)
    {
        printf("\n%s Conquista Mestre: Backlog 100%%%% Zerado! Parabéns!%s\n", COLOR_GREEN, COLOR_RESET);
    }
}

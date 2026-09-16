#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"

Game* game_create_catalog(int initial_capacity)
{
    Game *catalog = malloc(initial_capacity * sizeof(*catalog));

    if (catalog == NULL)
    {
        fprintf(stderr, "Erro: falha na alocacao de memoria.\n");
    }

    return catalog;
}

Game* game_resize_catalog(Game *catalog, int *capacity)
{
    int new_capacity = (*capacity) * 2;

    Game *temp = realloc(catalog, new_capacity * sizeof(*temp));

    if (temp == NULL)
    {
        fprintf(stderr, "Erro: falha na expansao de memoria.\n");
        return catalog;
    }

    *capacity = new_capacity;

    return temp;
}

void game_list_all(const Game *catalog, int size)
{
    if (size == 0)
    {
        printf("O catalogo está vazio.\n");
        return;
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            printf("=== %s ===\n", catalog[i].title );

            printf("- Gênero: %s\n", catalog[i].genre);
            printf("- Ano de Lançamento: %d\n", catalog[i].release_year);
            printf("- Preço: %f\n", catalog[i].price);
            printf("- Pontos no Metacritic: %d\n", catalog[i].metacritic_score);
            printf("- Horas jogadas: %d\n", catalog[i].hours_played);            
            printf("O jogo é multiplayer? %s\n", (catalog[i].status_flags & FLAG_MULTIPLAYER) ? "SIM" : "NÂO");
            printf("O jogo pode ser jogado em nuvem? %s\n", (catalog[i].status_flags & FLAG_CLOUD) ? "SIM" : "NÂO");
            printf("O jogo está favoritado? %s\n", (catalog[i].status_flags & FLAG_FAVORITE) ? "SIM" : "NÂO");
            printf("O jogo está instalado? %s\n", (catalog[i].status_flags & FLAG_INSTALLED) ? "SIM" : "NÂO");

        }
        
    }
    
}

int game_find_by_id(const Game *catalog, int size, int id)
{
    for (int i = 0; i < size; i++)
    {
        if(catalog[i].id == id)return i;
    }
    return -1;
}

void game_create(Game **catalog, int *size, int *capacity)
{

    if (*size == *capacity)
    {
        *catalog = game_resize_catalog(*catalog, capacity);
    }
    
    Game *new_game = &((*catalog)[*size]);

    new_game->id = *size + 1;

    new_game->hours_played = 0;

    new_game->status_flags = 0;

    // Limpa o buffer de entrada (\n)
    getchar();

    printf("Digite o nome do jogo (título): \n");

    // Lê a string para o campo title
    fgets(new_game->title, sizeof(new_game->title), stdin);

    // Retira a quebra de linha usando "strcspn"
    new_game->title[strcspn(new_game->title, "\n")] = '\0';

    printf("Digite o genero do jogo: ");
    scanf("%s", new_game->genre);
    getchar();
    
    printf("Digite o ano de lancamento do jogo: ");
    scanf("%d", &new_game->release_year);
    getchar();

    printf("Digite o preco do jogo: ");
    scanf("%f", &new_game->price);
    getchar();

    printf("Digite os pontos no Metacritic: ");
    scanf("%d", &new_game->metacritic_score);
    getchar();

    char choice;

    printf("O jogo é multiplayer? S/N: \n");

    // ** Dar um espaço antes do "%c" faz o C ignorar qualquer "\n" ou sujeira sobrando no teclado **
    scanf(" %c", &choice);

    if (choice == 'S' || choice == 's')
    {
        new_game->status_flags |= FLAG_MULTIPLAYER;
    }
    getchar();

    printf("O jogo pode ser jogado na nuvem? S/N: \n");

    scanf(" %c", &choice);

    if (choice == 'S' || choice == 's')
    {
        new_game->status_flags |= FLAG_CLOUD;
    }
    getchar();

    (*size)++;

    return;
}

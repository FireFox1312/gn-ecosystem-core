#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"
#include "ui.h"

Game *game_create_catalog(int initial_capacity)
{
    Game *catalog = malloc(initial_capacity * sizeof(*catalog));

    if (catalog == NULL)
    {
        fprintf(stderr, "Erro: falha na alocacao de memoria.\n");
    }

    return catalog;
}

Game *game_resize_catalog(Game *catalog, int *capacity)
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
            // Cabeçalho
            printf("\n%-4s | %-20s | %-12s | %-4s | %-8s | %-5s | %-10s | %-9s | %-9s | %s\n",
                   "ID", "TÍTULO", "GÊNERO", "ANO", "PREÇO", "HORAS", "METACRITIC", "STATUS", "AVALIAÇÃO", "CONQUISTAS");
            printf("------------------------------------------------------------------------------------------------------------------\n");

            for (int j = 0; j < size; j++)
            {
                // Representação da flag em caractere
                char f_mult = (catalog[j].status_flags & FLAG_MULTIPLAYER) ? 'M' : '-';
                char f_cld = (catalog[j].status_flags & FLAG_CLOUD) ? 'C' : '-';
                char f_fav = (catalog[j].status_flags & FLAG_FAVORITE) ? 'F' : '-';
                char f_inst = (catalog[j].status_flags & FLAG_INSTALLED) ? 'I' : '-';

                // O formato %-Ns alinha as strings à esquerda preenchendo com espaços até N caracteres
                printf("%-4d | %-20s | %-12s | %-4d | R$%-5.2f | %-5d | %-10d | [%c %c %c %c] | %-9.1f | %d / %d\n",
                       catalog[j].id,
                       catalog[j].title,
                       catalog[j].genre,
                       catalog[j].release_year,
                       catalog[j].price,
                       catalog[j].hours_played,
                       catalog[j].metacritic_score,
                       f_mult, f_cld, f_fav, f_inst,
                       catalog[j].user_rating,
                       catalog[j].current_achievements,
                       catalog[j].total_achievements);
            }
            printf("------------------------------------------------------------------------------------------------------------------\n");
            break; // A listagem estava repetindo o cabeçalho e os jogos N vezes (tinha um for dentro do for iterando a mesma variável 'size')
        }
    }
}

int game_find_by_id(const Game *catalog, int size, int id)
{
    for (int i = 0; i < size; i++)
    {
        if (catalog[i].id == id)
            return i;
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

    new_game->user_rating = 0;

    new_game->current_achievements = 0;

    printf("Digite a quantidade de conquistas do jogo: ");
    scanf("%d", &new_game->total_achievements);
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

void game_update(Game *catalog, int size)
{
    int id;

    printf("Digite o Id do jogo que deseja atualizar: \n");
    scanf("%d", &id);
    getchar();

    int index = game_find_by_id(catalog, size, id);

    if (index == -1)
    {
        ui_error("Jogo não encontrado!");
        return;
    }

    char buffer[100];

    Game *c = &catalog[index];

    printf("Título atual: %s\n", c->title);

    printf("Novo título (Aperte Enter caso não queira alterar): \n");
    fgets(buffer, sizeof(buffer), stdin);

    if (buffer[0] != '\n')
    {
        buffer[strcspn(buffer, "\n")] = '\0';

        strcpy(c->title, buffer);
    }

    printf("Gênero atual: %s\n", c->genre);

    printf("Novo gênero (Aperte Enter caso não queira alterar): \n");
    fgets(buffer, sizeof(buffer), stdin);

    if (buffer[0] != '\n')
    {
        buffer[strcspn(buffer, "\n")] = '\0';

        strcpy(c->genre, buffer);
    }

    printf("Ano de lançamento atual: %d\n", c->release_year);

    printf("Novo ano de lançamento (Aperte Enter caso não queira alterar): \n");
    fgets(buffer, sizeof(buffer), stdin);

    if (buffer[0] != '\n')
    {
        buffer[strcspn(buffer, "\n")] = '\0';

        sscanf(buffer, "%d", &c->release_year);
    }

    printf("Preço Atual: %f\n", c->price);

    printf("Novo preço (Aperte Enter caso não queira alterar): \n");
    fgets(buffer, sizeof(buffer), stdin);

    if (buffer[0] != '\n')
    {
        buffer[strcspn(buffer, "\n")] = '\0';

        sscanf(buffer, "%f", &c->price);
    }

    printf("Horas jogadas atualmente: %d\n", c->hours_played);

    printf("Atualização das horas jogadas (Aperte Enter caso não queira alterar): \n");
    fgets(buffer, sizeof(buffer), stdin);

    if (buffer[0] != '\n')
    {
        buffer[strcspn(buffer, "\n")] = '\0';

        sscanf(buffer, "%d", &c->hours_played);
    }

    printf("Pontos no metacritic: %d\n", c->metacritic_score);

    printf("Atualziação na prontuação do metacritic (Aperte Enter caso não queira alterar): \n");
    fgets(buffer, sizeof(buffer), stdin);

    if (buffer[0] != '\n')
    {
        buffer[strcspn(buffer, "\n")] = '\0';

        sscanf(buffer, "%d", &c->metacritic_score);
    }

    printf("Nota atual de avaliação do jogo: %f\n", c->user_rating);

    printf("Nova nota atribuída ao jogo (Aperte Enter caso não queira alterar): \n");
    fgets(buffer, sizeof(buffer), stdin);

    if (buffer[0] != '\n')
    {
        buffer[strcspn(buffer, "\n")] = '\0';

        sscanf(buffer, "%f", &c->user_rating);
    }

    printf("Quantidade máxima de conquistas do jogo: %d\n", c->total_achievements);

    printf("Nova quantidade de conquistas (Aperte Enter caso não queira alterar): \n");
    fgets(buffer, sizeof(buffer), stdin);

    if (buffer[0] != '\n')
    {
        buffer[strcspn(buffer, "\n")] = '\0';

        sscanf(buffer, "%d", &c->total_achievements);
    }

    printf("Quantidade de conquistas obtidas: %d\n", c->current_achievements);

    printf("Nova quantidade de conquistas obtidas (Aperte Enter caso não queira alterar): \n");
    fgets(buffer, sizeof(buffer), stdin);

    if (buffer[0] != '\n')
    {
        buffer[strcspn(buffer, "\n")] = '\0';

        sscanf(buffer, "%d", &c->current_achievements);
    }


    printf("--- Status atual do jogo --- \n");

    printf("Jogo multiplayer? %s\n", (c->status_flags & FLAG_MULTIPLAYER) ? "SIM" : "NÂO");
    printf("Jogo na nuvem? %s\n", (c->status_flags & FLAG_CLOUD) ? "SIM" : "NÂO");
    printf("Jogo está favoritado? %s\n", (c->status_flags & FLAG_FAVORITE) ? "SIM" : "NÂO");
    printf("Jogo está instalado? %s\n", (c->status_flags & FLAG_INSTALLED) ? "SIM" : "NÂO");

    char choice;

    printf("Você deseja alterar o status de multiplayer? S/N \n");

    scanf(" %c", &choice);

    if (choice == 'S' || choice == 's')
    {
        c->status_flags ^= FLAG_MULTIPLAYER;
    }
    getchar();

    printf("Você deseja alterar o status jogo na nuvem? S/N \n");

    scanf(" %c", &choice);

    if (choice == 'S' || choice == 's')
    {
        c->status_flags ^= FLAG_CLOUD;
    }
    getchar();

    if (c->status_flags & FLAG_FAVORITE)
    {
        printf("Você deseja desfavoritar o jogo? S/N \n");

        scanf(" %c", &choice);

        if (choice == 'S' || choice == 's')
        {
            c->status_flags ^= FLAG_FAVORITE;
        }
        getchar();
    }
    else
    {
        printf("Você deseja favoritar o jogo? S/N \n");

        scanf(" %c", &choice);

        if (choice == 'S' || choice == 's')
        {
            c->status_flags ^= FLAG_FAVORITE;
        }
        getchar();
    }

    if (c->status_flags & FLAG_INSTALLED)
    {
        printf("Você deseja desinstalar o jogo? S/N \n");

        scanf(" %c", &choice);

        if (choice == 'S' || choice == 's')
        {
            c->status_flags ^= FLAG_INSTALLED;
        }
        getchar();
    }
    else
    {
        printf("Você deseja instalar o jogo? S/N \n");

        scanf(" %c", &choice);

        if (choice == 'S' || choice == 's')
        {
            c->status_flags ^= FLAG_INSTALLED;
        }
        getchar();
    }
}

void game_delete(Game **catalog, int *size)
{
    int id;

    printf("Digite o Id do jogo que deseja deletar: \n");
    scanf("%d", &id);
    getchar();

    int index = game_find_by_id(*catalog, *size, id);

    if (index == -1)
    {
        ui_error("Jogo não encontrado!");
        return;
    }

    int elements = (*size) - index - 1;

    // Confirmação de Segurança
    char confirmation;
    printf("Voce esta prestes a DELETAR o jogo '%s'. Tem certeza? [S/N]: ", (*catalog)[index].title);
    scanf(" %c", &confirmation);

    if (confirmation != 'S' && confirmation != 's')
    {
        ui_error("Exclusao cancelada pelo usuario!");
        return;
    }

    memmove(
        &((*catalog)[index]),     // O destino
        &((*catalog)[index + 1]), // A origem de onde vai ser puxado
        elements * sizeof(Game)   // O tamanho dos jogos a serem realocado
    );

    (*size)--;

    ui_success("Jogo deletado com sucesso!\n");
}

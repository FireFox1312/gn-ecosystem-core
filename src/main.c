#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "jogo.h"

int main(void)
{
    int capacidade = 4;
    int tamanho = 0;

    Jogo *catalogo = jogo_criar_catalogo(capacidade);

    if (catalogo == NULL)
    {
        return 1;
    }
    
    catalogo[0].id = 1;
    catalogo[0].status = FLAG_INSTALADO | FLAG_ZERADO; //
    strcpy(catalogo[0].titulo, "The Legend of Zelda: Breath of the Wild");
    tamanho++;
    
    if (tamanho == capacidade)
    {
        printf("Capacidade esgotada (%d). Expandindo...\n", capacidade);
        catalogo = jogo_redimensionar_catalogo(catalogo, &capacidade);
        printf("Nova capacidade: %d\n", capacidade);
    }

    //Adicione mais 4 jogos e coloque o if de verificação para cada 1.

    catalogo[1].id = 2;
    catalogo[1].status = FLAG_INSTALADO | FLAG_FAVORITO;
    strcpy(catalogo[1].titulo, "Super Mario Odyssey");
    tamanho++;

    if (tamanho == capacidade)
    {
        printf("Capacidade esgotada (%d). Expandindo...\n", capacidade);
        catalogo = jogo_redimensionar_catalogo(catalogo, &capacidade);
        printf("Nova capacidade: %d\n", capacidade);
    }

    catalogo[2].id = 3;
    catalogo[2].status = FLAG_INSTALADO | FLAG_MULTIPLAYER;
    strcpy(catalogo[2].titulo, "Fortnite");
    tamanho++;

    if (tamanho == capacidade)
    {
        printf("Capacidade esgotada (%d). Expandindo...\n", capacidade);
        catalogo = jogo_redimensionar_catalogo(catalogo, &capacidade);
        printf("Nova capacidade: %d\n", capacidade);
    }

    catalogo[3].id = 4;
    catalogo[3].status = FLAG_INSTALADO | FLAG_NUVEM;
    strcpy(catalogo[3].titulo, "Minecraft");
    tamanho++;

    if (tamanho == capacidade)
    {
        printf("Capacidade esgotada (%d). Expandindo...\n", capacidade);
        catalogo = jogo_redimensionar_catalogo(catalogo, &capacidade);
        printf("Nova capacidade: %d\n", capacidade);
    }

    catalogo[4].id = 5;
    catalogo[4].status = FLAG_INSTALADO | FLAG_ZERADO | FLAG_FAVORITO;
    strcpy(catalogo[4].titulo, "The Witcher 3: Wild Hunt");
    tamanho++;

    if (tamanho == capacidade)
    {
        printf("Capacidade esgotada (%d). Expandindo...\n", capacidade);
        catalogo = jogo_redimensionar_catalogo(catalogo, &capacidade);
        printf("Nova capacidade: %d\n", capacidade);
    }

    for (int i = 0; i < tamanho; i++)
    {
        printf("Jogo %d: %s\n", catalogo[i].id, catalogo[i].titulo);
    }

    free(catalogo);

    return 0;
}

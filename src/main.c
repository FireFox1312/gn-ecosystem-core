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
    strcpy(catalogo[0].genero, "Ação/Aventura");
    catalogo[0].ano_lancamento = 2017;
    catalogo[0].preco = 59.99;
    tamanho++;

    for (int i = 0; i < tamanho; i++)
    {
        printf("Jogo %d: %s\n", catalogo[i].id, catalogo[i].titulo);
    }

    free(catalogo);

    return 0;
}

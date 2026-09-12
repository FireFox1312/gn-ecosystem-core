#include <stdio.h>
#include <stdlib.h>
#include "jogo.h"

Jogo* jogo_criar_catalogo(int capacidade_inicial){

    Jogo *pJogo = malloc(capacidade_inicial * sizeof(*pJogo) ) ;

    if (pJogo == NULL)
    {
        fprintf(stderr, "Erro: falha na alocacao de memoria.\n");
    }

    return pJogo;

}

void cadastrarJogo(Jogo *jogo)
{
    // Leitura dos dados
    printf("Digite o ID do jogo: ");
    scanf("%d", &jogo->id);

    printf("Digite o nome do jogo: ");
    scanf("%s", jogo->titulo);

    printf("Digite o gênero do jogo: ");
    scanf("%s", jogo->genero);

    printf("Digite o preço do jogo: ");
    scanf("%f", &jogo->preco);

    return;
}

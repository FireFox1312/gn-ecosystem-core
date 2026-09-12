// Guardas de cabeçalho para evitar múltiplas inclusões do arquivo

#ifndef JOGO_H
#define JOGO_H

#include <stdint.h>

#define FLAG_INSTALADO (1 << 0)   // 0000 0001
#define FLAG_ZERADO (1 << 1)      // 0000 0010
#define FLAG_FAVORITO (1 << 2)    // 0000 0100
#define FLAG_MULTIPLAYER (1 << 3) // 0000 1000
#define FLAG_NUVEM (1 << 4)       // 0001 0000

typedef struct
{
    int id;
    uint8_t status; // status do jogo compactado
    char titulo[100];
    char genero[50];
    int ano_lancamento;
    float preco;
    int horas_jogadas;
    int nota_metacritic;
} Jogo;

// Assinatura da função para criar um catálogo de jogos
Jogo* jogo_criar_catalogo(int capacidade_inicial);

// Assinatura da função para cadastrar um jogo
void cadastrarJogo(Jogo *jogo);

#endif // JOGO_H

#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

#define TAM 10
#define NAVIO 3

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    int tabuleiro[TAM][TAM]; // Matriz do tabuleiro
    int navio1[NAVIO] = {3, 3, 3}; // Navio horizontal
    int navio2[NAVIO] = {3, 3, 3}; // Navio vertical

    // Inicializar o tabuleiro com água (0)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Posicionar o navio1 horizontalmente (linha 2, colunas 3 a 5)
    int linha1 = 2, coluna1 = 3;
    for (int i = 0; i < NAVIO; i++) {
        tabuleiro[linha1][coluna1 + i] = navio1[i];
    }

    // Posicionar o navio2 verticalmente (coluna 6, linhas 5 a 7)
    int linha2 = 5, coluna2 = 6;
    for (int i = 0; i < NAVIO; i++) {
        tabuleiro[linha2 + i][coluna2] = navio2[i];
    }

    // Exibir o tabuleiro
    printf("=== Tabuleiro Batalha Naval ===\n\n");
    printf("   ");
    for (int j = 0; j < TAM; j++) {
        printf("%2d ", j);
    }
    printf("\n");

    for (int i = 0; i < TAM; i++) {
        printf("%2d ", i); // Índice da linha
        for (int j = 0; j < TAM; j++) {
            printf(" %d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}

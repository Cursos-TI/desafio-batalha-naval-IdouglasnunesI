#include <stdio.h>
#define TAM 10
#define NAVIO_TAM 3
#define NAVIO_VALOR 3
#define HABILIDADE_VALOR 5
int main() {

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.



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



// Verifica se pode posicionar o navio
int podePosicionar(int tabuleiro[TAM][TAM], int linha, int coluna, int dx, int dy) {
    for (int i = 0; i < NAVIO_TAM; i++) {
        int x = linha + dx * i;
        int y = coluna + dy * i;
        if (x < 0 || x >= TAM || y < 0 || y >= TAM || tabuleiro[x][y] != 0)
            return 0;
    }
    return 1;
}

// Posiciona o navio
void posicionarNavio(int tabuleiro[TAM][TAM], int linha, int coluna, int dx, int dy) {
    for (int i = 0; i < NAVIO_TAM; i++) {
        tabuleiro[linha + dx * i][coluna + dy * i] = NAVIO_VALOR;
    }
}

// Aplica habilidade no tabuleiro com base em uma matriz de forma
void aplicarHabilidade(int tabuleiro[TAM][TAM], int forma[7][7], int tam_forma, int origem_linha, int origem_coluna) {
    int centro = tam_forma / 2;
    for (int i = 0; i < tam_forma; i++) {
        for (int j = 0; j < tam_forma; j++) {
            if (forma[i][j] == 1) {
                int x = origem_linha + (i - centro);
                int y = origem_coluna + (j - centro);
                if (x >= 0 && x < TAM && y >= 0 && y < TAM && tabuleiro[x][y] != NAVIO_VALOR) {
                    tabuleiro[x][y] = HABILIDADE_VALOR;
                }
            }
        }
    }
}

// Gera matriz de cone (7x7)
void gerarCone(int forma[7][7]) {
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            forma[i][j] = 0;
            if (i >= 0 && i < 4) {
                int centro = 3;
                if (j >= centro - i && j <= centro + i)
                    forma[i][j] = 1;
            }
        }
    }
}

// Gera matriz de cruz (7x7)
void gerarCruz(int forma[7][7]) {
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            forma[i][j] = (i == 3 || j == 3) ? 1 : 0;
        }
    }
}

// Gera matriz de octaedro (losango) (7x7)
void gerarOctaedro(int forma[7][7]) {
    int centro = 3;
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            forma[i][j] = (abs(i - centro) + abs(j - centro) <= 3) ? 1 : 0;
        }
    }
}

// Exibe o tabuleiro
void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\n=== TABULEIRO ===\n\n   ");
    for (int j = 0; j < TAM; j++)
        printf("%2d ", j);
    printf("\n");

    for (int i = 0; i < TAM; i++) {
        printf("%2d ", i);
        for (int j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] == 0)
                printf(" ~ ");
            else if (tabuleiro[i][j] == NAVIO_VALOR)
                printf(" # ");
            else if (tabuleiro[i][j] == HABILIDADE_VALOR)
                printf(" * ");
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM][TAM] = {0};

    // Posiciona 4 navios
    if (podePosicionar(tabuleiro, 2, 1, 0, 1))
        posicionarNavio(tabuleiro, 2, 1, 0, 1); // Horizontal

    if (podePosicionar(tabuleiro, 4, 5, 1, 0))
        posicionarNavio(tabuleiro, 4, 5, 1, 0); // Vertical

    if (podePosicionar(tabuleiro, 0, 0, 1, 1))
        posicionarNavio(tabuleiro, 0, 0, 1, 1); // Diagonal principal

    if (podePosicionar(tabuleiro, 0, 9, 1, -1))
        posicionarNavio(tabuleiro, 0, 9, 1, -1); // Diagonal secundária

    // Habilidades (7x7)
    int cone[7][7], cruz[7][7], octaedro[7][7];

    gerarCone(cone);
    gerarCruz(cruz);
    gerarOctaedro(octaedro);

    // Aplicar habilidades em posições específicas
    aplicarHabilidade(tabuleiro, cone, 7, 6, 2);       // Cone centrado em (6,2)
    aplicarHabilidade(tabuleiro, cruz, 7, 5, 5);       // Cruz centrado em (5,5)
    aplicarHabilidade(tabuleiro, octaedro, 7, 3, 7);   // Octaedro centrado em (3,7)

    // Mostrar o tabuleiro
    exibirTabuleiro(tabuleiro);

    return 0;
}

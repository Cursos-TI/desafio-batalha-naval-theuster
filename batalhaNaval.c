#include <stdio.h>

// Tamanho do tabuleiro
#define TAM 10

int main() {
    int tabuleiro[TAM][TAM];
    int i, j;

    // Inicializa o tabuleiro com 0 (água)
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // ===============================
    // Posiciona o navio horizontal
    // ===============================
    int linhaH = 2;
    int colunaH = 4;

    if (colunaH + 2 < TAM &&
        tabuleiro[linhaH][colunaH] == 0 &&
        tabuleiro[linhaH][colunaH + 1] == 0 &&
        tabuleiro[linhaH][colunaH + 2] == 0) {

        tabuleiro[linhaH][colunaH] = 3;
        tabuleiro[linhaH][colunaH + 1] = 3;
        tabuleiro[linhaH][colunaH + 2] = 3;
    }

    // ===============================
    // Posiciona o navio vertical
    // ===============================
    int linhaV = 5;
    int colunaV = 1;

    if (linhaV + 2 < TAM &&
        tabuleiro[linhaV][colunaV] == 0 &&
        tabuleiro[linhaV + 1][colunaV] == 0 &&
        tabuleiro[linhaV + 2][colunaV] == 0) {

        tabuleiro[linhaV][colunaV] = 3;
        tabuleiro[linhaV + 1][colunaV] = 3;
        tabuleiro[linhaV + 2][colunaV] = 3;
    }

    // ===============================
    // Posiciona o navio diagonal principal
    // ===============================
    int linhaD1 = 0;
    int colunaD1 = 0;

    if (linhaD1 + 2 < TAM && colunaD1 + 2 < TAM &&
        tabuleiro[linhaD1][colunaD1] == 0 &&
        tabuleiro[linhaD1 + 1][colunaD1 + 1] == 0 &&
        tabuleiro[linhaD1 + 2][colunaD1 + 2] == 0) {

        tabuleiro[linhaD1][colunaD1] = 3;
        tabuleiro[linhaD1 + 1][colunaD1 + 1] = 3;
        tabuleiro[linhaD1 + 2][colunaD1 + 2] = 3;
    }

    // ===============================
    // Posiciona o navio diagonal secundária
    // ===============================
    int linhaD2 = 0;
    int colunaD2 = 9;

    if (linhaD2 + 2 < TAM && colunaD2 - 2 >= 0 &&
        tabuleiro[linhaD2][colunaD2] == 0 &&
        tabuleiro[linhaD2 + 1][colunaD2 - 1] == 0 &&
        tabuleiro[linhaD2 + 2][colunaD2 - 2] == 0) {

        tabuleiro[linhaD2][colunaD2] = 3;
        tabuleiro[linhaD2 + 1][colunaD2 - 1] = 3;
        tabuleiro[linhaD2 + 2][colunaD2 - 2] = 3;
    }

    // ===============================
    // Imprime o título e cabeçalho
    // ===============================
    printf("\n====== BATALHA NAVAL ======\n\n");

    // Letras do topo (A a J)
    printf("   ");
    for (j = 0; j < TAM; j++) {
        printf(" %c", 'A' + j);
    }
    printf("\n");

    // Tabuleiro com números na lateral
    for (i = 0; i < TAM; i++) {
        printf("%2d ", i + 1); // Números de 1 a 10
        for (j = 0; j < TAM; j++) {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}

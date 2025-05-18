#include <stdio.h>

int main() {
    int tabuleiro[10][10];
    int i, j;

    // Inicializa o tabuleiro com 0 (água)
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Posiciona o navio horizontal
    int linhaH = 2;
    int colunaH = 4;
    if (colunaH + 2 < 10) {
        tabuleiro[linhaH][colunaH] = 3;
        tabuleiro[linhaH][colunaH + 1] = 3;
        tabuleiro[linhaH][colunaH + 2] = 3;
    }

    // Posiciona o navio vertical
    int linhaV = 5;
    int colunaV = 1;
    if (linhaV + 2 < 10 &&
        tabuleiro[linhaV][colunaV] == 0 &&
        tabuleiro[linhaV + 1][colunaV] == 0 &&
        tabuleiro[linhaV + 2][colunaV] == 0) {

        tabuleiro[linhaV][colunaV] = 3;
        tabuleiro[linhaV + 1][colunaV] = 3;
        tabuleiro[linhaV + 2][colunaV] = 3;
    }

    // Exibe o título do jogo
    printf("\n====== BATALHA NAVAL ======\n\n");

    // Imprime letras no topo (A–J)
    printf("   ");
    for (j = 0; j < 10; j++) {
        printf(" %c", 'A' + j);
    }
    printf("\n");

    // Imprime o tabuleiro com números na lateral
    for (i = 0; i < 10; i++) {
        printf("%2d ", i + 1); // Números de 1 a 10 na lateral
        for (j = 0; j < 10; j++) {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}

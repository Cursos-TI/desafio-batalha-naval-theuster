#include <stdio.h>

#define TAM 10
#define TAM_HAB 5

// Função para gerar matriz de habilidade em formato de cone
void gerarCone(int matriz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (j >= (TAM_HAB / 2 - i) && j <= (TAM_HAB / 2 + i))
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Função para gerar matriz de habilidade em formato de cruz
void gerarCruz(int matriz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i == TAM_HAB / 2 || j == TAM_HAB / 2)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Função para gerar matriz de habilidade em formato de octaedro (losango)
void gerarOctaedro(int matriz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (abs(i - TAM_HAB / 2) + abs(j - TAM_HAB / 2) <= TAM_HAB / 2)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Função para aplicar matriz de habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[TAM_HAB][TAM_HAB], int origemLinha, int origemColuna) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int linhaTabuleiro = origemLinha - TAM_HAB / 2 + i;
            int colunaTabuleiro = origemColuna - TAM_HAB / 2 + j;

            if (linhaTabuleiro >= 0 && linhaTabuleiro < TAM &&
                colunaTabuleiro >= 0 && colunaTabuleiro < TAM &&
                habilidade[i][j] == 1 &&
                tabuleiro[linhaTabuleiro][colunaTabuleiro] == 0) {
                tabuleiro[linhaTabuleiro][colunaTabuleiro] = 5;
            }
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM];
    int i, j;

    // Inicializa o tabuleiro com 0 (água)
    for (i = 0; i < TAM; i++)
        for (j = 0; j < TAM; j++)
            tabuleiro[i][j] = 0;

    // Posiciona alguns navios
    tabuleiro[2][4] = tabuleiro[2][5] = tabuleiro[2][6] = 3; // horizontal
    tabuleiro[5][1] = tabuleiro[6][1] = tabuleiro[7][1] = 3; // vertical
    tabuleiro[0][0] = tabuleiro[1][1] = tabuleiro[2][2] = 3; // diagonal principal
    tabuleiro[0][9] = tabuleiro[1][8] = tabuleiro[2][7] = 3; // diagonal secundária

    // Cria matrizes de habilidades
    int cone[TAM_HAB][TAM_HAB], cruz[TAM_HAB][TAM_HAB], octaedro[TAM_HAB][TAM_HAB];
    gerarCone(cone);
    gerarCruz(cruz);
    gerarOctaedro(octaedro);

    // Aplica as habilidades no tabuleiro
    aplicarHabilidade(tabuleiro, cone, 5, 5);      // Cone com centro em (5,5)
    aplicarHabilidade(tabuleiro, cruz, 2, 2);      // Cruz com centro em (2,2)
    aplicarHabilidade(tabuleiro, octaedro, 7, 7);  // Octaedro com centro em (7,7)

    // Imprime cabeçalho
    printf("\n====== BATALHA NAVAL ======\n\n   ");
    for (j = 0; j < TAM; j++) printf(" %c", 'A' + j);
    printf("\n");

    // Imprime tabuleiro com linhas numeradas
    for (i = 0; i < TAM; i++) {
        printf("%2d ", i + 1);
        for (j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] == 0) printf(" ~");          // água
            else if (tabuleiro[i][j] == 3) printf(" N");      // navio
            else if (tabuleiro[i][j] == 5) printf(" *");      // área afetada
        }
        printf("\n");
    }

    return 0;
}

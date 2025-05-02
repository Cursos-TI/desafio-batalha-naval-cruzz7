#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO_TABULEIRO 10

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int navio1[3] = {3, 3, 3}; // Navio horizontal de tamanho 3
    int navio2[3] = {3, 3, 3}; // Navio vertical de tamanho 3
    int linha_navio1, coluna_navio1, linha_navio2, coluna_navio2;
    int i, j;
    int orientacao1, orientacao2; // 0 para horizontal, 1 para vertical

    // Inicializa o gerador de números aleatórios
    srand(time(NULL));

    // Inicializa o tabuleiro com água (0)
    for (i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Posiciona o navio 1 (horizontal ou vertical aleatório)
    orientacao1 = rand() % 2;
    linha_navio1 = rand() % TAMANHO_TABULEIRO;
    coluna_navio1 = rand() % TAMANHO_TABULEIRO;

    if (orientacao1 == 0) { // Horizontal
        if (coluna_navio1 + 3 <= TAMANHO_TABULEIRO) {
            for (i = 0; i < 3; i++) {
                tabuleiro[linha_navio1][coluna_navio1 + i] = navio1[i];
            }
        } else {
             // Tenta novamente com coluna válida
            coluna_navio1 = TAMANHO_TABULEIRO - 3;
            for (i = 0; i < 3; i++) {
                tabuleiro[linha_navio1][coluna_navio1 + i] = navio1[i];
            }
        }
    } else { // Vertical
        if (linha_navio1 + 3 <= TAMANHO_TABULEIRO) {
            for (i = 0; i < 3; i++) {
                tabuleiro[linha_navio1 + i][coluna_navio1] = navio1[i];
            }
        } else {
            // Tenta novamente com linha válida
             linha_navio1 = TAMANHO_TABULEIRO - 3;
             for (i = 0; i < 3; i++) {
                tabuleiro[linha_navio1 + i][coluna_navio1] = navio1[i];
            }
        }
    }


    // Posiciona o navio 2 (horizontal ou vertical aleatório)
    orientacao2 = rand() % 2;
    linha_navio2 = rand() % TAMANHO_TABULEIRO;
    coluna_navio2 = rand() % TAMANHO_TABULEIRO;
     int tentativas = 0;
    while (tentativas < 1000) { // Limita as tentativas para evitar loop infinito
        tentativas++;
        int valido = 1; // Assume que a posição é válida inicialmente

        if (orientacao2 == 0) { // Horizontal
            if (coluna_navio2 + 3 > TAMANHO_TABULEIRO) {
                valido = 0; // Navio excede o tabuleiro
            } else {
                for (i = 0; i < 3; i++) {
                    if (tabuleiro[linha_navio2][coluna_navio2 + i] != 0) {
                        valido = 0; // Posição ocupada
                        break;
                    }
                }
            }
        } else { // Vertical
            if (linha_navio2 + 3 > TAMANHO_TABULEIRO) {
                valido = 0; // Navio excede o tabuleiro
            } else {
                for (i = 0; i < 3; i++) {
                    if (tabuleiro[linha_navio2 + i][coluna_navio2] != 0) {
                        valido = 0; // Posição ocupada
                        break;
                    }
                }
            }
        }

        if (valido) {
            break; // Posição válida encontrada, sai do loop
        } else {
            // Gera novas coordenadas e orientação para tentar novamente
            linha_navio2 = rand() % TAMANHO_TABULEIRO;
            coluna_navio2 = rand() % TAMANHO_TABULEIRO;
            orientacao2 = rand() % 2;
        }
    }
      if (tentativas >= 1000) {
        printf("Erro: Não foi possível posicionar o segundo navio após muitas tentativas.\n");
        return 1;
    }

    // Posiciona o navio 2
     if (orientacao2 == 0) { // Horizontal
        for (i = 0; i < 3; i++) {
            tabuleiro[linha_navio2][coluna_navio2 + i] = navio2[i];
        }
    } else {
        for (i = 0; i < 3; i++) {
            tabuleiro[linha_navio2 + i][coluna_navio2] = navio2[i];
        }
    }


    // Exibe o tabuleiro
    printf("Tabuleiro:\n");
    for (i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}

#include <stdio.h>

void movimento_torre() {
    int i;

    // Movimento vertical para cima
    printf("Movimento da Torre (Vertical para cima):\n");
    for(i = 1; i <= 8; i++) {
        printf("Casa %d, %d\n", i, 1);
    }

    // Movimento vertical para baixo
    printf("\nMovimento da Torre (Vertical para baixo):\n");
    for(i = 8; i >= 1; i--) {
        printf("Casa %d, %d\n", i, 1);
    }

    // Movimento horizontal para a direita
    printf("\nMovimento da Torre (Horizontal para direita):\n");
    for(i = 1; i <= 8; i++) {
        printf("Casa %d, %d\n", 1, i);
    }

    // Movimento horizontal para a esquerda
    printf("\nMovimento da Torre (Horizontal para esquerda):\n");
    for(i = 8; i >= 1; i--) {
        printf("Casa %d, %d\n", 1, i);
    }
}

void movimento_bispo() {
    int i = 1;

    // Movimento diagonal para cima e direita
    printf("Movimento do Bispo (Diagonal para cima e direita):\n");
    while(i <= 8) {
        printf("Casa %d, %d\n", i, i);
        i++;
    }

    i = 1;
    // Movimento diagonal para baixo e direita
    printf("\nMovimento do Bispo (Diagonal para baixo e direita):\n");
    while(i <= 8) {
        printf("Casa %d, %d\n", 9 - i, i);
        i++;
    }
}

void movimento_rainha() {
    int i = 1;

    // Movimento horizontal para a direita
    printf("Movimento da Rainha (Horizontal para direita):\n");
    do {
        printf("Casa %d, %d\n", 1, i);
        i++;
    } while(i <= 8);

    i = 1;

    // Movimento vertical para cima
    printf("\nMovimento da Rainha (Vertical para cima):\n");
    do {
        printf("Casa %d, %d\n", i, 1);
        i++;
    } while(i <= 8);

    i = 1;

    // Movimento diagonal para cima e direita
    printf("\nMovimento da Rainha (Diagonal para cima e direita):\n");
    do {
        printf("Casa %d, %d\n", i, i);
        i++;
    } while(i <= 8);

    i = 1;

    // Movimento diagonal para baixo e direita
    printf("\nMovimento da Rainha (Diagonal para baixo e direita):\n");
    do {
        printf("Casa %d, %d\n", 9 - i, i);
        i++;
    } while(i <= 8);
}

int main() {
    printf("Simulação do movimento das peças de xadrez:\n\n");

    movimento_torre();
    movimento_bispo();
    movimento_rainha();

    return 0;
}

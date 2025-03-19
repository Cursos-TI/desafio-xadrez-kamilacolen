#include <stdio.h>

#define TAM 8

// Função Recursiva para o movimento da Torre
void movimentoTorre(int x, int y, int direcao, int tabuleiro[TAM][TAM]) {
    if (x < 0 || x >= TAM || y < 0 || y >= TAM || tabuleiro[x][y] == 1)
        return;
    
    // Marca a posição atual como ocupada
    tabuleiro[x][y] = 1;
    printf("Torre em: (%d, %d)\n", x, y);

    if (direcao == 0) { // Movendo para a direita
        movimentoTorre(x, y + 1, direcao, tabuleiro);
    } else if (direcao == 1) { // Movendo para baixo
        movimentoTorre(x + 1, y, direcao, tabuleiro);
    } else if (direcao == 2) { // Movendo para a esquerda
        movimentoTorre(x, y - 1, direcao, tabuleiro);
    } else if (direcao == 3) { // Movendo para cima
        movimentoTorre(x - 1, y, direcao, tabuleiro);
    }
}

// Função Recursiva para o movimento do Bispo com Loops Aninhados
void movimentoBispo(int x, int y, int direcaoX, int direcaoY, int tabuleiro[TAM][TAM]) {
    if (x < 0 || x >= TAM || y < 0 || y >= TAM || tabuleiro[x][y] == 1)
        return;
    
    // Marca a posição atual como ocupada
    tabuleiro[x][y] = 1;
    printf("Bispo em: (%d, %d)\n", x, y);

    movimentoBispo(x + direcaoX, y + direcaoY, direcaoX, direcaoY, tabuleiro);
}

// Função Recursiva para o movimento da Rainha (combinando Torre e Bispo)
void movimentoRainha(int x, int y, int direcaoX, int direcaoY, int tabuleiro[TAM][TAM]) {
    if (x < 0 || x >= TAM || y < 0 || y >= TAM || tabuleiro[x][y] == 1)
        return;

    // Marca a posição atual como ocupada
    tabuleiro[x][y] = 1;
    printf("Rainha em: (%d, %d)\n", x, y);

    // Movimentos verticais e horizontais (Torre)
    if (direcaoX == 0) {
        movimentoRainha(x, y + 1, direcaoX, direcaoY, tabuleiro);
    } else if (direcaoY == 0) {
        movimentoRainha(x + 1, y, direcaoX, direcaoY, tabuleiro);
    }

    // Movimentos diagonais (Bispo)
    movimentoRainha(x + direcaoX, y + direcaoY, direcaoX, direcaoY, tabuleiro);
}

// Função para o movimento do Cavalo utilizando Loops Aninhados
void movimentoCavalo(int x, int y, int tabuleiro[TAM][TAM]) {
    int i, j;
    int movimentos[8][2] = {
        {-2, 1}, {-1, 2}, {1, 2}, {2, 1},
        {2, -1}, {1, -2}, {-1, -2}, {-2, -1}
    };
    
    // Loop aninhado para controlar os 8 movimentos possíveis do Cavalo
    for (i = 0; i < 8; i++) {
        int novoX = x + movimentos[i][0];
        int novoY = y + movimentos[i][1];
        
        if (novoX >= 0 && novoX < TAM && novoY >= 0 && novoY < TAM) {
            printf("Cavalo em: (%d, %d)\n", novoX, novoY);
            tabuleiro[novoX][novoY] = 1;
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM] = {0};
    int x = 0, y = 0;

    printf("Movimentos da Torre (direção 1: baixo, 2: esquerda, 3: cima, 4: direita):\n");
    movimentoTorre(x, y, 1, tabuleiro); // Direção 1: baixo
    
    printf("\nMovimentos do Bispo (direção diagonal 1):\n");
    movimentoBispo(x, y, 1, 1, tabuleiro); // Direção 1,1 para diagonal
    
    printf("\nMovimentos da Rainha (direção 1: baixo, 2: direita):\n");
    movimentoRainha(x, y, 0, 1, tabuleiro); // Movimento para a direita
    
    printf("\nMovimentos do Cavalo:\n");
    movimentoCavalo(x, y, tabuleiro);
    
    return 0;
}


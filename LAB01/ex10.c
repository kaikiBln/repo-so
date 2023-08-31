#include <stdio.h>

void multiplicar_linha(int matriz[][100], int n, int linha, int numero) {
    int j;

    if (linha <= n) {
        for (j = 0; j < n; j++) {
            matriz[linha-1][j] *= numero;
        }
    }
}

void multiplicar_coluna(int matriz[][100], int n, int coluna, int numero) {
    int i;

    if (coluna <= n) {
        for (i = 0; i < n; i++) {
            matriz[i][coluna-1] *= numero;
        }
    }
}

int main() {
    int matriz[100][100];
    int n, i, j, linha, coluna, numero;

    printf("ordem da matriz: ");
    scanf("%d", &n);

    printf("elementos da matriz:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("nmero a ser multiplicado: ");
    scanf("%d", &numero);

    printf("numero da linha ou coluna a ser multiplicada: ");
    scanf("%d", &linha);

    multiplicar_linha(matriz, n, linha, numero);

    printf("Matriz resultante da multiplicação da linha:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("numero da coluna a ser multiplicada: ");
    scanf("%d", &coluna);

    multiplicar_coluna(matriz, n, coluna, numero);

    printf("Matriz resultante da multiplicação da coluna:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}

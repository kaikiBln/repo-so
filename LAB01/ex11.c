#include <stdio.h>

void somar_linhas(int matriz[][100], int n, int l1, int l2) {
    int j;

    if (l1 <= n && l2 <= n) {
        for (j = 0; j < n; j++) {
            matriz[l2-1][j] += matriz[l1-1][j];
        }
    }
}

void multiplicar_linhas(int matriz[][100], int n, int l1, int l2) {
    int j;

    if (l1 <= n && l2 <= n) {
        for (j = 0; j < n; j++) {
            matriz[l2-1][j] *= matriz[l1-1][j];
        }
    }
}

int main() {
    int matriz[100][100];
    int n, i, j, l1, l2;

    printf("Digite a ordem da matriz: ");
    scanf("%d", &n);

    printf("Digite os elementos da matriz:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("Numero das linhas a serem somadas e multiplicadas: ");
    scanf("%d %d", &l1, &l2);

    somar_linhas(matriz, n, l1, l2);

    printf("Matriz resultante da soma das linhas:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    multiplicar_linhas(matriz, n, l1, l2);

    printf("Matriz resultante da multiplicação das linhas:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}

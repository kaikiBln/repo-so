#include <stdio.h>

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

    printf("numero a ser multiplicado: ");
    scanf("%d", &numero);

    printf("linha ou coluna a ser multiplicada: ");
    scanf("%d", &linha);

    if (linha <= n) {
        for (j = 0; j < n; j++) {
            matriz[linha-1][j] *= numero;
        }
    } else {
        coluna = linha - n;
        for (i = 0; i < n; i++) {
            matriz[i][coluna-1] *= numero;
        }
    }

    printf("Matriz resultante:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}

#include <stdio.h>

void substituir_negativos(int matriz[][100], int n) {
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (matriz[i][j] < 0) {
                matriz[i][j] = -matriz[i][j];
            }
        }
    }

    printf("Matriz resultante:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matriz[100][100];
    int n, i, j;

    printf("ordem da matriz: ");
    scanf("%d", &n);

    printf("elementos da matriz:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    substituir_negativos(matriz, n);

    return 0;
}

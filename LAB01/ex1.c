#include <stdio.h>

int main() {
    int matriz[100][100];
    int n, i, j, menor, linha_menor;

    printf("Ordem da matriz: ");
    scanf("%d", &n);

    printf("Elementos da matriz:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    menor = matriz[0][0];
    linha_menor = 0;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (matriz[i][j] < menor) {
                menor = matriz[i][j];
                linha_menor = i;
            }
        }
    }

    printf("Menor num: %d\n", linha_menor + 1);

    return 0;
}

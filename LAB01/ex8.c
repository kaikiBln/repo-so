#include <stdio.h>

void transposta(int matriz[][100], int n) {
    int transposta[100][100];
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            transposta[j][i] = matriz[i][j];
        }
    }

    printf("Matriz transposta:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", transposta[i][j]);
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

    transposta(matriz, n);

    return 0;
}

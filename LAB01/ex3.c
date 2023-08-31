#include <stdio.h>

int main() {
    int num, i, j, k;

    printf("Maior numero (deve ser impar): ");
    scanf("%d", &num);

    for (i = 1; i <= num; i++) {
        for (k = 1; k < i; k++) {
            printf("   ");
        }
        for (j = i; j <= num; j++) {
            printf("%2d ", j);
        }
        printf("\n");
    }

    return 0;
}

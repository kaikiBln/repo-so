#include <stdio.h>

int main() {
    float n1, n2, n3, me, ma;

    printf("3 notas do aluno: ");
    scanf("%f %f %f", &n1, &n2, &n3);

    printf("Media dos ex: ");
    scanf("%f", &me);

    ma = (n1 + n2*2 + n3*3 + me) / 7;

    printf("Media de aproveitamento: %.2f\n", ma);

    if (ma >= 9) {
        printf("Conceito: A\n");
    } else if (ma >= 7.5) {
        printf("Conceito: B\n");
    } else if (ma >= 6) {
        printf("Conceito: C\n");
    } else if (ma >= 4) {
        printf("Conceito: D\n");
    } else {
        printf("Conceito: E\n");
    }

    return 0;
}

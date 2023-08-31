#include <stdio.h>
#include <string.h>

void remover_caractere(char str[], int posicao) {
    int i;

    for (i = posicao; i < strlen(str) - 1; i++) {
        str[i] = str[i+1];
    }

    str[strlen(str) - 1] = '\0';
}

int main() {
    char str[100];
    int posicao;

    printf("sigite uma string: ");
    scanf("%s", str);

    printf("posicao do caractere a ser removido: ");
    scanf("%d", &posicao);

    remover_caractere(str, posicao);

    printf("string resultante: %s\n", str);

    return 0;
}

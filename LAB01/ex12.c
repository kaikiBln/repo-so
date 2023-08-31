#include <stdio.h>
#include <string.h>

int encontrar_posicao(char str[], char c) {
    int i;

    for (i = 0; i < strlen(str); i++) {
        if (str[i] == c) {
            return i;
        }
    }

    return -1;
}

int main() {
    char str[100];
    char c;

    printf("Digite uma string: ");
    scanf("%s", str);

    printf("Digite o caractere a ser encontrado: ");
    scanf(" %c", &c);

    int posicao = encontrar_posicao(str, c);

    if (posicao != -1) {
        printf("O caractere '%c' está na posição %d da string.\n", c, posicao);
    } else {
        printf("O caractere '%c' não foi encontrado na string.\n", c);
    }

    return 0;
}

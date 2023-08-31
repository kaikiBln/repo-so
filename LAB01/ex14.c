#include <stdio.h>
#include <string.h>

void inserir_caractere(char str[], int posicao, char c) {
    int i;

    for (i = strlen(str); i > posicao; i--) {
        str[i] = str[i-1];
    }

    str[posicao] = c;
}

int main() {
    char str[100];
    int posicao;
    char c;

    printf("digite uma string: ");
    scanf("%s", str);

    printf("digite a posição para inserir o caractere: ");
    scanf("%d", &posicao);

    printf("digite o caractere a ser inserido: ");
    scanf(" %c", &c);

    inserir_caractere(str, posicao, c);

    printf("string resultante: %s\n", str);

    return 0;
}

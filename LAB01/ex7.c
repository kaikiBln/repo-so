#include <stdio.h>

struct Pessoa {
    char nome[100];
    int idade;
    float peso;
    float altura;
};

int main() {
    struct Pessoa pessoas[3];
    int i;

    for (i = 0; i < 3; i++) {
        printf("nome da pessoa %d: ", i+1);
        scanf("%s", pessoas[i].nome);

        printf("idade da pessoa %d: ", i+1);
        scanf("%d", &pessoas[i].idade);

        printf("peso da pessoa %d: ", i+1);
        scanf("%f", &pessoas[i].peso);

        printf("altura da pessoa %d: ", i+1);
        scanf("%f", &pessoas[i].altura);
    }

    printf("Dados das pessoas:\n");
    for (i = 0; i < 3; i++) {
        printf("Pessoa %d:\n", i+1);
        printf("Nome: %s\n", pessoas[i].nome);
        printf("Idade: %d\n", pessoas[i].idade);
        printf("Peso: %.2f\n", pessoas[i].peso);
        printf("Altura: %.2f\n", pessoas[i].altura);
        printf("\n");
    }

    return 0;
}

// Código em C
#include <stdio.h>
#include <string.h>

int main() {
    char nome1[100], nome2[100];

    printf("Digite o primeiro nome: ");
    scanf("%s", nome1);

    printf("Digite o segundo nome: ");
    scanf("%s", nome2);

    if (strcmp(nome1, nome2) < 0) {
        printf("%s\n%s\n", nome1, nome2);
    } else {
        printf("%s\n%s\n", nome2, nome1);
    }

    return 0;
}

// Código em C++
#include <iostream>
#include <string>

int main() {
    std::string nome1, nome2;

    std::cout << "Digite o primeiro nome: ";
    std::cin >> nome1;

    std::cout << "Digite o segundo nome: ";
    std::cin >> nome2;

    if (nome1 < nome2) {
        std::cout << nome1 << std::endl << nome2 << std::endl;
    } else {
        std::cout << nome2 << std::endl << nome1 << std::endl;
    }

    return 0;
}

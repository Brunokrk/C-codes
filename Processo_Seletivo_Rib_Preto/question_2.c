//Questão 2
#include <stdio.h>

int main() {
    int num, a = 0, b = 1, temp = 0;
    int found = 0; 

    printf("Informe um número: ");
    scanf("%d", &num);

    if (num == a || num == b) {
        found = 1;
    }
    while (b <= num) {
        temp = b;
        b = a + b;
        a = temp;

        if (b == num) {
            found = 1;
            break;
        }
    }

    if (found) {
        printf("O número %d pertence à sequência de Fibonacci.\n", num);
    } else {
        printf("O número %d não pertence à sequência de Fibonacci.\n", num);
    }

    return 0;
}
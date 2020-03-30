#include <stdio.h>
#include <stdlib.h>
void FillArray(int n, int *ptr);

int main()
{
    int vet[5];
    int *ptr;
    int n;

    ptr = vet;
    printf("Digite o valor: \n");
    scanf("%d", &n);
    FillArray(n, ptr);
}

void FillArray(int n, int *ptr)
{
    size_t i;

    for (i = 0; i < 5; i++)
    {
        *(ptr + i) = n;
        printf("%d", *(ptr + i));
    }
}
/*Tirando duvida de um amigo sobre ponteiro e suas interações com vetores*/
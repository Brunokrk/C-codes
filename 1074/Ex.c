#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void setValues(int *vet, int N);
void getResults(int *vet, int N);

int main()
{
    int N, i;
    int *vet;
    printf("Quantidade de valores: ");
    scanf("%d\n", &N);
    fflush(stdin);
    vet = (int *)malloc(N * sizeof(int));
    setValues(vet, N);
    for (i = 0; i < N; i++)
    {
        printf("%d\n", vet[i]);
    }
    getResults(vet, N);
    return 0;
}

void setValues(int *vet, int N)
{
    int i;
    for (i = 0; i < N; i++)
    {
        printf("Valor %d: ", (i + 1));
        scanf("%d\n", &vet[i]);
    }
}
void getResults(int *vet, int N)
{
    int i;
    for (i = 0; i < N; i++)
    {
        if (((vet[i] % 2) == 0) && (vet[i] > 0))
        {
            printf("EVEN POSITIVE\n");
        }
        else if (((vet[i] % 2) == 0) && (vet[i] < 0))
        {
            printf("EVEN NEGATIVE\n");
        }
        else if (((vet[i] % 2) != 0) && (vet[i] > 0))
        {
            printf("ODD POSITIVE\n");
        }
        else if (((vet[i] % 2) != 0) && (vet[i] < 0))
        {
            printf("ODD NEGATIVE\n");
        }
        else
        {
            printf("NULL\n");
        }
    }
}

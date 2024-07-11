#include <stdio.h>

void print_n_matrix(int n)
{
    int nn = n * n;
    for (int i = 1; i <= nn; i++)
    {
        printf("%d ", i);
        if (i % n == 0)
            printf("\n");
    }
}

int main()
{
    int n;
    printf("Введите n: ");
    scanf("%d", &n);
    printf("\n");
    print_n_matrix(n);
    printf("\n");
}
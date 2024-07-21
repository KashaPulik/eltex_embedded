#include <stdio.h>

void draw_matrix(int n)
{
    int array[n];
    int last_one_index = n - 1;
    for (int i = 0; i < n - 1; i++)
        array[i] = 0;
    array[last_one_index--] = 1;
    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            printf("%d ", array[j]);
        printf("\n");
        array[last_one_index--] = 1;
    }
}

int main()
{
    int n;
    printf("Введите n: ");
    scanf("%d", &n);
    printf("\n");
    draw_matrix(n);
}
#include <stdio.h>
#include <stdlib.h>

int **fill_array(int n)
{
    int **array = malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++)
        array[i] = malloc(sizeof(int) * n);
    int a = 1;
    int right_bound = n;
    int lower_bound = n;
    int left_bound = 0;
    int upper_bound = 0;
    int i = 0, j = 0;
    while (a <= n * n)
    {
        for (j = upper_bound; j < right_bound; j++)
            array[i][j] = a++;
        upper_bound++;
        right_bound--;
        j--;
        for (i = i + 1; i < lower_bound; i++)
            array[i][j] = a++;
        lower_bound--;
        i--;
        for(j = j - 1; j >= left_bound; j--)
            array[i][j] = a++;
        left_bound++;
        j++;
        for(i = i - 1; i >= upper_bound; i--)
            array[i][j] = a++;
        i++;
    }
    return array;
}

int main()
{
    int n;
    printf("Введите n: ");
    scanf("%d", &n);
    printf("\n");
    int **array = fill_array(n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            printf("%-4d", array[i][j]);
        printf("\n");
    }
}
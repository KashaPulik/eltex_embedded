#include <stdio.h>

int count_ones(int number)
{
    int count = 0;
    for (int i = (sizeof(number) * 8) - 1; i >= 0; i--)
        if ((number >> i) & 1)
            count++;
    return count;
}

void print_bin(int number)
{
    for (int i = (sizeof(number) * 8) - 1; i >= 0; i--)
    {
        printf("%d", (number >> i) & 1);
        if (i % 4 == 0)
            printf(" ");
    }
    printf("\n");
}

int main()
{
    int number;
    printf("Введите целое число, чтобы узнать, сколько единиц в его двоичном представлении: ");
    scanf("%d", &number);
    printf("Количество единиц в двоичном представлении числа %d: %d\n", number, count_ones(number));
    printf("Если возникают сомнения, можно пересчитать их самостоятельно, вот двоичное представление числа:\n");
    print_bin(number);
}
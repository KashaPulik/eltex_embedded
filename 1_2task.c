#include <stdio.h>

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
    printf("Введите целое число, чтобы увидеть его двоичное представление: ");
    scanf("%d", &number);
    print_bin(number);
}
#include <stdio.h>
#include <stdint.h>

void print_bin(int number)
{
    for (int i = (sizeof(number) * 8) - 1; i >= 0; i--)
    {
        printf("%d", (number >> i) & 1);
        if (i % 8 == 0)
            printf(" ");
    }
    printf("\n");
}

void print_bin_one_byte(uint8_t number)
{
    for (int i = 7; i >= 0; i--)
    {
        printf("%d", (number >> i) & 1);
        if (i % 8 == 0)
            printf(" ");
    }
    printf("\n");
}

int change_third_byte(int dest, uint8_t src)
{
    uint8_t *p = &dest;
    *(p + 1) = src;
    return dest;
}

int main()
{
    int a;
    uint8_t b;
    printf("Введите число, в котором нужно заменить третий байт: ");
    scanf("%d", &a);
    printf("Вот ваше число в двоичном виде\n");
    print_bin(a);
    printf("Введите число, на которое нужно заменить третий байт в предыдущем числе: ");
    scanf("%hhu", &b);
    printf("Вот это число в двоичном виде\n");
    print_bin_one_byte(b);
    printf("А так выглядит изменённое изначальное число в двоичном виде\n");
    a = change_third_byte(a, b);
    print_bin(a);
    printf("А в десятичном виде оно выглядит так: %d\n", a);
}
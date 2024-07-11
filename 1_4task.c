#include <stdio.h>

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

void print_bin_one_byte(int number)
{
    for (int i = 7; i >= 0; i--)
    {
        printf("%d", (number >> i) & 1);
        if (i % 8 == 0)
            printf(" ");
    }
    printf("\n");
}

int change_third_byte(int number, int displacer)
{
    int mask = 0b11111111111111110000000011111111;
    displacer <<= 8;
    return (number & mask) | displacer;
}

int main()
{
    int number, displacer;

    printf("Я не уверен в том, с какой стороны первый байт,\n");
    printf("так как это может быть тот, что слева, или же тот,\n");
    printf("что является самым младшим, то есть тот, что справа,\n");
    printf("поэтому я решил считать первым байтом тот, что слева\n\n");

    printf("Введите целое число, в котором хотите заменить третий байт: ");
    scanf("%d", &number);
    printf("Вот его двоичное представление:\n");
    print_bin(number);
    printf("Введите число, которое должно заменить третий байт в предыдущем числе\n");
    printf("Желательно ввести число от 0 до 255, так как один байт не поддерживает большее количество значений\n");
    printf("В случае, если вы введёте другое число, поведение программы не определено\n");
    scanf("%d", &displacer);
    printf("Вот его двоичное представление\n");
    print_bin_one_byte(displacer);
    number = change_third_byte(number, displacer);
    printf("После замены третьего байта число проибрело следующее значение: %d\n", number);
    printf("Его двоичное представление теперь:\n");
    print_bin(number);
}
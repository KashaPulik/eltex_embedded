#include <stdio.h>
#include <string.h>

char *my_strstr(char *strB, char *strA)
{
    int a, b;
    for (int i = 0; strB[i] != '\0'; i++)
    {
        a = 0;
        b = i;
        while (strB[b++] == strA[a++])
            if (strA[a] == '\0')
                return strB + i;
    }
    return NULL;
}

int main()
{
    char A[128], B[128];
    printf("Введите строку: ");
    scanf("%s", A);
    printf("Введите подстроку, которую нужно найти: ");
    scanf("%s", B);
    char *C = my_strstr(A, B);
    if(C == NULL)
    {
        printf("Данная подстрока в строке не найдена\n");
        return 0;
    }
    printf("Подстрока найдена!\n");
    printf("Если вывести строки, начиная с найденной подстроки, то получится:\n");
    printf("%s\n", C);
}
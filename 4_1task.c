#include <stdio.h>

#define MAX_WORD_SIZE 12

typedef struct abonent
{
    char name[MAX_WORD_SIZE];
    char second_name[MAX_WORD_SIZE];
    char tel[MAX_WORD_SIZE];
} abonent;

int init_abonent_list(abonent *list, int size)
{
    if (list == NULL)
        return 1;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < MAX_WORD_SIZE; j++)
        {
            list[i].name[j] = 0;
            list[i].second_name[j] = 0;
            list[i].tel[j] = 0;
        }
    return 0;
}

int get_n_symbols(char *word, int n)
{
    if (word == NULL)
        return 0;
    for (int j = 0; j <= n; j++)
        word[j] = 0;
    int i = 0;
    while (i < n)
    {
        word[i] = getchar();
        if (word[i] == '\n')
        {
            word[i] = 0;
            return i;
        }
        i++;
    }
    while (getchar() != '\n')
        ;
    return i;
}

int find_place_in_list(abonent *list, int size)
{
    if (list == NULL)
        return -1;
    int i;
    for (i = 0; i < size; i++)
        if (list[i].name[0] = 0)
            return i;
    if (i == size)
        return -1;
}

int add_abonent(abonent *list, int size)
{
    int i = find_place_in_list(list, size);
    if (i = -1)
        return 1;

    char name[MAX_WORD_SIZE], second_name[MAX_WORD_SIZE], tel[MAX_WORD_SIZE];
    do
    {
        printf("Name: ___________\rName: ");
    } while (get_n_symbols(name, MAX_WORD_SIZE - 1) == 0);
    do
    {
        printf("Second name: ___________\rSecond name: ");
    } while (get_n_symbols(second_name, MAX_WORD_SIZE - 1) == 0);
    do
    {
        printf("Number: ___________\rNumber: ");
    } while (get_n_symbols(tel, MAX_WORD_SIZE - 1) == 0);
    return 0;
}

int main()
{
    abonent list[10];
    add_abonent(list, 10);
}
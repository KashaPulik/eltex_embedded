#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        if (list[i].name[0] == 0)
            return i;
    return -1;
}

int find_abonent(abonent *list, int size, char *name, char *second_name, char *tel)
{
    for (int i = 0; i < size; i++)
        if (!strcmp(list[i].name, name) && !strcmp(list[i].second_name, second_name) && !strcmp(list[i].tel, tel))
            return i;
    return -1;
}

void get_name(char *name)
{
    do
    {
        printf("Name: ___________\rName: ");
    } while (get_n_symbols(name, MAX_WORD_SIZE - 1) == 0);
}

void get_info(char *name, char *second_name, char *tel)
{
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
}

int add_abonent(abonent *list, int size)
{
    int i = find_place_in_list(list, size);
    if (i == -1)
        return 1;

    char name[MAX_WORD_SIZE], second_name[MAX_WORD_SIZE], tel[MAX_WORD_SIZE];
    get_info(name, second_name, tel);
    if (find_abonent(list, size, name, second_name, tel) != -1)
        return 2;
    strcpy(list[i].name, name);
    strcpy(list[i].second_name, second_name);
    strcpy(list[i].tel, tel);
    return 0;
}

int delete_abonent(abonent *list, int size, char *name, char *second_name, char *tel)
{
    if (list == NULL)
        return 1;
    int number = find_abonent(list, size, name, second_name, tel);
    if (number == -1)
        return 2;
    for (int i = 0; i < MAX_WORD_SIZE; i++)
    {
        list[number].name[i] = 0;
        list[number].second_name[i] = 0;
        list[number].tel[i] = 0;
    }
    return 0;
}

abonent *search_by_name(abonent *list, int size, char *name, int *count)
{
    abonent *searched_list = malloc(sizeof(abonent) * size);
    if (init_abonent_list(searched_list, size))
    {
        free(searched_list);
        return NULL;
    }
    int temp_count = 0;
    for (int i = 0; i < size; i++)
    {
        if (!strcmp(list[i].name, name))
        {
            strcpy(searched_list[temp_count].name, list[i].name);
            strcpy(searched_list[temp_count].second_name, list[i].second_name);
            strcpy(searched_list[temp_count].tel, list[i].tel);
            temp_count++;
        }
    }
    *count = temp_count;
    if (temp_count == 0)
    {
        free(searched_list);
        return NULL;
    }
    return searched_list;
}

void print_all_records(abonent *list, int size)
{
    int number = 1;
    for (int i = 0; i < size; i++)
    {
        if (list[i].name[0] != 0)
        {
            printf("%-3d. name: %s\n", number, list[i].name);
            printf("     second name: %s\n", list[i].second_name);
            printf("     tel: %s\n\n", list[i].tel);
            number++;
        }
    }
    if (number == 1)
        printf("The list is empty!\n");
}

void draw_start_menu()
{
    printf("1) Add abonent\n");
    printf("2) Delete abonent\n");
    printf("3) Search abonent by name\n");
    printf("4) See all records\n");
    printf("5) Exit\n");
    printf("Choose the option: ");
}

void press_any_key()
{
    printf("\nPress any key to continue...\n");
    getchar();
}

int main()
{
    int size = 100;
    abonent list[size];
    abonent *searched_list = NULL;
    init_abonent_list(list, size);
    int exit_code, count;
    char input[2] = "\0\0";
    char name[MAX_WORD_SIZE], second_name[MAX_WORD_SIZE], tel[MAX_WORD_SIZE];
    while (input[0] != '5')
    {
        system("clear");
        draw_start_menu();
        get_n_symbols(input, 1);
        system("clear");
        switch (input[0])
        {
        case '1':
            printf("Adding new abonent\n\n");
            exit_code = add_abonent(list, size);
            if (exit_code == 0)
                printf("New abonent was added to list!\n");
            if (exit_code == 1)
                printf("There is no more space in list\n");
            if (exit_code == 2)
                printf("Abonent already exist\n");
            press_any_key();
            break;
        case '2':
            printf("Deleting abonent\n\n");
            get_info(name, second_name, tel);
            exit_code = delete_abonent(list, size, name, second_name, tel);
            if (exit_code == 0)
                printf("Abonent was succesfully deleted\n");
            if (exit_code == 1)
            {
                printf("Memory error\n");
                exit(1);
            }
            if (exit_code == 2)
                printf("There is no such abonent in list\n");
            press_any_key();
            break;
        case '3':
            printf("Searching abonent\n\n");
            get_name(name);
            searched_list = search_by_name(list, size, name, &count);
            if (searched_list == NULL)
                printf("There is no abonents with name \"%s\"\n", name);
            else
            {
                printf("Founded %d abonents with name \"%s\":\n\n", count, name);
                print_all_records(searched_list, count);
                free(searched_list);
                searched_list = NULL;
            }
            press_any_key();
            break;
        case '4':
            printf("Abonent list\n\n");
            print_all_records(list, size);
            press_any_key();
            break;
        case '5':
            system("clear");
            return 0;
        }
    }
}
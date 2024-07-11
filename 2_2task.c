#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 100

int main()
{
    char input[MAX_INPUT_SIZE];
    char *ptr;
    int number;
    int count = 0;
    int array[100];

    if (fgets(input, sizeof(input), stdin) != NULL)
    {
        input[strcspn(input, "\n")] = '\0';
        ptr = input;
        while (sscanf(ptr, "%d", &number) == 1)
        {
            array[count++] = number;
            while(*ptr != ' ' && *ptr != '\0')
                ptr++;
            while(*ptr == ' ')
                ptr++;
        }
    }
    for(int i = count - 1; i >= 0; i--)
        printf("%d ", array[i]);
    printf("\n");
}
#include <stdio.h>
#include <stdlib.h>
#define SIZE 30

int main()
{

    int *number = malloc(sizeof(int) * SIZE);
    int *frequency = malloc(sizeof(int) * SIZE);
    int max_frequency = 0;
    int num;
    int count = 0;
    int i = 0;
    FILE *in_file = fopen("scores-data.txt", "r"); // only open a pre-exisiting file in read mode.

    if (!in_file) // equivalent to saying if ( in_file == NULL )
    {
        printf("oops, file can't be read\n");
        exit(-1);
    }
    // attempt to read the next line and store
    // the value in the "number" variable
    while (fscanf(in_file, "%d", &num) == 1)
    {
        printf("We just read %d\n", num);
        i++;
        if (count < 30)
        {
            number[count] = num;
            count++;
        }
    }
    // close the file
    fclose(in_file);
    // int n = sizeof(number) / sizeof(number[0]);

    //    calculate the mode
    for (int i = 0; i < SIZE; i++)
    {
        frequency[number[i]]++;
        if (frequency[number[i]] > max_frequency)
        {
            max_frequency = frequency[number[i]];
        }
    }

    printf("Modes of the array:\n");
    for (int i = 0; i < SIZE; i++)
    {
        if (frequency[i] == max_frequency && max_frequency > 1)
        {
            printf("%d (frequency: %d)\n", i, frequency[i]);
        }
    }

    return 0;
}
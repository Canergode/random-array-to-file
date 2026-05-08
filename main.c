#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    FILE *file;
    int *ptr, N, i, ch;

    // Get array size from user
    printf("How many integers to generate: ");
    scanf("%d", &N);

    // Allocate memory for N integers
    ptr = (int *)malloc(N * sizeof(int));

    // Open file for writing
    file = fopen("numbers.txt", "w");

    // Generate random numbers and write to file
    srand(time(0));
    printf("Generated numbers:\n");

    for (i = 0; i < N; i++)
    {
        *(ptr + i) = rand() % 100;
        fprintf(file, "%d ", *(ptr + i));
        printf("%d ", *(ptr + i));
    }

    fclose(file);

    // Read and print file contents
    printf("\nReading from file:\n");
    file = fopen("numbers.txt", "r");

    do
    {
        ch = getc(file);
        if (ch != EOF)
        {
            putchar(ch);
        }
    }
    while (ch != EOF);

    fclose(file);
    free(ptr);

    return 0;
}

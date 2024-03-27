// DISCLAIMER: I DO NOT SUPPORT PEOPLE PLAGIARIZING MY CODE. I DO NOT TAKE RESPONSIBILITY FOR THE UNLAWFUL ACTIONS OF OTHERS.

#include <stdio.h>
#include <stdlib.h>
#define KEY 157

int main(int argc, char **argv[])
{

    // arg error checking
    if (argc != 3)
    {
        printf("Insufficient arguments.");
        return 1;
    }
    // open file
    FILE *input = fopen(argv[1], "r"); // argv[1] is file name
    if (input == NULL)
    {
        printf("Provided argument is not a valid file.\n");
        return 2;
    }
    FILE *output = fopen(argv[2], "w"); // argv[1] is file name
    if (output == NULL)
    {
        printf("Provided argument is not a valid file.\n");
        return 2;
    }

    // read & print file
    char buffer[1024];
    size_t bytes;

    while ((bytes = fread(buffer, sizeof(char), 1024, input)) > 0)
    {
        for (int i = 0; i < bytes; i++)
        {
            buffer[i] ^= KEY;
        }
        fwrite(buffer, sizeof(char), bytes, output);
    }

    printf("File size: %d bytes\n", ftell(input));

    // close files
    fclose(input);
    fclose(output);
    return 0;
}

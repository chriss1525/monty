#include "monty.h"
/**
 * read_file - opens and reads monty bytecode file
 * @path: path to monty bytecode
 * Return: pointer to read file
 */

void read_file(char *path)
{
    size_t buffer = 0;
    ssize_t nread;
    FILE *file = fopen(path, "r");
    char *line;
    int ln;

    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", path);
        exit(EXIT_FAILURE);
    }

    while ((nread = getline(&line, &buffer, file)) != -1)
    {
        get_tokens(line, ++ln);
    }

    fclose(file);
}

/**
 *
 *
 */
void get_tokens(char *line, int line_number)
{
    char *token;
    int token_number;

    token = strtok(line, " \n");
    token_number = 0;

    while (token)
    {
        printf("Line %d, Token %d: %s\n", line_number, ++token_number, token);
        token = strtok(NULL, " \n");
    }
}

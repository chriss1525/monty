#include "monty.h"
/**
 * read_file - opens and reads monty bytecode file
 * @path: path to monty bytecode
 * @stack: pointer pointer stack
 * Return: pointer to read file
 */

void read_file(char *path, stack_t **stack)
{
	size_t buffer = 0;
	ssize_t nread;
	char *line = NULL;
	int ln = 1;

	/*open file*/
	FILE *file = fopen(path, "r");

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", path);
		exit(EXIT_FAILURE);
	}
	/* read line in file*/
	while ((nread = getline(&line, &buffer, file)) != -1)
	{
		/*break lines into tokens*/
		get_tokens(line, stack, ++ln);
	}
	free(line);
	fclose(file);
}

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
	char *line;
	int ln;

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
		get_tokens(line, ++ln);
	}

	fclose(file);
}

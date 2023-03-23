#include "monty.h"

/**
 * get_tokens - breaks file line strings to tokens
 * @line: file lines
 * @line_number: line number
 * Return: nothing
 */
char *get_tokens(char *line, int line_number)
{
	char *token;
	stack_t *stack = NULL; /* Initialize the stack pointer */
	void (*func)(stack_t **, unsigned int);

	token = strtok(line, " \n");

	while (token != NULL)
	{
		/* Call the appropriate function based on the instruction token */
		func = opcodes(token);
		if (func != NULL)
		{
			func(&stack, line_number);
			return (token);
		}
		else
		{
			errors(line_number, 2);
			exit(EXIT_FAILURE);
		}

		token = strtok(NULL, " \n");
	}
	return (NULL);
}

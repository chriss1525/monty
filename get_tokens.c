#include "monty.h"

/**
 * get_tokens - breaks file line strings to tokens
 * @line: file lines
 * @line_number: line number
 * Return: nothing
 */
void get_tokens(char *line, int line_number)
{
	char *token;
	stack_t *stack = NULL; /* Initialize the stack pointer */
	void (*func)(stack_t **, unsigned int);

	token = strtok(line, " \n");

	while (token)
	{
		/* Call the appropriate function based on the instruction token */
		func = opcodes(token);
		if (func)
			func(&stack, line_number);

		/*printf("%s\n", token);*/
		token = strtok(NULL, " \n");
	}
}

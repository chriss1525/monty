#include "monty.h"

/**
 * get_tokens - breaks a line into tokens
 * and calls the corresponding opcode function
 *
 * @line: the line to break into tokens and execute
 * @stack: a pointer to the stack to manipulate
 * @line_number: the current line number being executed
 *
 * Return: 0 if successful, -1 if an error occurred
 */

int get_tokens(char *line, stack_t **stack, unsigned int line_number)
{
	char *token;
	void (*func)(stack_t **stack, unsigned int line_number);

	token = strtok(line, " \t\n");
	while (token != NULL)
	{
		func = opcodes(token);
		if (func != NULL)
		{
			if (strcmp(token, "push") == 0)
			{
				token = strtok(NULL, " \t\n");
				if (token == NULL)
				{
					errors(line_number - 1, 2);
					return (-1);
				}
				data = strtol(token, NULL, 10);
				func(stack, line_number);
			}
			else
			{
				func(stack, line_number);
			}
		}
		else
		{
			/* Handle unknown instruction */
			fprintf(stderr, "L%d: unknown instruction %s", line_number = 1, token);
			return (1);
		}
		token = strtok(NULL, " \t\n");
	}

	return (0);
}

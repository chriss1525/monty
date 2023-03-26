#include "monty.h"

/**
 * get_tokens - breaks file line strings to tokens
 * @line: file lines
 * @stack: pointer pointer stack
 * @line_number: line number
 * Return: nothing
 */
void get_tokens(char *line, stack_t **stack, int line_number)
{
	char *token;
	char *opc;
	void (*func)(stack_t **, unsigned int);
	int push_val = 0;

	/* Remove trailing '$' character */
	line[strcspn(line, "\n")] = '\0';
	if (line[strlen(line) - 1] == '$')
		line[strlen(line) - 1] = '\0';

	token = strtok(line, " \n");

	while (token != NULL)
	{
		if (strcmp(token, "push") == 0)
		{
			token = strtok(NULL, " \n");
			if (token == NULL)
			{
				errors(line_number - 1, 2);
				/*printf("Error: unknown instruction on line %d\n", line_number);*/
			}
			push_val = atoi(token);
			push(stack, line_number);
		}
		else if (strcmp(token, "pall") == 0)
		{
			pall(stack, line_number);
		}
		else if (strcmp(token, "nop") == 0)
		{
			/* Ignore any non-integer tokens that come after the first token */
			return;
		}
		else if (strcmp(token, "swap") == 0)
		{
			/* Ignore any non-integer tokens that come after the first token */
			return;
		}
		else
		{
			opc = token;
			func = opcodes(opc);
			if (func != NULL)
			{
				func(stack, line_number);
			}
			else
			{
				printf("1\n");
				fprintf(stderr, "L%d: unknown instruction %s\n", line_number - 1, token);
				/*printf("Error: unknown instruction on line %d\n", line_number - 1);*/
				return;
			}
		}

		token = strtok(NULL, " \n");
	}

	/* If we pushed a value, add it to the top of the stack */
	if (push_val != 0)
	{
		(*stack)->n = push_val;
	}
}

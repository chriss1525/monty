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

	/* Remove trailing '$' character */
	line[strcspn(line, "\n")] = '\0';
	if (line[strlen(line) - 1] == '$')
		line[strlen(line) - 1] = '\0';

	token = strtok(line, " \n");

	while (token != NULL)
	{
		/*printf("%d: %s\n", line_number, token);*/

		if (strcmp(token, "push") == 0)
		{
			token = strtok(NULL, " \n");
			if (token == NULL)
			{
				errors(line_number - 1, 2);
				return;
			}
			data = atoi(token);
			push(stack, line_number);
			/*printf("%d: %s\n", line_number, token);*/
		}
		else if (strcmp(token, "pall") == 0)
		{
			/*printf("pall instruction encountered at line %d\n", line_number);*/
			pall(stack, line_number);
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
				errors(line_number, 2);
				return;
			}
			/*printf("Processing opcode: %s\n", opc);*/
		}

		token = strtok(NULL, " \n");
	}
}

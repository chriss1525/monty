#include "monty.h"
/**
 * opcodes - selects instruction to follow
 *
 * @opc: code passed
 *
 * Return: pointer to the function that executes the instruction
 */
void (*opcodes(char *opc))(stack_t **stack, unsigned int line_number)
{
	instruction_t instruct[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}};
	int i;

	printf("Processing opcode: %s\n", opc);
	data = 0;
	for (i = 0; instruct[i].opcode; i++)
	{
		if (strcmp(instruct[i].opcode, opc) == 0)
		{
			data++;
			printf("Selected function: %p\n", (void *)instruct[i].f);
			return (instruct[i].f);
		}
	}

	printf("Error: Unknown instruction %s\n", opc);
	exit(EXIT_FAILURE);
}

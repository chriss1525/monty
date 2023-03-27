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
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"nop", nop},
		{"add", add},
		{NULL, NULL}};

	int i;

	for (i = 0; instruct[i].opcode; i++)
	{
		if (strcmp(instruct[i].opcode, opc) == 0)
		{
			return (instruct[i].f);
		}
	}

	return (NULL);
}

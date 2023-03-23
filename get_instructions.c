#include "monty.h"

/**
 * get_opcodes - selcts instruction to follow
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

	for (i = 0; instruct[i].opcode; i++)
	{
		if (strcmp(instruct[i].opcode, opc) == 0)
			break;
	}

	return (instruct[i].f);
}

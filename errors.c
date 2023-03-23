#include "monty.h"

/**
 * errors - handle errors from the program
 * @line_num: number of lines in opcode file
 * @err_num: number passed representing error type
 *
 * Return: void
 */

void errors(unsigned int line_num, int err_num)
{
	if (err_num == 1)
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
	else if (err_num == 2)
		fprintf(stderr, "L%d: usage: push integer\n", line_num);
	else if (err_num == 3)
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
	else if (err_num == 4)
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
	else if (err_num == 5)
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
	else if (err_num == 6)
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_num);
	exit(EXIT_FAILURE);
}

#include "monty.h"
/**
 * add - adds to the top two elements of the stack
 * @stack: double pointer to a double linked list as stack
 * @line_number: number of lines inside the opcode file
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *aux_stack;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		errors(line_number, 5);
	}
	aux_stack = *stack;
	if (aux_stack->next == NULL)
	{
		errors(line_number, 5);
	}
	aux_stack->next->n += (*stack)->n;
	*stack = (*stack)->next;
	free(aux_stack);
	(*stack)->prev = NULL;
}

/**
 * nop - does nothing
 * @stack: double pointer to the beggining of the stack (DLL)
 * @line_number: number of lines in the opcode file
 * Return: void
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

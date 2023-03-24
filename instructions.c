#include "monty.h"
/**
 * push - puts an item at the top of a stack
 * @stack: pointer to stack
 * @line_number: number of read line
 * Return: nothing
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = (stack_t *)malloc(sizeof(stack_t));
	(void)line_number;

	/*printf("push function called from line %d\n", line_number);*/
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = data;
	if (*stack == NULL)
	{
		new_node->next = NULL;
	}
	else
	{
		new_node->next = *stack;
	}
	new_node->prev = NULL;
	*stack = new_node;

	if (new_node->next != NULL)
		new_node->next->prev = new_node;
}

/**
 * pall - prints all the values on stack staarting from top
 * @line_number: number of read line
 * @stack: pointer to stack
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	(void)line_number;

	/*printf("pall function called from line %d\n", line_number);*/
	new = *stack;
	while (new != NULL)
	{
		printf("%d\n", new->n);
		new = new->next;
	}
}

/**
 * pint - print value at the top of the stack
 * @stack: stack
 * @line_number: line number of instruction
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		errors(line_number - 1, 4);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * _pop - removes top element from stack
 * @stack: double pointer to the beggining of the stack
 * @line_number: number of lines in the opcode file
 *
 * Return: void
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *aux_stack;

	if (*stack == NULL)
		errors(line_number, 1);

	if ((*stack)->next == NULL)
	{
		free(*stack);
		*stack = NULL;
	}
	else
	{
		aux_stack = (*stack)->next;
		(*stack) = aux_stack;
		aux_stack = aux_stack->prev;
		(*stack)->prev = NULL;
		free(aux_stack);
	}
}
#include "monty.h"
/**
 * push - puts an item at the top of a stack
 * @stack: pointer to stack
 * @data: buffer
 * Return: nothing
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = (stack_t *)malloc(sizeof(stack_t));
	(void) line_number;
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
 * 
*/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	(void) line_number;

	if (stack == NULL)
		exit(EXIT_FAILURE);
	new_node = *stack;
	while (new_node != NULL)
	{
		fprintf(stdout, "%d\n", new_node->n);
		new_node = new_node->next;
	}
}

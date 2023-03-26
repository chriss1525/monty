#include "monty.h"

/**
 * main - start point for interprator
 * @argc: number of arguments passed to interprator
 * @argv: arguments passed to interprator
 *
 * Return: 0 on success else exit_failure
 */

int main(int argc, char *argv[])
{
	char *file_name;
	stack_t *stack;

	stack = create_stack();

	file_name = argv[1];
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	read_file(file_name, &stack);
	exit(EXIT_SUCCESS);
}

#include "monty.h"

/**
 * create_stack - creates a new empty stack
 *
 * Return: pointer to the new stack
 */
stack_t *create_stack(void)
{
	stack_t *stack = NULL;
	return (stack);
}

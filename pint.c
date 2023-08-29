#include "monty.h"


/**
 * _pint - Opcodes prints values at the top of the stack
 *
 * @stack: Indicates a pointer to the stack
 *
 * @line_number: Indicates different operations in the stack
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	if (!head)
	{
		dprintf(STDERR_FILENO, PINT_FAIL, line_number);
		_release(1);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", head->n);
}

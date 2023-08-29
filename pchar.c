#include "monty.h"


/**
 * _pchar - Opcode prints char at the top of the stack
 *
 * @stack: Indicates a pointer to the stack
 *
 * @line_number: Indicates different operations in the stack
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;

	if (!node)
	{
		dprintf(STDERR_FILENO, PCHAR_FAIL, line_number);
		_release(1);
		exit(EXIT_FAILURE);
	}

	if (node->n < 0 || node->n > 127)
	{
		dprintf(STDERR_FILENO, PCHAR_RANGE, line_number);
		_release(1);
		exit(EXIT_FAILURE);
	}

	putchar(node->n);
	putchar('\n');
}

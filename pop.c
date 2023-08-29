#include "monty.h"


/**
 * _pop - Opcode removes the top element of the stack
 *
 * @stack: Indicates a pointer to the stack
 *
 * @line_number: Indicates different operations in the stack
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (!temp)
	{
		dprintf(STDERR_FILENO, POP_FAIL, line_number);
		_release(1);
		exit(EXIT_FAILURE);
	}

	_delete(stack, 0);
}

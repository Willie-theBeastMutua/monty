#include "monty.h"


/**
 * _mod - Opcode computes rest of second top by top element of the stack
 *
 * @stack: Indicates a pointer to the stack
 *
 * @line_number: Indicates different operations in the stack
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	int mod = 0;
	stack_t *node = NULL;
	stack_t *node_0 = _get_node_index(*stack, 0);
	stack_t *node_1 = _get_node_index(*stack, 1);

	if (_length(*stack) < 2)
	{
		dprintf(STDERR_FILENO, MOD_FAIL, line_number);
		_release(1);
		exit(EXIT_FAILURE);
	}

	if (node_0->n == 0)
	{
		dprintf(STDERR_FILENO, DIV_ZERO, line_number);
		_release(1);
		exit(EXIT_FAILURE);
	}

	mod = node_1->n % node_0->n;
	_delete(stack, 0);
	_delete(stack, 0);
	node = _addnode(stack, mod);
	if (!node)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		_release(1);
		exit(EXIT_FAILURE);
	}
}

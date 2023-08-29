#include "monty.h"


/**
 * _mul - Opcode multiplies second top element with top element of the stack
 *
 * @stack: Indicates a pointer to the stack
 *
 * @line_number: Indicates different operations in the stack
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	int mul = 0;
	stack_t *node = NULL;
	stack_t *node_0 = _get_node_index(*stack, 0);
	stack_t *node_1 = _get_node_index(*stack, 1);

	if (_length(*stack) < 2)
	{
		dprintf(STDERR_FILENO, MUL_FAIL, line_number);
		_release(1);
		exit(EXIT_FAILURE);
	}

	mul = node_1->n * node_0->n;
	_delete(stack, 0);
	_delete(stack, 0);
	node = _addnode(stack, mul);
	if (!node)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		_release(1);
		exit(EXIT_FAILURE);
	}
}

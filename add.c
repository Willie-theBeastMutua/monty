#include "monty.h"


/**
 * _add - Opcode adds top two elements of the stack
 *
 * @stack: Indicates a pointer to the stack
 *
 * @line_number: Indicates different operations in the stack
 */
void _add(stack_t **stack, unsigned int line_number)
{
	int sum = 0;
	stack_t *node = NULL;
	stack_t *node_0 = _get_node_index(*stack, 0);
	stack_t *node_1 = _get_node_index(*stack, 1);

	if (_length(*stack) < 2)
	{
		dprintf(STDERR_FILENO, ADD_FAIL, line_number);
		_release(1);
		exit(EXIT_FAILURE);
	}

	sum = node_0->n + node_1->n;
	_delete(stack, 0);
	_delete(stack, 0);
	node = _addnode(stack, sum);
	if (!node)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		_release(1);
		exit(EXIT_FAILURE);
	}
}

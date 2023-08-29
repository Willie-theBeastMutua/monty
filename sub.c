#include "monty.h"


/**
 * _sub - Opcode subtracts top element from second element
 *
 * @stack: Indicates a pointer to the stack
 *
 * @line_number: Indicates different operations in the stack
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	int sub = 0;
	stack_t *node = NULL;
	stack_t *node_0 = _get_node_index(*stack, 0);
	stack_t *node_1 = _get_node_index(*stack, 1);

	if (_length(*stack) < 2)
	{
		dprintf(STDERR_FILENO, SUB_FAIL, line_number);
		_release(1);
		exit(EXIT_FAILURE);
	}

	sub = node_1->n - node_0->n;
	_delete(stack, 0);
	_delete(stack, 0);
	node = _addnode(stack, sub);
	if (!node)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		_release(1);
		exit(EXIT_FAILURE);
	}
}

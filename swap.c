#include "monty.h"


/**
 * _swap - Opcode swaps top two elements of the stack
 *
 * @stack: Indicates a pointer to the stack
 *
 * @line_number: Indicates different operations in the stack
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack, *node = NULL;
	int num;

	if (_length(*stack) < 2)
	{
		dprintf(STDERR_FILENO, SWAP_FAIL, line_number);
		_release(1);
		exit(EXIT_FAILURE);
	}

	temp = _get_node_index(*stack, 0);
	num = temp->n;
	_delete(stack, 0);
	node = _insert(stack, 1, num);
	if (!node)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		_release(1);
		exit(EXIT_FAILURE);
	}
}

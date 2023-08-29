#include "monty.h"


/**
 * _rotl - Opcode rotates the stack to the top
 *
 * @stack: Indicates a pointer to the stack
 *
 * @line_number: Indicates different operations in the stack
 */
void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int num  = 0;

	(void)line_number;

	if (*stack == NULL)
		return;
	temp = _get_node_index(*stack, 0);
	num = temp->n;
	_delete(stack, 0);
	_addnode(stack, num);
}

#include "monty.h"


/**
 * _rotr - Opcode rotates the stack to the bottom
 *
 * @stack: Indicates a pointer to the stack
 *
 * @line_number: Indicates different operations in the stack
 */
void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int num = 0, len = _length(*stack);

	(void)line_number;

	if (*stack == NULL)
		return;
	temp = _get_node_index(*stack, len - 1);
	num = temp->n;
	_delete(stack, len - 1);
	_addnode(stack, num);
}

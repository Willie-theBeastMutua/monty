#include "monty.h"


/**
 * _stack -  Opcode sets the format of the info to a stack(LIFO).
 *
 * @stack: Indicates a pointer to the stack
 *
 * @line_number: Indicates different operations in the stack
 */
void _stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	info.qflag = 0;
}

/**
 * _queue - Opcode sets the format of the info  to a queue(FIFO).
 *
 * @stack: Indicates a pointer to the stack
 *
 * @line_number: Indicates different operations in the stack
 */
void _queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	info.qflag = 1;
}

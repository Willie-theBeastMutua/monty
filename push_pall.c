#include "monty.h"


/**
 * _push - Opcode pushes an element to the stack
 *
 * @stack: Indicates a pointer to the stack
 *
 * @line_number: Indicates different operations in the stack
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	int num = 0, i;

	if (info.words[1] == NULL)
	{
		dprintf(STDERR_FILENO, PUSH_FAIL, line_number);
		_release(1);
		exit(EXIT_FAILURE);
	}

	for (i = 0; info.words[1][i]; i++)
	{
		if (isalpha(info.words[1][i]) != 0)
		{
			dprintf(STDERR_FILENO, PUSH_FAIL, line_number);
			_release(1);
			exit(EXIT_FAILURE);
		}
	}
	num = atoi(info.words[1]);

	if (info.qflag == 0)
		new = _addnode(stack, num);
	else if (info.qflag == 1)
		new = _add_end(stack, num);
	if (!new)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		_release(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * _pall - Opcode prints all values on the stack , from  top to bottom
 *
 * @stack: Indicates a pointer to the stack
 *
 * @line_number: Indicates different operations in the stack
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	if (*stack)
		_print(*stack);
}

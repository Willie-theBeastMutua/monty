#include "monty.h"

/**
 * get_func - selects the right function
 * @parsed: line from the bytecode file passed to main
 *
 * Return: pointer to the selected function, or NULL on failure
 */
void (*get_func(char **parsed))(stack_t **, unsigned int)
{
	instruction_t func_arr[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{"stack", _stack},
		{"queue", _queue},
		{NULL, NULL}
	};

	int codes = 17, i;

	for (i = 0; i < codes; i++)
	{
		if (strcmp(func_arr[i].opcode, parsed[0]) == 0)
		{
			return (func_arr[i].f);
		}
	}
	return (NULL);
}

/**
 * _opcode - count argument and open file
 *
 * @str: pointer to struct of arguments from main
 * Return: Nothing
 */
void _opcode(arg_stack *str)
{
	size_t measure = 0;
	int wax = 0;
	void (*code_func)(stack_t **, unsigned int);

	if (str->ac != 2)
	{
		dprintf(STDERR_FILENO, USAGE);
		exit(EXIT_FAILURE);
	}
	info.fptr = fopen(str->vec, "r");
	if (!info.fptr)
	{
		dprintf(STDERR_FILENO, FILE_ERROR, str->vec);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		str->line_number++;
		wax = getline(&(info.line), &measure, info.fptr);
		if (wax < 0)
			break;
		info.words = _token(info.line);
		if (info.words[0] == NULL || info.words[0][0] == '#')
		{
			_release(0);
			continue;
		}
		code_func = get_func(info.words);
		if (!code_func)
		{
			dprintf(STDERR_FILENO, UNKNOWN, str->line_number, info.words[0]);
			_release(1);
			exit(EXIT_FAILURE);
		}
		code_func(&(info.stack), str->line_number);
		_release(0);
	}
	_release(1);
}

/**
 * _print - prints elements from stack
 *
 * @h: pointer parameter
 * Return: number of elements in the list
 */
size_t _print(const dlistint_t *h)
{
	size_t ptr = 0;

	if (!h)
		return (0);

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
		ptr++;
	}

	return (ptr);
}

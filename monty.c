#include "monty.h"


data_t info = DATA_INIT;

/**
 * main - entry point
 * @argc: arguments count
 * @argv: arguments vector
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char *argv[])
{
	arg_stack str;

	str.vec = argv[1];
	str.ac = argc;
	str.line_number = 0;

	_opcode(&str);

	return (EXIT_SUCCESS);
}

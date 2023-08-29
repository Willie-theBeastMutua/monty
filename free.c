#include "monty.h"


/**
 * _release - release memory
 * @all: parameter
 * Return: Nothing
 */
void _release(int all)
{
	if (info.line)
	{
		free(info.line);
		info.line = NULL;
		_deallocate(info.words);
		info.words = NULL;
	}

	if (all)
	{
		if (info.stack)
		{
			_freelist(info.stack);
			info.stack = NULL;
		}
		if (info.fptr)
		{
			fclose(info.fptr);
			info.fptr = NULL;
		}
	}
}

/**
 * _deallocate - frees strings
 *
 * @args: parameter
 * Return: Nothing
 */
void _deallocate(char **args)
{
	int d;

	if (!args)
		return;

	for (d = 0; args[d]; d++)
		free(args[d]);

	free(args);
}

/**
 * _freelist - frees list
 *
 * @head: parameter
 * Return: Nothing
 */
void _freelist(dlistint_t *head)
{
	dlistint_t *tmp;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

/**
 * _length - number of nodes
 *
 * @h: parameter
 * Return: elements count
 */
size_t _length(const dlistint_t *h)
{
	size_t ptr = 0;

	if (!h)
		return (0);

	while (h)
	{
		ptr++;
		h = h->next;
	}

	return (ptr);
}

#include "monty.h"


/**
 * _insert - inserts a node
 *
 * @h: parameter
 * @idx: parameter
 * @n: parameter
 * Return: address or NULL
 */
dlistint_t *_insert(dlistint_t **h, unsigned int idx, int n)
{
	unsigned int i;
	dlistint_t *ch;
	dlistint_t *ptr = *h;

	if (idx == 0)
		return (_addnode(h, n));

	for (i = 0; ptr && i < idx; i++)
	{
		if (i == idx - 1)
		{
			if (ptr->next == NULL)
				return (_add_end(h, n));
			ch = malloc(sizeof(dlistint_t));
			if (!ch || !h)
				return (NULL);
			ch->n = n;
			ch->next = NULL;
			ch->next = ptr->next;
			ch->prev = ptr;
			ptr->next->prev = ch;
			ptr->next = ch;
			return (ch);
		}
		else
			ptr = ptr->next;
	}

	return (NULL);
}

/**
 * _add_end - add new node at the end
 *
 * @head: parameter
 * @n: parameter
 * Return: address or NULL
 */
dlistint_t *_add_end(dlistint_t **head, const int n)
{
	dlistint_t *ch;
	dlistint_t *ptr = *head;

	if (!head)
		return (NULL);

	ch = malloc(sizeof(dlistint_t));
	if (!ch)
		return (NULL);

	ch->n = n;
	ch->next = NULL;

	if (*head == NULL)
	{
		ch->prev = NULL;
		*head = ch;
		return (ch);
	}

	while (ptr->next)
		ptr = ptr->next;

	ptr->next = ch;
	ch->prev = ptr;

	return (ch);
}

/**
 * _addnode - adds a new node
 *
 * @head: parameter
 * @n: parameter
 * Return: address or Null
 */
dlistint_t *_addnode(dlistint_t **head, const int n)
{
	dlistint_t *ch;

	if (!head)
		return (NULL);

	ch = malloc(sizeof(dlistint_t));
	if (!ch)
		return (NULL);

	ch->n = n;

	ch->next = *head;
	ch->prev = NULL;

	if (*head)
		(*head)->prev = ch;

	*head = ch;

	return (ch);
}

/**
 * _delete - deltes a node
 *
 * @head: parameter
 * @index: parameter
 * Return: 1 or -1
 */
int _delete(dlistint_t **head, unsigned int index)
{
	dlistint_t *ch = *head;
	unsigned int i = 0;

	if (!index)
	{
		(*head) = ch->next;
		if (ch->next)
			ch->next->prev = NULL;
		ch->next = NULL;
		free(ch);
		return (1);
	}

	while (i < index)
	{
		ch = ch->next;
		i++;
		if (!ch)
			return (0);
	}

	ch->prev->next = ch->next;
	if (ch->next)
		ch->next->prev = ch->prev;
	free(ch);

	return (1);
}

/**
 * _get_node_index - gets the nth node of a doubly linked list
 * @head: pointer to the list
 * @index: index of the node to return
 *
 * Return: address of the node, or if it does not exist, NULL
 */
dlistint_t *_get_node_index(dlistint_t *head, unsigned int index)
{
	unsigned int j = 0;

	if (!head)
		return (NULL);

	while (head && j < index)
	{
		head = head->next;
		j++;
	}

	return (head ? head : NULL);
}

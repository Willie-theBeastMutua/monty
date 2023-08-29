#include "monty.h"


/**
 * _count - count the number
 *
 * @s: parameter
 * Return: number of words counted
 */
int _count(char *s)
{
	int zab, i, j;

	zab = 0;
	j = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == ' ')
			zab = 0;
		else if (zab == 0)
		{
			zab = 1;
			j++;
		}
	}

	return (j);
}
/**
 * _token - splits string
 *
 * @str: parameter
 * Return: (Success)
 */
char **_token(char *str)
{
	char **ch, *ptr;
	int size = 0, c = 0, first, i, string, k = 0, last;

	size = strlen(str);
	string = _count(str);
	if (string == 0)
		return (NULL);

	ch = (char **) malloc(sizeof(char *) * (string + 1));
	if (ch == NULL)
		return (NULL);

	for (i = 0; i <= size; i++)
	{
		if (isspace(str[i]) || str[i] == '\0' || str[i] == '\n')
		{
			if (c)
			{
				last = i;
				ptr = (char *) malloc(sizeof(char) * (c + 1));
				if (ptr == NULL)
					return (NULL);
				while (first < last)
					*ptr++ = str[first++];
				*ptr = '\0';
				ch[k] = ptr - c;
				k++;
				c = 0;
			}
		}
		else if (c++ == 0)
			first = i;
	}

	ch[k] = NULL;

	return (ch);
}

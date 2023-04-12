#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>

/**
 * argstostr - concatenates all the arguments of the program
 * @ac: count of arguments
 * @av: array of arguments
 *
 * Return: pointer to a new string,
 *	or NULL if (it fails or (ac == 0 or av == NULL))
 */

char *argstostr(int ac, char **av)
{
	char *ptr;
	int i, j, arg_len, args_len = 0, len = 0;

	if (ac == 0 || av == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < ac; i++)
		args_len += (strlen(av[i]) + 1);

	ptr = (char *)malloc(sizeof(char) * args_len + 1);

	if (!ptr)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		arg_len = strlen(av[i]);

		for (j = 0; j <= arg_len; j++)
		{
			if (j == (arg_len))
			{
				ptr[len] = '\n';
				len++;
				continue;
			}
			ptr[len] = av[i][j];
			len++;
		}
		ptr[len] = '\0';
		ptr[len + 1] = '\n';
	}

	return (ptr);
}


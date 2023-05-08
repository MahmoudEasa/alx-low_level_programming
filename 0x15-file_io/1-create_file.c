#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "main.h"

/**
 * create_file - creates a file
 * @filename: the name of the file to create
 * @text_content: a NULL terminated string to write to the file
 *
 * Return: 1 on success, -1 on failure
 */

int create_file(const char *filename, char *text_content)
{
	int f, count, len;

	if (!filename)
		return (-1);

	f = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);

		if (f == -1)
			return (-1);

		if (text_content)
		{
			len = strlen(text_content);
			count = write(f, text_content, len);
		}

	close(f);

	if (count == -1)
		return (count);
	else
		return (1);
}


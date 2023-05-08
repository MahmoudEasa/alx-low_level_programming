#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "main.h"

/**
 * append_text_to_file - appends text at the end of a file
 * @filename: string
 * @text_content: a NULL terminated string to write to the file
 *
 * Return: 1 on success and -1 on failure
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int f, count, len;

	if (!filename)
		return (-1);

	f = open(filename, O_WRONLY | O_APPEND);

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


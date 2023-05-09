#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "main.h"

/**
 * read_textfile -  reads a text file and prints it to
 *	the POSIX standard output
 * @filename: string
 * @letters: the number of letters it should read and print
 *
 * Return: the actual number of letters it could read and print
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buffer;
	ssize_t count, f;

	if (!filename)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (!buffer)
	{
		free(buffer);
		return (0);
	}

	f = open(filename, O_RDONLY);

		if (f == -1)
		{
			free(buffer);
			return (0);
		}
		count = read(f, buffer, letters);
		if (count == -1)
		{
			free(buffer);
			return (0);
		}
		count = write(STDOUT_FILENO, buffer, count);
		free(buffer);
	close(f);

	if (count == -1)
		return (0);
	else
		return (count);
}


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
	char buffer[1024];
	int f;
	ssize_t count;

	if (!filename)
		return (0);

	f = open(filename, O_RDONLY);

		if (f == -1)
			return (0);

		count = read(f, buffer, letters);

		if (count == -1)
			return (0);

		write(STDOUT_FILENO, buffer, count);

	close(f);

	if (count == -1)
		return (0);
	else
		return (count);
}


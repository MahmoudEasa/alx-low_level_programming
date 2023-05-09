#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "main.h"

/**
 * main - copies the content of a file to another file.
 * @ac: number of arguments
 * @av: array of arguments
 *
 * Return: 0
 */

int main(int ac, char **av)
{
	int f_from, f_to, count, w;
	char *buffer;

	if (ac != 3)
		print_err("Usage:", "cp file_from file_to", 97, NULL);

	buffer = malloc(sizeof(char) * 1024);
	if (!buffer)
		print_err("Error: Can't write to", av[2], 99, NULL);

	f_from = open(av[1], O_RDONLY);
		if (f_from == -1)
			print_err("Error: Can't read from file", av[1], 98, buffer);
	f_to = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	count = read(f_from, buffer, 1024);

		do {
			if (f_to == -1 || w == -1)
				print_err("Error: Can't write to", av[2], 99, buffer);

			if (count == -1)
				print_err("Error: Can't read from file", av[1], 98, buffer);

			w = write(f_to, buffer, count);

			count = read(f_from, buffer, 1024);
			f_to = open(av[2], O_WRONLY | O_APPEND);
		} while (count > 0);
		if (close(f_to) == -1)
			print_err("Error:", "Can't close fd -1", 100, buffer);

	if (close(f_from) == -1)
		print_err("Error:", "Can't close fd -1", 100, buffer);

	free(buffer);
	return (0);
}

/**
 * print_err - print error
 * @s1: string
 * @s2: strign
 * @ex: number of exit
 * @buf: pointer to buffer to free
 */

void print_err(char *s1, char *s2, int ex, char *buf)
{
	if (buf)
		free(buf);

	dprintf(STDERR_FILENO, "%s %s\n", s1, s2);
	exit(ex);
}


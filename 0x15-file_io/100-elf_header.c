#include <stdio.h>
#include <elf.h>
#include <stdlib.h>
#include "main.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * main - displays the information contained
 *	in the ELF header at the start of an ELF file
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0
 */

int main(int argc, char **argv)
{
	int f, r;
	Elf64_Ehdr *header;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
		exit(98);
	}
	f = open(argv[1], O_RDONLY);
	if (f == -1)
		print_err_elf(argv[1]);
	header = malloc(sizeof(header));
	if (!header)
	{
		close(f);
		print_err_elf(argv[1]);
	}

	r = read(f, header, sizeof(header));
	if (r == -1)
	{
		free(header);
		close(f);
		print_err_elf(argv[1]);
	}
	check_elf(header->e_ident, argv[1]);
	printf("ELF Header:\n");
	print_magic(header->e_ident);
	print_class(header->e_ident);
	print_data(header->e_ident);
	print_version(header->e_ident);
	print_os_abi(header->e_ident);
	print_abi_version(header->e_ident);
	print_type(header->e_type, header->e_ident);
	print_entry(header->e_entry, header->e_ident);

	free(header);
	close(f);
	return (0);
}

/**
 * print_err_elf - print error
 * @s: string
 */

void print_err_elf(char *s)
{
	dprintf(STDERR_FILENO, "Error: Can't read file %s\n", s);
	exit(98);
}

/**
 * check_elf - check ELF
 * @e_ident: array
 * @file: string
 */

void check_elf(unsigned char *e_ident, char *file)
{
	if (e_ident[EI_MAG0] != ELFMAG0
				|| e_ident[EI_MAG1] != ELFMAG1
				|| e_ident[EI_MAG2] != ELFMAG2
				|| e_ident[EI_MAG3] != ELFMAG3)
	{
		dprintf(STDERR_FILENO, "Error: %s is not an ELF file\n", file);
		exit(98);
	}
}

/**
 * print_magic - print Magic
 * @e_ident: array
 */

void print_magic(unsigned char *e_ident)
{
	printf("   Magic:  %02x %02x %02x %02x\n", e_ident[EI_MAG0],
		e_ident[EI_MAG1],
		e_ident[EI_MAG2],
		e_ident[EI_MAG3]);
}

/**
 * print_class - print Class
 * @e_ident: array
 */

void print_class(unsigned char *e_ident)
{
	printf("  Class:                              %s\n",
			e_ident[EI_CLASS] == ELFCLASS32
			? "ELF32"
			: e_ident[EI_CLASS] == ELFCLASS64
			? "ELF64"
			: "This class is invalid");
}

/**
 * print_data - print Data
 * @e_ident: array
 */

void print_data(unsigned char *e_ident)
{
	printf("   Data:                              %s\n",
			e_ident[EI_DATA] == ELFDATA2LSB
			? "2's complement, little-endian"
			: e_ident[EI_DATA] == ELFDATA2LSB
			? "2's complement, big-endian"
			: "Unknown data format");
}

/**
 * print_version - print Version
 * @e_ident: array
 */

void print_version(unsigned char *e_ident)
{
	printf("   Version:                           %d %s\n",
			e_ident[EI_VERSION],
			e_ident[EI_VERSION] == EV_NONE
			? ""
			: "1 (current)");
}

/**
 * print_os_abi - print OS/ABI
 * @e_ident: array
 */

void print_os_abi(unsigned char *e_ident)
{
	printf("  OS/ABI:                             ");
	switch (e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64 UNIX\n");
			break;
		case ELFOSABI_ARM:
			printf("UNIX - ARM architecture\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("UNIX - Stand-alone (embedded)\n");
			break;
	}
}

/**
 * print_abi_version - print ABI VERSION
 * @e_ident: array
 */

void print_abi_version(unsigned char *e_ident)
{
	printf("  ABI Version:                        %d",
			e_ident[EI_ABIVERSION]);
}

/**
 * print_type - printr e_type
 * @e_type: number
 * @e_ident: array
 */

void print_type(unsigned int e_type, unsigned char *e_ident)
{
	(void) e_ident;
	printf("  Type:                               %d", e_type);
}

/**
 * print_entry- printr e_entry
 * @e_entry: number
 * @e_ident: array
 */

void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	(void) e_ident;
	printf("  Entry point address:              %lu", e_entry);
}


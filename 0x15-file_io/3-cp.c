#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
 * create_buffer - This function allocates 1024 bytes for a buffer.
 * @file: The name of the file buffer is storing chars for.
 * Return: Pointer to the newly-allocated buffer
 */
char *create_buffer(char *file)
{
	char *tif;

	tif = malloc(sizeof(char) * 1024);

	if (tif == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (tif);
}

/**
 * close_file - this function closes file descriptors.
 * @fd: The file descriptor to be closed.
 */
void close_file(int fd)
{
	int cl;

	cl = close(fd);

	if (cl == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - the function copies the contents of a file to another file.
 * @argc: is the  number of arguments supplied to the program.
 * @argv: is an array of pointers to the arguments.
 *
 * Return: 0 if executes successfully.
 *
 * Description:
 */
int main(int argc, char *argv[])
{
	int from, to, read_file, w;
	char *tif;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	tif = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	read_file = read(from, tif, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || read_file == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(tif);
			exit(98);
		}

		w = write(to, tif, read_file);
		if (to == -1 || w == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(tif);
			exit(99);
		}

		read_file = read(from, tif, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	} while (read_file > 0);

	free(tif);
	close_file(from);
	close_file(to);

	return (0);
}

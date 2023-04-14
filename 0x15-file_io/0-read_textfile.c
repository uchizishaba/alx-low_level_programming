#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - this function reads a text file and prints it to POSIX stdout.
 * @filename: pointer to the name of the file.
 * @letters: number of letters the function should read and print.
 *
 * Return: If the function fails return 0 or if filename is NULL
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t open_file, read_file, write_file;
	char *buff;

	if (filename == NULL)
	{
		return (0);
	}

	buff = malloc(sizeof(char) * letters);
	if (buff == NULL)
	{
		return (0);
	}	
	open_file = open(filename, O_RDONLY);
	read_file = read(open_file, buff, letters);
	write_file = write(STDOUT_FILENO, buff, read_file);

	if (read_file == -1 || open_file == -1 || write_file == -1 || write_file != read_file)
	{
		free(buff);
		return (0);
	}

	free(buff);
	close(open_file);

	return (write_file);
}

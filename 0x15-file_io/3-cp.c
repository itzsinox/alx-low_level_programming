#include "main.h"
#include <stdlib.h>
#include <stdio.h>

void close_file(int fd);
char *create_buffer(char *file);

/**
 * create_buffer - allc 1024 b
 * @file: name of file
 * Return: ptr
 */
char *create_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);
	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
				"Error: Can not write to %s\n",
				file);
		exit(99);
	}
	return (buffer);
}
/**
 * main - cp content
 * @argc: argument
 * @argv: args
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int f, t, r, w;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO,
				"Usage: cp file_from file_to\n");
		exit(97);
	}
	buffer = create_buffer(argv[2]);
	f = open(argv[1], O_RDONLY);
	r = read(f, buffer, 1024);
	t = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	do {
		if (f == -1 || r == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't read from file %s\n",
					argv[1]);
			free(buffer);
			exit(98);
		}
		w = write(t, buffer, r);
		if (t == -1 || w == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Cant write to %s\n",
					argv[2]);
			free(buffer);
			exit(99);
		}
		r = read(f, buffer, 1024);
		t = open(argv[2], O_WRONLY | O_APPEND);
	} while (r > 0);
	free(buffer);
	close_file(f);
	close_file(t);
	return (0);
}
/**
 * close_file - close file
 * @fd: file desc
 */
void close_file(int fd)
{
	int x;

	x = close(fd);

	if (x == -1)
	{
		dprintf(STDERR_FILENO, "Error: cant close fd %d\n", fd);
		exit(100);
	}
}

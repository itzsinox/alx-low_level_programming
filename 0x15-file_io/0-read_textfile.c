#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - reads text
 * @filename: file
 * @letters: letters
 * Return: num of bytes or 0
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *b;
	ssize_t f;
	ssize_t x;
	ssize_t y;

	f = open(filename, O_RDONLY);
	if (f == -1)
		return (0);
	b = malloc(sizeof(char) * letters);
	y = read(f, b, letters);
	x = write(STDOUT_FILENO, b, y);
	free(b);
	close(f);
	return (x);
}

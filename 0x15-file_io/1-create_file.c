#include "main.h"

/**
 * create_file - to create file
 * @filename: file
 * @text_content: text
 * Return: 1 or -1
 */
int create_file(const char *filename, char *text_content)
{
	int f, x, l = 0;

	if (filename == NULL)
		return (-1);
	if (text_content != NULL)
	{
		for (l = 0; text_content[l];)
			l++;
	}
	f = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	x = write(f, text_content, l);
	if (f == -1 || w == -1)
		return (-1);
	close(f);
	return (1);
}

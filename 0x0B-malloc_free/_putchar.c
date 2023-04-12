#include <unistd.h>
/**
 * _putchar - prints int to stdout
 * @c: input to print
 * Return: 1 on success
 * and on error -1 is returned, and errno is set appropriately
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

#include <unistd.h>
/**
 * _putchar - writed the char c to stdout
 * @c: the caht to print
 * Return: 1 on success
 * on error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

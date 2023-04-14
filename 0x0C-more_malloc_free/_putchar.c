#include <unistd.h>
/**
 * _putchar - prints char into stdout
 * @c: input to print
 * Return: 1 on success
 * and on error -1 is returned, and errno set appropriately
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

#include <unistd.h>
/**
 * _putchar - puts the char to stdout
 * @c: char to put
 * Return: 1 on success
 * and on error -1 is returned, and errno set appropriately
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

#include "3-calc.h"

int op_add(int a, int b);
int op_sub(int a, int b);
int op_mul(int a, int b);
int op_div(int a, int b);
int op_mod(int a, int b);

/**
 * op_add - returns the sum of 2 numb
 * @a: the first numb
 * @b: the second numb
 * Return: the sum
 */
int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - return the diff of 2 numb
 * @a: first numb
 * @b: second numb
 * Return: the diff
 */
int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - returns the product of 2 numb
 * @a: first numb
 * @b: second numb
 * Return: the value of a*b
 */
int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - returns the division of 2 numb
 * @a: first numb
 * @b: second numb
 * Return: the div
 */
int op_div(int a, int b)
{
	return (a / b);
}

/**
 * op_mod - returns the modulo of 2 numb
 * @a: first numb
 * @b: second numb
 * Return: the mod
 */
int op_mod(int a, int b)
{
	return (a % b);
}

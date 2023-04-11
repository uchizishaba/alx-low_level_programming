#include "main.h"

/**
 * set_bit - function that sets the value of a bit to 1 at a given index
 * @n: pointer of an unsigned long int.
 * @index: index of the bit starting from 0 of the bit to be set
 *
 * Return: 1 if it worked, -1 if it didn't.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned int j;

	if (index >= 64)
		return (-1);

	j = 1 << index;
	*n = (*n | j);

	return (1);
}

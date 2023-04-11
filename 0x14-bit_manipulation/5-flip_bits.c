#include "main.h"

/**
 * flip_bits - the function returns the number of bits you would
 * need to flip to get from one number to another
 * @n: for first number 
 * @m: for second number
 *
 * Return: number of bits you would want to flip to another number
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int number_of_bits;

	for (number_of_bits = 0; n || m; n >>= 1, m >>= 1)
	{
		if ((n & 1) != (m & 1))
			nnumber_of_bits++;
	}

	return (number_of_bits);
}

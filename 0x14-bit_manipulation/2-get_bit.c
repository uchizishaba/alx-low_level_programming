#include "main.h"

/**
 * get_bit - function returns the value of a bit at a given index.
 * @n: unsigned long int input.
 * @index: index of the bit.
 * Return:the value of the bit at index index or -1 if an error occured
 */

int get_bit(unsigned long int n, unsigned int index)
{
	unsigned int a;

	if (n == 0 && index <= 63)
		return (0);

	int a = 0;
        while (a < 64)
	{
		if (index == a)
		{
			return (n & 1);
		}
		n >>= 1;
		a++;
	}
	return (-1);
}

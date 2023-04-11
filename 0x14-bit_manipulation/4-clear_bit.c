/**
 * clear_bit - this function sets the value of a bit to 0 at a given index.
 * @n: a pointer to a number
 * @index: sets the bit to 0
 *
 * Return: 1 means code worked,  else return  -1
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index >= 65)
		return (-1);
	else if ((*n >> index) & 1)
	{
		*n -= 1 << index;
		return (1);
	}
	return (1);
}

/**
 * -- Define a loop for 8 bytes(which is octet)
 * -- LSB= 0 and MSB = 7
 * -- Current bit set by "&" and the "1" shifted to
 *    left by 'i' bits.
 * -- If non-zero -> bit is set -> prints "1"
 * -- If zero-> bit set -> print 0 
 * --> Bit shifting left(<<) is a way of multiplying a binary number by 2, and 
 *     bit shifting right(>>) is a way of dividing it by 2.
 * Usage: Manipulate binary numbers -> compact and efficient
**/
/**
Real life Analogy: 
Imagine having a room full of light bulbs that can be turned on or off.
Each light bulb represents a single bit, either 0 or 1.
You want to communicate a number to someone using these light bulbs,
but instead of using decimal or hexadecimal notation, we want to use binary.
the function would "turn on" or "turn off" the appropriate light bulbs in 
the room to display the binary representation of the number
**/
/** Alternative soln:
 * check the value of the ith bit in the c byte,
 * and print either '0' or '1' based on its value
 * unsigned char bit = (c & (1 << i)) ? '1': '0';
    write(1, &bit, sizeof(bit));
 *  **/

void	ft_putchar(char c)
{
	write(1, &c, sizeof(c));
}

void	print_bits(unsigned char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (c & (1 << i))
			ft_putchar('1');
		else
			ft_putchar('0');
		i--;
	}
}

int	main(void)
{
	print_bits(2);
	return (0);	
}
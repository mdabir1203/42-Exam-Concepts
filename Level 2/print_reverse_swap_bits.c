
/*      ------Print Bits------------------------ */ 
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

/*-------------------- Reverse Bits ---------------------*/
/**
Subject:
Write a function that takes a byte, reverses it, bit by bit (like the
example) and returns the result.

Reallife Analogy:
Just reversing the order of letters in a word changes the word's appearance 
without changing its meaning,
reversing the order of bits in an 8-bit integer changes its binary representation
without changing its numerical value.

/** Usage:
 *Cryptography: For encryption and random number generation, 
 *Data compression: For optimizing data storage
 *Digital signal processing: Implementing fast Fourier transforms and other signal processing algorithms efficiently.
**/


unsigned char reverse_bits(unsigned char octet)
{
	int i = 7;
	unsigned char res = 0;

	while (i >= 0)
	{
		res = res * 2 + (octet % 2);
		octet = octet / 2;
		i--;
	}
	return (res);
}


/*-------------------- Swap Bits ---------------------*/
/**
Subject:
Write a function that takes a byte, swaps its halves (like the example) and
returns the result.
**/
/**
Real Life Analogy:
Assume you have a deck of cards, and you want to swap the top and bottom halves.
Divide the deck in half, placing the top half on a table 
and holding the bottom half in your hand. 
The top half would be placed on top of the half in your hand,
effectively swapping their positions.
To complete the swap, you would place the new "top" half on the table.
*/

unsigned char	swap_bits(unsigned char octet)
{
	return ((octet >> 4) | (octet << 4));
}

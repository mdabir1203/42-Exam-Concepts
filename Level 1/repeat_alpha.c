/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:36:24 by galpers           #+#    #+#             */
/*   Updated: 2023/03/30 02:41:44 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
Assignment name  : repeat_alpha
Expected files   : repeat_alpha.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program called repeat_alpha that takes a string and display it
repeating each alphabetical character as many times as its alphabetical index,
followed by a newline.

'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...

Case remains unchanged.

If the number of arguments is not 1, just display a newline.

Examples:

$>./repeat_alpha "abc"
abbccc
$>./repeat_alpha "Alex." | cat -e
Alllllllllllleeeeexxxxxxxxxxxxxxxxxxxxxxxx.$
$>./repeat_alpha 'abacadaba 42!' | cat -e
abbacccaddddabba 42!$
$>./repeat_alpha | cat -e
$
$>
$>./repeat_alpha "" | cat -e
$
$>  
**/

/* Real life Analogy/ Usage 
 * 
A headline might have the first letter of each word
emphasized or bolded to draw the reader's attention,
while the body text might have each letter emphasized 
a number of times based on its position in the alphabet. 
This could make the text more visually interesting 
and engaging for the reader.

Alternatively,
This program could be used in typography or graphic design to create interesting
and visually striking text effects, where each letter 
is repeated a different number of
times based on its position in the alphabet.

*/

#include <unistd.h>

int	main(int ac, char **av)
{
	int i;
	int k;
	char *str;

	i = 0;
	k = 1;
	if (ac ==2)
	{
		str = av[1];
		while (str[i] != '\0')
		{
			k = 1;
			if (str[i] >= 'A' && str[i] <= 'Z')
				k = str[i] - 64; // ascii compare to repeat 
			if (str[i] >= 'a' && str[i] <= 'z')
				k = str[i] - 96;
			while (k-- >= 1) // character repeat based on index
			{
				write(1, &str[i], 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}



/* Optimized soln
- for loop, k is initialized to determine the current character is uppercase or lowercase. 
  For uppercase characters, its value is the character's ASCII value minus 64, for lowercase characters, 
  the value is the character's ASCII value minus 96.
- A while loop is used to repeat (the current character * k ).
- Putchar function is used. It is efficient for single char output.
- Combines 2 if statement to a ternary operator
**/

#include <stdio.h>
ft_putchar(char c)
{
	write(1, c, 1);
}
int main(int ac, char **av)
{
	if(ac != 2)
		return (1);
	char *str = av[1];
	int i = 0;
	while (str[i] != '\0')
	{
		int j = str[i] >= 'a' ? str[i] - 96 : str[i] -  64; // Ascii comparison for lower/uppercase
		while (j--)
			ft_putchar(str[i]);
		i++; // Outer while loop increase -> next char in input string processed.
	}
	ft_putchar('\n');
	return (0);
}

/** 
Concept Solution:
Imagine writing a letter to a friend, 
and realize you made a mistake in the last sentence. 
Either you could start over and rewrite the entire letter,
or you could use a pen to cross out the last sentence 
and write the correction above it.
The second option would be quicker and more efficient.

Usage: Mirrored message / Display countdown timer
 */

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		int	i;
		char *str;

		str = av[1];
		i = 0;
		while(str[i] != '\0')
			i++;
		while (i >= 1)
		{
			write(1, &str[i - 1], 1);
			i--;
		}
	}
	write(1, "\n", 1);
	return (0);
}

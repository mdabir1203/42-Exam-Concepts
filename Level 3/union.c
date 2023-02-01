#include <unistd.h>

/**
 Assignment name  : union
Expected files   : union.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in either one of the strings.

The display will be in the order characters appear in the command line, and
will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Example:

$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
$
$>

 Optimized soln using hash map : 
 * The program first checks if the number of command line arguments is equal to 3 (argc == 3). If not, it immediately exits and returns 0.
It creates an array of size 255, called ascii, and initializes all of its elements to 0. This array will be used to keep track of the characters that have appeared in the strings.
The program then enters a for loop that iterates through each of the two strings passed as command line arguments.
Inside the for loop, there is another while loop that iterates through each character of the current string.
For each character, the program checks if the corresponding element in the ascii array is equal to 0. If it is, it means that the character has not appeared yet, so the program marks the corresponding element in the ascii array as 1 and writes the character to the standard output using the write function.
The program then ends with a newline character and returns 0.
**/

int main(int ac,char **av)
{
	if (ac == 3)
	{
		int ascii[255] = {0}; // keep track of chars appeared in strings
		for(int i = 0;i < 3;i++)
		{
			int j = 0;
			while(av[i][j])
			{
				if (ascii[av[i][j]] == 0)
				{
					ascii[av[i][j]] = 1;
					write(1, &av[i][j], 1);
				}
				j += 1;
			}
		}
		write(1, "\n", 1);
		return (0);
	}
}


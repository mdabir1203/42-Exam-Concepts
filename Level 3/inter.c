/** Assignment name  : inter
Expected files   : inter.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in both strings, in the order they appear in the first
one.

The display will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Examples:

$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padinto$
$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6ewg4$
$>./inter "rien" "cette phrase ne cache rien" | cat -e
rien$
$>./inter | cat -e
$


Optimized Solution Concepts:
   You can use a hash table or a set to store the characters 
   that have already been added to the result string.
   This would allow you to check if a character has already been added in O(1) time,
   as opposed to O(n) time with the current 
   approach of iterating through the result string.
**/

#include <unistd.h>
#include <string.h>
#include <stdbool.h>

void common_chars(char *s1, char *s2)
{
	int i = 0;
	bool seen[256] = {false};
	char res[strlen(s1)];
	int res_ind = 0;
	while (s1[i])
	{
		if(!seen[s1[i]] && strchr(s2, s1[i]))
		{
			seen[s1[i]] = true;
			res[res_ind++] = s1[i];
		}
		i++;
	}
	res[res_ind] = '\0';
	write(1, res, strlen(res));
	write(1, "\n", 1);
}



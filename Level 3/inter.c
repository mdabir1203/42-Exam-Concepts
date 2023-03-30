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


Intutive solution:

Imagine you're at a party with two guests,
and you're trying to figure out if they have any favorite clubs in common. 
The first guest tells you their favorite clubs,
and you write them down on a list. Then, you go to the second guest
and ask if they also like any of the clubs on the list. If they do,
you write it down on a separate list.
a)Takes in two strings as input, which are like the lists of
clubs from the two guests.
b)It starts by setting up an empty list of seen clubs,
which is like an empty array of 256 spots (one spot for each possible club).
Then, it looks at each club on the first list, one by one.
For each club on the first list, it checks if it's already been seen before
by looking in the seen clubs list.
If it hasn't been seen before, it checks if the second guest also likes 
that club. If they do, it writes the club down on a separate list
(which is like the "res" string in the code). 
Finally, it prints out the list of common clubs 
(like writing down the list of clubs on a piece of paper and
 showing it to the guests).

**/

#include <unistd.h>
#include <string.h>
#include <stdbool.h>

char *ft_strchr(const char *s, int c) {
    while (*s != '\0')
	{
        if (*s == c) {
            return (char *)s;
        }
        s++;
    }
    if (*s == c) {
        return (char *)s;
    }
    return NULL;
}

void	common_chars(char *s1, char *s2)
{
	int i = 0;
	bool seen[256] = {false};
	char res[strlen(s1)];
	int res_ind = 0;
	while (s1[i])
	{
		if(!seen[(int)s1[i]] && strchr(s2, s1[i]))
		{
			seen[(int)s1[i]] = true;
			res[res_ind++] = s1[i];
		}
		i++;
	}
	res[res_ind] = '\0';
	write(1, res, strlen(res));
	write(1, "\n", 1);
}

int	main(int ac, char **av)
{
	if (ac != 3)
		write(1, "\n", 1);
	common_chars(av[1], av[2]);
	return (0);
}

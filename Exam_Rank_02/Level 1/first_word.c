/**
Write a program that takes a string and displays its first word, followed by a
newline.

A word is a section of string delimited by spaces/tabs or by the start/end of
the string.

If the number of parameters is not 1, or if there are no words, simply display
a newline.

**/

/* Real life Analogy:
By ignoring any leading whitespace characters (spaces or tabs)
and then printing characters until it reaches the 
first whitespace or the end of the string.
*/

#include <unistd.h>

int main(int ac, char **av)
{
    int i = 0;
    char *str = av[1];
    if (ac == 2)
    {
        while(str[i] == 32 || str[i] == 9)
            i++;
        while (str[i] != 32 && str[i] != 9 && str[i])
        {
            write(1, &str[i], 1);
            i++;
        }
        write(1, "\n", 1);
    }
    return (0);
}

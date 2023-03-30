/*
ROT13 Transformation:

the ROT13 transformation on it by subtracting 'a' from the character
to get its 0-based position in the alphabet,
adding 13 to this position to get the new position,
then the result modulo 26 to wrap around if necessary,
and finally adding 'a' back to get the new character.
The resulting character is 
then assigned back to the same position in the input string.

*/

#include <unistd.h>


int main(int ac,char **av)
{
    int i = 0;
    char *str = av[1];

    if (ac > 1)
    {
        while (str[i] != '\0')
        {
            if (str[i] >= 'a' && str[i] <= 'z')
                str[i] = (str[i] - 'a' + 13) % 26 + 'a';
            else if (str[i] >= 'A' && str[i] <= 'Z')
                str[i] = (str[i] - 'A' + 13) % 26 + 'A';
            write(1, &av[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
    
}
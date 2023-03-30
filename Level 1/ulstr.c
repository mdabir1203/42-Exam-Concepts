/**
 * Write a program that takes a string and reverses the case of all its letters.
Other characters remain unchanged.

You must display the result followed by a '\n'.

If the number of arguments is not 1, the program displays '\n'
*/

/**
 * A real-life analogy of this program could be a translator 
 * that converts all words in a sentence from one language
 *  to another. 
 * Just like the program converts uppercase letters to lowercase 
 * and lowercase letters to uppercase, 
 * a translator can convert words from one language to another.
 * For example, if the input sentence is in French, 
 * the translator can convert it to English or any other language.
 */

#include<unistd.h>

int main(int ac,char **av)
{
    int i = 0;
    char *str = av[1];
    if (ac == 2)
    {
        while (str[i] != '\0')
        {
            if (str[i] >= 'a' && str[i] <= 'z')
                str[i] -= 32;
            else if (str[i] >= 'A' && str[i] <= 'Z')
                str[i] += 32;
            write(1, &str[i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
}
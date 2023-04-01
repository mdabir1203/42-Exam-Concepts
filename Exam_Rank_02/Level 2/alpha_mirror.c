/**
Write a program called alpha_mirror that takes a string and displays this string
after replacing each alphabetical character by the opposite alphabetical
character, followed by a newline.

'a' becomes 'z', 'Z' becomes 'A'
'd' becomes 'w', 'M' becomes 'N'
and so on.
Case is not changed.
If the number of arguments is not 1, display only a newline.
**/

/**
Alpha_mirror displays the result of applying the opposite transformation
to a string.

Imagine that you have a message written in a secret code 
where each letter is replaced with its opposite letter
in the alphabet (e.g. 'a' becomes 'z', 'b' becomes 'y', etc.).
To read the message, you need to apply the opposite transformation and replace each letter with its opposite again. 
*/

int main(int ac, char **av)
{
    if (ac != 2)
    {
        write(1, "\n", 1);
        return (0);
    }
    char *str = av[1];
    while (*str)
    {
        if (*str >= 'a' && *str <= 'z')
            *str = 'z' - (*str - 'a');
        else if (*str >= 'A' && *str <= 'Z')
            *str = 'Z' - (*str - 'A');
        write(1, str, 1);
        str++;
    }
    write(1, "\n", 1);
    return (0);
}

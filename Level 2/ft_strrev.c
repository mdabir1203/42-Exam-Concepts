/**
 * 'ft_strrev' function, the input string 'str' is like 
 * the row of books on the shelf. 
 * The function uses a while loop to find the length
 *  of the string, which
 *  is like counting the number of books on the shelf.

The function then uses another while loop to swap 
the characters at the beginning and end of the string, and move towards the middle of the string. 
This is like swapping the positions of the 
first and last books on the shelf, and then moving 
towards the middle of the row to swap the positions 
of the second and second-to-last books, and so on.
*/

char *ft_strrev(char *str)
{
    int i = -1;
    int len = 0;
    char temp;

    while (str[len])
        len++;
    while (i < len /2)
    {
        temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 -i] = temp;
    }
    return (str);
}

/**
 * Reads two strings s1 and s2 from the user, 
 * and passes them to the wdmatch function.
 *  The wdmatch function uses two variables i and j to keep track of the indices of the characters
 *  in s1 and s2, respectively. The function loops through the characters in s2 and increments j each time,
 *  but only increments i when the current characters in s1 and s2 are the same. If s1[i] 
 *  reaches the end of the string '\0', it means that all the characters in s1 have been found
 *  in s2 in the right order, and the function outputs s1 and returns 1. If s1[i] never reaches the end of the string, 
 *  it means that all the characters in s1 could not be found in s2 
 *  in the right order, and the function outputs a newline and returns 0.
**/

#include <string.h>
#include <unistd.h>

int wdmatch(const char *s1,const char *s2)
{
    int i =0, j = 0;
    while(s1[i] != '\0' && s2[j] != '\0')
    {
        if(s1[i] == s2[j])
            i++;
        j++;
    }
    if (s1[i] == '\0')
    {
        write(1, s1, strlen(s1));
        write(1, "\n", 1);
        return (1);
    }
    else
    {
        write(1,"\n", 1);
        return (0);
    }
    return (0);
}

int main(int ac,char **av)
{
    // if (ac == 2)
    //     wdmatch(av[1],av[2]);
    // else
    //     write(1,"\n",1);
    if (ac != 3)
    {
        write(1, "\n", 1);
        return (0);
    }
    else
        wdmatch(av[1],av[2]);
    return (0);
}

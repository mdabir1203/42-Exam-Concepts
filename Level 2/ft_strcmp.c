/* Remember to check for && which helps potential out of bound access

Reallife analogy would be:
->The first word that differs in the two lists,
if the "book, pen, pencil" and "book,eraser, pencil" lists are being compared, 
 the function would return "pen", 
 since it is the first word that differs.

 */

#include<stdio.h>

int ft_strcmp(char *s1, char *s2)
{
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
        i++;
    return (s1[i] - s2[i])
}

int ft_strcmp(char *s1, char *s2)
{
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
        i++;
    return (s1[i] - s2[i]);
}
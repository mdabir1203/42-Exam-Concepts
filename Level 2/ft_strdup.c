#include <stdlib.h>

char *ft_strdup(const char *s1)
{
    size_t len = 0;
    size_t i = 0;

    while (s1[len])
        len++;
    char *cpy = malloc(len + 1);
    if (cpy != NULL)
    {
        while (i <= len)
            cpy[i] = s1[i];
    }
    return (cpy);
}
/**
 * Implementation: pointers instead of array indexing to access 
 * the chars of input. 
 * Makes the code a bit faster and more compact.
 * -> p->  starts at the beginning of s 
 * -> moves forward as the current character is not in reject.
 * -> q pointer starts at the beginning of reject
 * -> moves forward as the current character does not match current char of s.
 * -> When q reaches the end of reject / finds a match, loop breaks
 * -> p is returned minus the initial address of s.
 * N:B: Assuming both s and reject are valid strings. If either of them is NULL, the behavior of the function
 *      is undefined.
 **/

size_t ft_strcspn(const char *s, const char *reject)
{
    const char *p = s;
    while (*p)
    {
        const char *q = reject;
        while (*q && *q != *p)
            q++;
        if (*q)
            break;
        p++;
    }
    return (p - s);
}

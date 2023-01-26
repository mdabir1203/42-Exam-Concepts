/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:21:34 by galpers           #+#    #+#             */
/*   Updated: 2023/01/26 23:08:25 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
- an O(1) lookup time for each character, more efficient than the standard library implementation, 
which uses a linear search to check if a character is in the charset.
Creates significant difference in performance for large inputs
or when the function is called multiple times.
- it doesn't require the charset to be null-terminated, which makes it more robust and less prone to errors.
- size_t data type to return the number of characters in the initial segment of the string which consists of only characters from the specified set, it's a good practice to use size_t when working with sizes of objects or arrays in C.
**/
size_t ft_strcspn(const char *s, const char *charset)
{
    size_t i;
    int char_set[256] = {0};
    //fillup the array with chars in charset
    for(i = 0; charset[i] != '\0';i++)
    {
        char_set[(unsigned char)charset[i]] = 1;
    }
    // iterate through the string s to check if character is in charset
    for(i = 0;s[i] != '\0';i++)
    {
        if(!char_set[(unsigned char)s[i]])
            break;
    }
    return (i);
}

int	main(void)
{
	printf("%lu\n", ft_strcspn("test", "es"));
 	printf("%lu\n", strcspn("test", "es"));
	 printf("%lu\n", ft_strcspn("test", "f"));
 	printf("%lu\n", strcspn("test", "f"));
}
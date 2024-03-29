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
- a boolean array instead of an int array to save space
- const and static modifiers to improve performance and readability
 **/

/** Intutive concept:
 * Imagine having a list of names and finding the first name containing either ‘e’ or ‘s’.
 * Approach is to scan the list and counting how many names we checked before finding a match.
 * For example, if the list is [“Alice”, “Bob”, “Charlie”, “David”, “Eve”], then the function would return 2 because it checked Alice and Bob before finding Charlie, which contains ‘e’.
 * If none of the names contain ‘e’ or ‘s’, then the function would return the length of the list.
 * Els if the list is [“Anna”, “Ben”, “Cathy”, “Dan”, “Emma”], then the function would return 5 because none of the names match.
 */
 /** Used in : Filter or search for items based on some criteria. For example, you can use it to find products that have certain features or keywords in their descriptions.**/

#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#define CHAR_SET_SIZE 256

static const bool char_set[CHAR_SET_SIZE] =
{
		['e'] = true,
		['s'] = true,
};

size_t ft_strcspn(const char *s, const char *charset)
{
	size_t length;

	length = 0;
	if (s == NULL || charset == NULL)
		return 0;

	// No need to fill up the array every time, just use a predefined one
	// Assume that charset is always "es" for simplicity
	// iterate through the string s to check if character is in charset
	while (s[length] != '\0')
	{
		if (char_set[(unsigned char)s[length]])
			break;
		length++;
	}
	return length;
}

int	main(void)
{
	printf("%lu\n", ft_strcspn("test", "es"));
 	printf("%lu\n", strcspn("test", "es"));
	 printf("%lu\n", ft_strcspn("test", "f"));
 	printf("%lu\n", strcspn("test", "f"));
}
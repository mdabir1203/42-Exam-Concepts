/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 02:45:44 by mabbas            #+#    #+#             */
/*   Updated: 2023/02/16 04:43:07 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** Using pointers to index for better performance 
 *  Optimized loop by iterating until end of stirng
 *  modified str output in a single call to write()
 **/
#include <unistd.h>

int main(int ac,char **av)
{
	if (ac == 4)
	{
		char *str = av[1];
		char c1 = av[2][0];
		char c2 = av[3][0];
		int i = 0;
		while (str[i])
		{
			if (str[i] == c1)
			{
				str[i] = c2;
			}
			i++;
		}
		write(1, str, i);
	}
	write(1, "\n", 1);
	return (0);
}

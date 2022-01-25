/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imarushe <imarushe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 21:25:33 by imarushe          #+#    #+#             */
/*   Updated: 2022/01/24 22:07:28 by imarushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void print_memory(const void *addr, size_t size)
{
	unsigned char	*str;
	char			*base = "0123456789abcdef";
	char			line[17];
	size_t			i;
	int				j;
	int				nbr;

	i = 0;
	str = (unsigned char *)addr;
	while (i < size || i % 16 != 0)
	{
		if (i < size)
		{
			nbr = str[i] / 16;
			write(1, &base[nbr], 1);
			nbr = str[i] % 16;
			write(1, &base[nbr], 1);
			if (str[i] >= 32 && str[i] <= 126)
				line[i % 16] = str[i];
			else
				line[i % 16] = '.';
		}
		else
			write(1, "  ", 2);
		i++;
		if (i % 2 == 0)
			write(1, " ", 1);
		if (i % 16 == 0)
		{
			j = 0;
			while(j < 16 && !(i - 16 + j >= size))
			{
				write(1, &line[j], 1);
				j++;
			}
			write(1, "\n", 1);
		}
	}
}

int	main(void)
{
	int	tab[10] = {0, 23, 150, 255, 12, 16,  21, 42};

	print_memory(tab, sizeof(tab));
	return (0);
}

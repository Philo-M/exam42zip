/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imarushe <imarushe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:06:01 by imarushe          #+#    #+#             */
/*   Updated: 2022/01/24 15:37:03 by imarushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	if (c < 32 && c > 126)
		c = '.';
	write(1, &c, 1);
}

void	ft_puthex(int nbr)
{
	int	i;

	if (nbr > 15)
		ft_puthex(nbr / 16);
	i = nbr % 16;
	if (i > 10)
		i += 'a' - 10;
	ft_putchar(i);
}

void	print_memory(const void *addr, size_t size)
{
	size_t	i;
	size_t	temp;
	int		col;
	unsigned char	*str;

	str = (unsigned char *)addr;
	i = 0;
	temp = 0;
	while (i < size)
	{
		col = 0;
		temp = i;
		while (col < 16)
		{
			if (i < size)
			{
				if (str[i] < 16)
					ft_putchar('0');
				ft_puthex(str[i]);
			}
			else
				write(1, "  ", 2);
			ft_putchar((i++ & 1) << 6);
			col++;
		}
		i = temp;
		while (col < 16 && i < size)
		{
			ft_putchar(str[i]);
			i++;
			col++;
		}
		write(1, "\n", 1);
	}
}

int	main(void)
{
	int	tab[10] = {0, 23, 150, 255, 12, 16,  21, 42};

	print_memory(tab, sizeof(tab));
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imarushe <imarushe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:39:32 by imarushe          #+#    #+#             */
/*   Updated: 2022/01/24 15:52:49 by imarushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void print_memory(const void *addr, size_t size)
{
	const char *base = "0123456789abcdef";
	size_t i = 0;
	unsigned char *str = (unsigned char*)addr;
	char line[17];
	int nb;
	int j;

	//Tant que je suis inférieur à size OU que j'ai pas fini ma ligne
	while (i < size || i % 16 != 0)
	{
		//Si je suis inférieur à size
		if (i < size)
		{
			nb = str[i] / 16;
			ft_putchar(base[nb]);
			nb = str[i] % 16;
			ft_putchar(base[nb]);
			//Si c'est un caractere imprimable, je stocke, sinon '.'
			line[i % 16] = (str[i] >= 32 && str[i] <= 126) ?  str[i] : '.';
		}
		//Sinon je mets des espaces pour la derniere ligne
		else
			write(1, "  ", 2);
		i++;
		if (i % 2 == 0)
			write(1, " ", 1);;
		if (i % 16 == 0)
		{
			j = 0;
			while (j < 16)
			{
				//Si je ne suis pas a la fin du tableau
				//(i - 16 == debut de la ligne) + j pour savoir ou j'en suis
				//dans la derniere ligne
				if (i - 16 + j >= size)
					break ;
				ft_putchar(line[j]);
				j++;
			}
			ft_putchar('\n');
		}
	}
}

int	main(void)
{
	int	tab[10] = {0, 23, 150, 255, 12, 16,  21, 42};

	print_memory(tab, sizeof(tab));
	return (0);
}

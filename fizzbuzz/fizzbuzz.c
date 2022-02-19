/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buzz_fizz.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imarushe <imarushe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:58:42 by imarushe          #+#    #+#             */
/*   Updated: 2022/01/19 14:06:05 by imarushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_putnbr(int i)
{
	if (i > 9)
		ft_putnbr(i / 10);
	i = i % 10 + 48;
	write(1, &i, 1);
}

int	main(void)
{
	int	i;

	i = 1;
	while (i <= 100)
	{
		if (i % 3 != 0 && i % 5 != 0)
			ft_putnbr(i);
		if (i % 3 == 0)
			ft_putstr("buzz");
		if (i % 5 == 0)
			ft_putstr("fizz");
		write(1, "\n", 1);
		i++;
	}
	return (0);
}

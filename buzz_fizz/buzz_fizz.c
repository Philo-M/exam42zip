/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buzz_fizz.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imarushe <imarushe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 08:42:59 by imarushe          #+#    #+#             */
/*   Updated: 2022/01/19 08:47:35 by imarushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_put_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_put_nbr(int i)
{
	if (i > 9)
		ft_put_nbr(i / 10);
	i = i % 10 + 48;
	write(1, &i, 1);
}

int	main(void)
{
	int	i;

	i = 1;
	while (i <= 100)
	{
		if (i % 4 != 0 && i % 7 != 0)
			ft_put_nbr(i);
		if (i % 4 == 0)
			ft_put_str("buzz");
		if (i % 7 == 0)
			ft_put_str("fizz");
		write(1, "\n", 1);
		i++;
	}
	return (0);
}

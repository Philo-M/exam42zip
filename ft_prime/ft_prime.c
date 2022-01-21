/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prime.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imarushe <imarushe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 10:44:13 by imarushe          #+#    #+#             */
/*   Updated: 2022/01/20 11:17:05 by imarushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_atoi(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = 10 * result + (str[i] - 48);
		i++;
	}
	return (result);
}

void	ft_putnbr(int	i)
{
	if (i > 9)
		ft_putnbr(i / 10);
	i = i % 10 + 48;
	write(1, &i, 1);
}

int	main(int argc, char *argv[])
{
	int	i;
	int	nbr;
	int	first;
	int	rest;

	i = 1;
	rest = 1;
	if (argc == 2)
	{
		nbr = ft_atoi(argv[1]);
		first = nbr;
		if (nbr == 1)
		{
			write(1, &nbr, 1);
			return (0);
		}
		while (nbr % i >= 0)
		{
			if (nbr % i == 0)
			{
				ft_putnbr(i);
				nbr /= i;
				rest = rest * i;
				if (rest == first)
					return (0);
				else
					write(1, "*", 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

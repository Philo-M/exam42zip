/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_diam.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imarushe <imarushe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:05:50 by imarushe          #+#    #+#             */
/*   Updated: 2022/02/16 09:38:04 by imarushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

static int	result;

int	ft_atoi(char **str)
{
	
	int nbr;

	nbr = 0;
	while (**str >= '0' && **str <= '9')
	{
		nbr = nbr * 10 + **str - 48;
		(*str)++;
	}
	if (**str)
		(*str)++;
	return (nbr);
}

void	ft_putnbr(int nbr)
{
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	nbr = nbr % 10 + 48;
	write(1, &nbr, 1);
}

int	ft_max(char *str)
{
	int	max;
	int	nbr;

	max = 0;
	while (*str)
	{
		nbr = ft_atoi(&str);
		if (nbr > max)
			max = nbr;
	}
	return (max);
}

void ft_path(int max, int matrix[max][max], int chain[max], int step, int length)
{
	int	i;

	i = 0;
	chain[step] = 1;
	while (i < max)
	{
		if (!chain[i] && matrix[step][i])
		{
			if (result < length + 1)
				result = length + 1;
			ft_path(max, matrix, chain, i, length + 1);
		}
		i++;
	}
	chain[step] = 0;
}

void	ft_matrix(int max, char *str)
{
	int	i;
	int	step;
	int	matrix[max][max];
	int	chain[max];

	step = 0;
	while (step < max)
	{
		i = 0;
		while (i < max)
		{
			matrix[step][i] = 0;
			i++;
		}
		step++;
	}
	i = 0;
	while (i < max)
	{
		chain[i] = 0;
		i++;
	}
	while (*str)
	{
		step = ft_atoi(&str);
		i = ft_atoi(&str);
		matrix[step][i] = 1;
		matrix[i][step] = 1;
	}
	result = 2;
	step = 0;
	while (step < max)
	{
		ft_path(max, matrix, chain, step, 1);
		step++;
	}
}


int	main(int argc, char *argv[])
{
	int	max;

	if (argc == 2)
	{
		max = ft_max(argv[1]);
		ft_matrix(max + 1, argv[1]);
		ft_putnbr(result);
	}
	write(1, "\n", 1);
	return (0);
}


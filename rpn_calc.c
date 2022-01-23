/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imarushe <imarushe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 18:00:28 by imarushe          #+#    #+#             */
/*   Updated: 2022/01/23 18:52:16 by imarushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	ft_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int ft_op(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
		return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	int		i;
	int		j;
	int		op;
	int		digit;
	int		a;
	int		b;
	char	*temp;

	i = 0;
	op = 0;
	digit = 0;
	a = 0;
	if (argc != 2)
		write(1, "Error\n", 6);
	else
	{
		while (argv[1][i])
		{
			while (argv[1][i] == 32)
				i++;
			if (ft_op(argv[1][i]))
				op++;
			else if (ft_digit(argv[1][i]))
				digit++;
			else
			{
				write(1, "Error\n", 6);
				return (1);
			}
			i++;
		}
		if (digit - 1 != op)
		{
			write(1, "Error\n", 6);
			return (1);
		}
		i = 0;
		while (argv[1][i])
		{
			if (!a)
			{
				while (argv[1][i] == 32)
					i++;
				if (ft_digit(argv[1][i]))
				{
					j = 0;
					while (ft_digit(argv[1][i + j]))
					{
						temp[j] = argv[1][i + j];
						argv[1][i + j] = 32;
						j++;
					}
					temp[j] = '\0';
					a = atoi(temp);
				}
			}
			while (argv[1][i] == 32)
				i++;
			if (ft_digit(argv[1][i]))
			{
				j = 0;
				while (ft_digit(argv[1][i + j]))
				{
					temp[j] = argv[1][i + j];
					argv[1][i + j] = 32;
					j++;
				}
				temp[j] = '\0';
				b = atoi(temp);
			}
			while (argv[1][i] == 32 || ft_digit(argv[1][i]))
				i++;
			if (ft_op(argv[1][i]))
			{
				if (argv[1][i] == '+')
					a += b;
				if (argv[1][i] == '-')
					a -= b;
				if (argv[1][i] == '*')
					a += b;
				if (argv[1][i] == '/')
					a /= b;
				if (argv[1][i] == '%')
					a %= b;
				argv[1][i] = 32;
			}
			i++;
		}
		printf("%d", a); 
	}
	return (0);
}





















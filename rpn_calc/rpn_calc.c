/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imarushe <imarushe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 18:00:28 by imarushe          #+#    #+#             */
/*   Updated: 2022/01/23 22:35:57 by imarushe         ###   ########.fr       */
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

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

int	main(int argc, char *argv[])
{
	int		i;
	int		j;
	int		k;
	int		op;
	int		digit;
	int		a;
	int		b;
	int		step;
	int		size;
	char	temp[256];

	i = 0;
	op = 0;
	digit = 0;
	step = 0;
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
		size = ft_strlen(argv[1]) - 1;
		i = size;
		printf("op %d, size %d, ", op, size);
		while (op)
		{
			while (op - step != 0)
			{
				while (!ft_op(argv[1][i]))
					i--;
				if (ft_op(argv[1][i]))
				{
					step++;
					i--;
				}
			}
			op--;
			printf("step %d, i %d\n", step, i);
			j = 0;
			if (!a)
			{
				
				while (!ft_digit(argv[1][i - j]))
					j++;
				if (ft_digit(argv[1][i - j]))
				{
					k = 0;
					while (ft_digit(argv[1][i - j]))
						j++;
					j--;
					printf("j %d\n", j);
					while (ft_digit(argv[1][i - j + k]))
					{
						temp[k] = argv[1][i - j + k];
						argv[1][i - j + k] = 32;
						k++;
					}
					temp[k] = '\0';
					a = atoi(temp);
					printf("a %d, i %d\n", a, i); 
				}
			}
			j = 0;
			while (!ft_digit(argv[1][i - j]))
				j++;
			if (ft_digit(argv[1][i - j]))
			{
				k = 0;
				while (ft_digit(argv[1][i - j]))
					j++;
				j--;
				printf("j %d\n", j);
				while (ft_digit(argv[1][i - j + k]))
				{
					temp[k] = argv[1][i - j + k];
					argv[1][i - j + k] = 32;
					k++;
				}
				temp[k] = '\0';
				b = atoi(temp);
				printf("b %d, i %d\n", b, i);
			}
			printf("op %s\n", &argv[1][i]);
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
			printf("res %d\n", a);
			i = size;
		}
		printf("%d", a); 
	}
	return (0);
}





















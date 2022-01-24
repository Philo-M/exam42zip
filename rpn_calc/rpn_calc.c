/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imarushe <imarushe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 18:00:28 by imarushe          #+#    #+#             */
/*   Updated: 2022/01/24 11:27:16 by imarushe         ###   ########.fr       */
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
	int		swap;
	int		a;
	int		b;
	int		step;
	int		size;
	char	temp[256];

	i = 0;
	op = 0;
//	digit = 0;
//	step = 0;
	a = 0;
	if (argc != 2)
		write(1, "AError\n", 7);
	else
	{
		while (argv[1][i])
		{
			while (argv[1][i] == 32)
				i++;
			if (ft_op(argv[1][i]))
				op++;
			if (argv[1][i] != 32 && !ft_digit(argv[1][i]) && !ft_op(argv[1][i]))
			{
				write(1, "1Error\n", 7);
				return (1);
			}
			i++;
		}
/*		if (digit - 1 != op)
		{
			write(1, "2Error\n", 7);
			return (1);
		}*/
		size = ft_strlen(argv[1]) - 1;
		i = size;
		while (op)
		{
			step = 0;
			printf("start\n");
//			printf("op %d", op);
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
			i++;
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
			if (step == 1)
			{
				swap = a;
				a = b;
				b = swap;
				printf("a %d, b %d\n", a, b);
			}
			printf("ft_op %d, op %s, a %d, b %d\n", ft_op(argv[1][i]), &argv[1][i], a, b);
			if (ft_op(argv[1][i]))
			{
				if (argv[1][i] == '+')
				{
					printf("a %d, b %d\n", a, b);
					b += a;
				}
				if (argv[1][i] == '-')
					b -= a;
				if (argv[1][i] == '*')
					b *= a;
				if (argv[1][i] == '/')
					b /= a;
				if (argv[1][i] == '%')
					b %= a;
				argv[1][i] = 32;
			}
			a = b;
			printf("res %d, step %d, i %d, size %d, op %d, len %d, %s\n", b, step, i, size, op, ft_strlen(argv[1]), argv[1]);
			i = size;
			printf("end\n");
		}
		i = 0;
		while (argv[1][i])
		{
			if (argv[1][i] != 32)
				printf("Error\n");
		}
		printf("%d", b); 
	}
	return (0);
}





















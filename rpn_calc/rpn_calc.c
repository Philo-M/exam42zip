/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imarushe <imarushe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 18:00:28 by imarushe          #+#    #+#             */
/*   Updated: 2022/01/24 15:01:56 by imarushe         ###   ########.fr       */
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

int	ft_op(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '%')
	{
		if (!ft_digit(str[i + 1]))
			return (1);
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

long	*ft_polish_calc(char *str)
{
	int		i;
	int		j;
	long	*result;

	i = 0;
	j = 0;
	result = malloc(sizeof(long) * ft_strlen(str));
	if (!result)
		return (NULL);
	while (str[i])
	{
		while (!ft_op(&str[i]))
		{
			result[j] = atoi(&str[i]);
			j++;
			while (str[i] && str[i] != 32)
				i++;
			if (!str[i])
			{
				printf("Error\n");
				return (NULL);
			}
			while (str[i] == 32)
				i++;
		}
		if (j < 2)
		{
			printf("Error\n");
			return (NULL);
		}
		if (str[i] == '*')
			result[j - 2] = result[j - 2] * result[j - 1];
		if (str[i] == '+')
			result[j - 2] = result[j - 2] + result[j - 1];
		if (str[i] == '-')
			result[j - 2] = result[j - 2] - result[j - 1];
		if (str[i] == '/')
		{
			if (!result[j - 1])
			{
				printf("Error\n");
				return (NULL);
			}
			result[j - 2] = result[j - 2] / result[j - 1];
		}
		if (str[i] == '%')
		{
			if (!result[j - 1])
			{
				printf("Error\n");
				return (NULL);
			}
			result[j - 2] = result[j - 2] % result[j - 1];
		}
		i++;
		j--;
		while (str[i] == 32)
			i++;
	}
	if (j > 1)
	{
		printf("Error\n");
		return (NULL);
	}
	return (result);
}

int	main(int argc, char *argv[])
{
	long	*result;

	if (argc == 2 && argv[1][0])
	{
		result = ft_polish_calc(argv[1]);
		if (!result)
			return (1);
		printf("%ld\n", result[0]);
		free(result);
		return (0);
	}
	printf("Error\n");
	return (1);
}

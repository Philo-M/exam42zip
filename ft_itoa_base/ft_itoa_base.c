/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imarushe <imarushe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 10:02:34 by imarushe          #+#    #+#             */
/*   Updated: 2022/01/19 10:37:17 by imarushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_size(int value, int base)
{
	int	size;

	size = 0;
	while (value > 0)
	{
		value /= base;
		size++;
	}
	return (size);
}

char	*ft_strdup(char *str)
{
	int		i;
	int		size;
	char	*result;

	i = 0;
	size = 0;
	while (str[size])
		size++;
	result = malloc(sizeof(char) * size);
	if (!result)
		return (NULL);
	while (str[i])
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_itoa_base(int value, int base)
{
	int		size;
	int		minus;
	char	*result;
	char	temp[17] = "0123456789ABCDEF\n";

	minus = 0;
	if (!value)
		return (ft_strdup("0"));
	if (value == -2147483648 && base == 10)
		return (ft_strdup("-2147483648"));
	if (value < 0 && base == 10)
		minus = 1;
	if (value < 0)
		value *= -1;
	size = ft_size(value, base);
	size = size + minus;
	result = malloc(sizeof(char) * size);
	if (!result)
		return (NULL);
	result[size] = '\0';
	size--;
	while (size >= 0)
	{
		result[size] = temp[value % base];
		value /= base;
		if (!size && minus)
			result[size] = '-';
		size--;
	}
	return (result);
}

int	main(void)
{
	printf("%s\n", ft_itoa_base(-2147483648, 10));
	printf("%s\n", ft_itoa_base(-42, 10));
	printf("%s\n", ft_itoa_base(0, 10));
	printf("%s\n", ft_itoa_base(3648, 16));
	printf("%s\n", ft_itoa_base(3648, 4));
	return (0);
}

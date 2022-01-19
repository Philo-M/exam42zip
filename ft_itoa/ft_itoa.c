/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imarushe <imarushe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:48:04 by imarushe          #+#    #+#             */
/*   Updated: 2022/01/19 16:06:27 by imarushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_nbrlen(int nbr)
{
	int	size;

	size = 0;
	while (nbr > 0)
	{
		nbr /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int nbr)
{
	char	*result;
	int		size;
	int		minus;
	
	minus = 0;
	if (nbr == -2147483648)
	{
		result = malloc(sizeof(char) * 12);
		if (!result)
			return (NULL);
		result = "-2147483648\0";
		return (result);
	}
	if (!nbr)
	{
		result = malloc(sizeof(char) * 2);
		if (!result)
			return (NULL);
		result = "0\0";
		return (result);
	}
	if (nbr < 0)
	{
		minus = 1;
		nbr *= -1;
	}
	size = ft_nbrlen(nbr);
	size = size + minus;
	result = malloc(sizeof(char) * size);
	if (!result)
		return (NULL);
	result[size] = '\0';
	size--;
	while (size >= 0)
	{
		result[size] = nbr % 10 + 48;
		nbr /= 10;
		if (size == 0 && minus)
			result[size] = '-';
		size--;
	}
	return (result);
}

int	main(void)
{
	printf("%s\n", ft_itoa(-2147483648));
	printf("%s\n", ft_itoa(-42));
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(21));
	printf("%s\n", ft_itoa(3648));
	printf("%s\n", ft_itoa(2147483647));
	return (0);
}

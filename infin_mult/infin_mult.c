/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infin_mult.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imarushe <imarushe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 22:08:59 by imarushe          #+#    #+#             */
/*   Updated: 2022/02/11 05:52:09 by imarushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

int	ft_mult(char *s1, char *s2)
{
	int		i;
	int		j;
	int		len1;
	int		len2;
	int		size;
	int		minus1;
	int		minus2;
	char	*result;

	minus1 = 0;
	minus2 = 0;
	if (s1[0] == '-')
		minus1 = 1;
	if (s2[0] == '-')
		minus2 = 1;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);

	if (s1[0] != '0' && s2[0] != '0')
	{
		size = len1 - minus1 + len2 - minus2;
		result = malloc(sizeof(char) * (size + 1));
		if (!result)
			return (0);
		result[size] = '\0';
		i = 0;
		while (i < size)
		{
			result[i] = 0;
			i++;
		}
		size--;
		len1--;
		len2--;

		i = 0;
		while (len2 - minus2 - i >= 0)
		{
			j = 0;
			while (len1 - minus1 - j >= 0)
			{
				result[size - i - j] += (s2[len2 - i] - 48) * (s1[len1 - j] - 48);
				if (result[size - i - j] > 9)
				{
					result[size - i - j - 1] += result[size - i - j] / 10;
					result[size - i - j] %= 10;
				}
				j++;
			}
			i++;
		}
		if (minus1 - minus2)
			write(1, "-", 1);
		i = 0;
		while (result[i] == 0)
			i++;
		while(i <= size)
		{
			result[i] += 48;
			write(1, &result[i], 1);
			i++;
		}
		free(result);
	}
	else
		write(1, "0", 1);
	return (1);
}

int	main(int argc, char *argv[])
{
	if (argc == 3)
		ft_mult(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}



















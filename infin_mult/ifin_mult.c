/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifin_mult.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imarushe <imarushe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 20:29:19 by imarushe          #+#    #+#             */
/*   Updated: 2022/02/07 21:05:52 by imarushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

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

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	minus1 = 0;
	minus2 = 0;
	if (s1[0] == '-')
		minus1 = 1;
	if (s2[0] == '-')
		minus2 = 1;

	size = len1 - minus1  + len2 - minus2;
	result = malloc(sizeof(char) * size + 1);
	if (!result)
		return (0);
	i = 0;
	while (i <= size)
	{
		result[i] = 0;
		i++;
	}
	result[size] = '\0';
	size--;
	len1--;
	len2--;

	i = 0;
	while (len2 - i - minus2 >= 0)
	{
		j = 0;
		while (len1 - j - minus1 >= 0)
		{
			result[size - i - j] += (s1[len1 - j] - 48) * (s2[len2 - i] - 48);
			if (result[size - i - j] > 9)
			{
				result[size - i - j - 1] += result[size - i - j] / 10;
				result[size - i - j] %= 10;
			}
			j++;
		}
		i++;
	}

	i = 0;
	if (minus1 + minus2 == 1)
		write(1, "-", 1);
	while(result[i] == 0)
		i++;
	while (i <= size)
	{
		result[i] += 48;
		write(1, &result[i], 1);
		i++;
	}
	free (result);
	return (1);
}

int	main(int argc, char *argv[])
{
	if (argc == 3)
		ft_mult(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}








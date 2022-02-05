/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infin_mult.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imarushe <imarushe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 21:50:10 by imarushe          #+#    #+#             */
/*   Updated: 2022/02/05 20:52:15 by imarushe         ###   ########.fr       */
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

int	main(int argc, char *argv[])
{
	(void)argc;

	int		i;
	int		len1;
	int		len2;
	int		sum_len;
	int		size;
	int		minus1;
	int		minus2;
	char	*result;

	if (argv[1][0] == '0' || argv[2][0] == '0')
	{
		write(1, "0\n", 2);
		return (0);
	}

	len1 = ft_strlen(argv[1]);
	len2 = ft_strlen(argv[2]);

	minus1 = 0;
	minus2 = 0;
	if (argv[1][0] == '-')
	{
		minus1 = 1;
		len1--;
	}
	if (argv[2][0] == '-')
	{
		minus2 = 1;
		len2--;
	}

	sum_len = len1 + len2;
	result = malloc(sizeof(char) * (sum_len + 1));
	if (!result)
		return (0);
	result[sum_len] = '\0';
	i = 0;
	while (result[i] != '\0')
	{
		result[i] = 0;
		i++;
	}

	if (!minus2)
		len2--;

	i = 0;
	while (len2 - i >= minus2)
	{
		size = sum_len - 1 - i;
		len1 = ft_strlen(argv[1]) - 1;
		while (len1 >= minus1)
		{
			result[size] += (argv[1][len1] - 48) * (argv[2][len2 - i] - 48);
			if (result[size] > 9)
			{
				result[size - 1] += result[size] / 10;
				result[size] %= 10;
			}
			size--;
			len1--;
		}
		i++;
	}
	
	i = 0;
	if (minus1 + minus2  == 1)
		write(1, "-", 1);
	while (result[i] == 0)
		i++;
	while (i < sum_len)
	{
		result[i] += 48;
		write(1, &result[i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}

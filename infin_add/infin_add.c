/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infin_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imarushe <imarushe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 11:28:08 by imarushe          #+#    #+#             */
/*   Updated: 2022/02/07 11:22:11 by imarushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	main(int argc, char *argv[])
{

	(void)argc;
	int		i;
	int		len1;
	int		len2;
	int		res_len;

	int		minus1;
	int		minus2;
	char	*result;
	char	c1;
	char	c2;
	char	*s1;
	char	*s2;

	len1 = ft_strlen(argv[1]);
	len2 = ft_strlen(argv[2]);
	minus1 = 0;
	minus2 = 0;
	if (argv[1][0] == '-')
		minus1 = 1;
	if (argv[2][0] == '-')
		minus2 = 1;
	if (len2 >= len1)
		res_len = len2 - minus2 + 1;
	else
		res_len = len1 - minus1 + 1;
	result = malloc(sizeof(char) * (res_len + 1));
	if (!result)
		return (0);
	i = 0;
	while (i <= res_len)
	{
		result[i] = 0;
		i++;
	}
	result[res_len] = '\0';
	res_len--;
	len1--;
	len2--;

	i = 0;
	if (minus1 - minus2 == 0)
	{
		while (i < res_len)
		{
			if (i > len1 - minus1)
				c1 = 0;
			else 
				c1 = argv[1][len1 - i] - 48;
			if (i > len2 - minus2)
				c2 = 0;
			else
				c2 = argv[2][len2 - i] - 48; 

			result[res_len - i] += c1 + c2;
			if (result[res_len - i] > 9)
			{
				result[res_len - i - 1] += result[res_len - i] / 10;
				result[res_len - i] %= 10;
			}

			i++;
		}
	}
	else
	{
		if (len1 - minus1 > len2 - minus2)
		{
			s1 = argv[1];
			s2 = argv[2];
		}
		else if (len2 - minus2 > len1 - minus1)
		{
			s1 = argv[2];
			s2 = argv[1];
			minus1 = !minus1;
		}
		else
		{
			i = 0;
			while (argv[1][i + minus1] && argv[2][i + minus2])
			{
				if (argv[1][i + minus1] > argv[2][i + minus2])
				{
					s1 = &argv[1][0 + minus1];
					s2 = &argv[2][0 + minus2];
					break ;
				}
				else if (argv[2][i + minus1] > argv[1][i + minus2])
					{
					s1 = &argv[2][0 + minus2];
					s2 = &argv[1][0 + minus1];
					minus1 = !minus1;
					break ;
				}
				else
					i++;
			}
		}

		len1 = ft_strlen(s1) - 1;
		len2 = ft_strlen(s2) - 1;

		i = 0;
		while (i < res_len)
		{
			if (i > len1 - minus1)
				c1 = 0;
			else 
				c1 = s1[len1 - i] - 48;
			if (i > len2 - !minus1)
				c2 = 0;
			else
				c2 = s2[len2 - i] - 48; 
			result[res_len - i] += c1 - c2;
			if (result[res_len - i] < 0)
			{
				result[res_len - i - 1] += -1;
				result[res_len - i] += 10;
			}
			i++;
		}
	}

	i = 0;
	if (minus1)
		write(1, "-", 1);
	while(result[i] == 0)
		i++;
	while (i <= res_len)
	{
		result[i] += 48;
		write(1, &result[i], 1);
		i++;
	}
	write(1, "\n", 1);
	free(result);
	return (0);
}

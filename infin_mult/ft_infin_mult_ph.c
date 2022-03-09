/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_infin_mult.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmandel <pmandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:39:54 by pmandel           #+#    #+#             */
/*   Updated: 2022/02/23 15:01:08 by pmandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putstr_0(char *str)
{
	int	i = 0;

	while(str[i] && str[i + 1] && str[i] == '0')
		i++;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int	ft_strlen(char *str)
{
	int	i = 0;

	while (str[i])
		i++;
	return (i);
}

int	ft_isdg(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return(0);
}

char	*ft_infin_mult(char *s1, char *s2)
{
	char	*s;
	int		len1 = ft_strlen(s1);
	int		len2 = ft_strlen(s2);
	int		i;
	int		j;
	int		k = len1 + len2 - 1;
	int		sum;
	int		rest = 0;

	s = (char *)malloc(len1 + len2 + 1);
	if (s == NULL)
		return (0);
	s[len1 + len2] = '\0';
	while (k >= 0)
	{
		i = len1 - 1;
		sum = 0;
		while (i >= 0)
		{
			j = len2 - 1;
			while (j >= 0)
			{
				if (k - len1 - len2 + 1 == i + j - len1 - len2 + 2 \
					&& ft_isdg(s1[i]) && ft_isdg(s2[j]))
					sum = sum + (s1[i] - 48) * (s2[j] - 48);
				j--;
			}
			i--;
		}
		sum = sum + rest;
		s[k] = sum % 10 + 48;
		rest = sum / 10;
		k--;
	}
	if (((s1[0] == '-' && s2[0] != '-') || (s1[0] != '-' && s2[0] == '-')) \
			&& s1[0] != '0' && s2[0] != '0')
	{
		k++;
		while (s[k] == '0')
			k++;
		s[k - 1] = '-';
	}
	return (s);
}

int	main(int argc, char **argv)
{
	char	*s;

	(void)argc;
	s = ft_infin_mult(argv[1], argv[2]);
	ft_putstr_0(s);
	free(s);
	return (0);
}

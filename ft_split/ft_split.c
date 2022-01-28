/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imarushe <imarushe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 09:43:00 by imarushe          #+#    #+#             */
/*   Updated: 2022/01/28 11:45:07 by imarushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	**ft_split(char *str)
{
	int		i;
	int		j;
	int		k;
	char	**result;

	i = 0;
	j = 0;
	result = malloc(sizeof(char *) * 1000);
	if (!result)
		return (NULL);
	while (str[i])
	{
		while (str[i] && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
			i++;
		if (str[i] && !(str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		{
			k = 0;
			result[j] = malloc(sizeof(char) * 1000);
			if (!result[j])
				return (NULL);
			while (str[i] && !(str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
			{
				result[j][k] = str[i];
				k++;
				i++;
			}
			result[j][k] = '\0';
			j++;
		}
	}
	result[j] = NULL;
	return (result);
}

int	main(void)
{
	char	**result;
	char	*str;
	int		i;

	i = 0;
	str = "Thanks, I'm fine!";
	result = ft_split(str);
	while (result[i])
	{
		printf("%s\n", result[i]);
		i++;
	}
	return (0);
}

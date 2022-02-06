/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infin_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imarushe <imarushe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 11:28:08 by imarushe          #+#    #+#             */
/*   Updated: 2022/02/06 19:58:54 by imarushe         ###   ########.fr       */
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
//	printf("len1 %d, len2 %d, res_len %d\n", len1, len2, res_len);
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


//	printf("[0] %d, len %d, [last] %d, [11] %d\n", result[0], ft_strlen(result), result[ft_strlen(result) - 1], result[11]);

	i = 0;
	while(result[i] == 0)
		i++;
	while (result[i] != '\0')
	{
		result[i] += 48;
//		printf("i %d, [i] %d\n", i, result[i]);
		write(1, &result[i], 1);
		i++;
	}
	write(1, "\n", 1);
	free(result);
	return (0);
}

















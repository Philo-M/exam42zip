/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imarushe <imarushe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 09:07:20 by imarushe          #+#    #+#             */
/*   Updated: 2022/01/19 11:16:20 by imarushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_rrange(int start, int end)
{
	int				i;
	unsigned int	size;
	int				*result;

	size = 0;
	if (start == end)
	{
		result = malloc(sizeof(int));
		if (!result)
			return (NULL);
		result[0] = start;
		return (result);
	}
	if (start < end)
	{
		i = start;
		while (i <= end)
		{
			size++;
			i++;
		}
	}
	if (end < start)
	{
		i = end;
		while (i <= start)
		{
			size++;
			i++;
		}
	}
	result = malloc(sizeof(int) * size);
	if (!result)
		return (NULL);
	i = 0;
	if (end < start)
	{
		while (end <= start)
		{
			result[i] = end;
			i++;
			end++;
		}
	}
	if (end > start)
	{
		while (end >= start)
		{
			result[i] = end;
			i++;
			end--;
		}
	}
	return (result);
}

int	main(void)
{
	int	i;
	int	*arr;

	i = 0;
	arr = ft_rrange(-3, 3);
	while (i < 7)
	{
		printf("%d ", arr[i]);
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imarushe <imarushe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 14:53:01 by imarushe          #+#    #+#             */
/*   Updated: 2022/01/19 15:43:49 by imarushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int start, int end)
{
	int	i;
	int	size;
	int	*result;

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
			i++;
			size++;
		}
	}
	if (end < start)
	{
		i = end;
		while (i <= start)
		{
			i++;
			size++;
		}
	}
//	printf("%d\n", size);
	result = malloc(sizeof(int) * size);
	if (!result)
		return (NULL);
	i = 0;
	if (start < end)
	{
		while (start <= end)
		{
			result[i] = start;
			i++;
			start++;
		}
	}
	if (start > end)
	{
		while (start >= end)
		{
			result[i] = start;
			i++;
			start--;
		}
	}
	return (result);
}

int	main(void)
{
	int	i;
	int	*arr;

	i = 0;
	arr = ft_range(2, -2);
	while (i < 5)
	{
		printf("%d ", arr[i]);
		i++;
	}
	return (0);
}

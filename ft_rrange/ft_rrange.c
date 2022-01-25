/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imarushe <imarushe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 09:07:20 by imarushe          #+#    #+#             */
/*   Updated: 2022/01/25 16:12:23 by imarushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_rrange(int start, int end)
{
	long			my_start;
	long			my_end;
	long			temp;
	long			size;
	long			i;	
	int					*result;

	size = 0;
	my_start = (long)start;
	my_end = (long)end;
	if (start == end)
	{
		result = malloc(sizeof(int));
		if (!result)
			return (NULL);
		result[0] = start;
		return (result);
	}
	if (my_start < my_end)
	{
		temp = start;
		while (temp <= end)
		{
			size++;
			temp++;
		}
	}
	if (end < start)
	{
		temp = end;
		while (temp <= start)
		{
			size++;
			temp++;
		}
	}
	printf("size %lu\n", size);
	printf("int %ld, int * %ld, long %ld, long long %ld, unsigned long long %ld, size_t %ld\n", sizeof(int), sizeof(int *), sizeof(long), sizeof(long long), sizeof(unsigned long long), sizeof(size_t));
	result = (int *)malloc(sizeof(int) * size);
	if (!result)
		return (0);
	printf("allocated\n");
	i = 0;
	if (my_end < my_start)
	{
		while (my_end <= my_start)
		{
			result[i] = my_end;
			i++;
			my_end++;
		}
	}
	if (my_end > my_start)
	{
		while (my_end >= my_start)
		{
			printf("fill in <-, my end %ld, i %lu\n", my_end, i);
			result[i] = my_end;
			i++;
			my_end--;
		}
	}
	printf("finish");
	return (result);
}

int	main(void)
{
	int	i;
	int	*arr;

	i = 0;
	arr = ft_rrange(-2147483648, 2147483647);
	while (1)
	{
		printf("%d\n", arr[i]);
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imarushe <imarushe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 09:07:20 by imarushe          #+#    #+#             */
/*   Updated: 2022/01/27 15:23:19 by imarushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_rrange(int start, int end)
{
	long int		my_start;
	long int		my_end;
	size_t			size;
	size_t			i;	
	int				*result;
	
	my_start = (long int)start;
	my_end = (long int)end;
	if (my_end >= my_start)
		size = my_end - my_start + 1;
	else
		size = my_start - my_end + 1;
	result = (int *)malloc(sizeof(int) * size);
	if (!result)
		return (NULL);
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
	else if (my_end >= my_start)
	{
		while (my_end >= my_start)
		{
			result[i] = my_end;
			i++;
			my_end--;
		}
	}
	return (result);
}

int	main(void)
{
	int	i;
	int	*arr;

	i = 0;
	arr = ft_rrange(-15, 0);
	while (i < 40)
	{
		if (arr)
			printf("%d\n", arr[i]);
		else
			printf("Memory error\n");
		i++;
	}
	return (0);
}

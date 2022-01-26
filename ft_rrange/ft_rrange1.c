/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imarushe <imarushe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 09:07:20 by imarushe          #+#    #+#             */
/*   Updated: 2022/01/26 14:29:54 by imarushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int	*ft_rrange(int start, int end)
{
	long int		my_start;
	long int		my_end;
	size_t			size;
	size_t			i;	
	int				*result;

	clock_t			start_all;
	clock_t			finish_all;
	clock_t			finish_fillin;
	double			time;

	size = 2 * 2147483648;
	my_start = (long int)start;
	my_end = (long int)end;
	if (my_start == my_end)
	{	
		printf("equal start %ld, end %ld\n", my_start, my_end);
		result = malloc(sizeof(long int));
		if (!result)
			return (NULL);
		result[0] = my_start;
		return (result);
	}
	printf("size %lu\n", size);
	start_all = clock();
	result = (int *)malloc(sizeof(int) * (size + 2));
	if (!result)
		return (NULL);
	finish_all = clock();
	time = (double)(finish_all - start_all)/CLOCKS_PER_SEC;
	printf("allocated in %f sec.\n", time);
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
			result[i] = my_end;
			i++;
			my_end--;
		}
	}
	finish_fillin = clock();
	time = (double)(finish_fillin - finish_all)/CLOCKS_PER_SEC;
	printf("finish fillin in %f sec.\n", time);
	return (result);
}

int	main(void)
{
	int	i;
	int	*arr;

	i = 0;
	arr = ft_rrange(2147483647, -2147483648);
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

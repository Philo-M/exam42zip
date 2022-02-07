/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_diam.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imarushe <imarushe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:05:50 by imarushe          #+#    #+#             */
/*   Updated: 2022/02/07 16:41:36 by imarushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>


int	ft_read(int	max, char *str)
{
	int		i;
	int		j;
	
	int		k;
	int		size;

	int		*a;
	int		*b;

	i = 0;
	size = 0;
	while (str[i])
	{
		if (str[i] == '-')
			size++;
		i++;
	}

	a = (int *)malloc(sizeof(int) * size);
	if (!a)
		return (0);
	b = (int *)malloc(sizeof(int)* size);
	if (!b)
		return (0);

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == 32)
			i++;
		if (str[i] >= '0' && str[i] <= '9')
			a[j] = atoi(&str[i]);
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		if (str[i] == '-')
			i++;
		if (str[i] >= '0' && str[i] <= '9')
			b[j] = atoi(&str[i]);
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		j++;
	}
	
	k = 0;
	while (k < j)
	{
		printf("%d-%d ", a[k], b[k]);
		k++;
	}
	printf("\n");

	int	min_a = 2147483647;
	int	min_b = 2147483647;
	int	max_a = 0;
	int max_b = 0;

	k = 0;
	while(k < j)
	{
		if (a[k] < min_a)
			min_a = a[k];
		if (a[k] > max_a)
			max_a = a[k];
		if (b[k] < min_b)
			min_b = b[k];
		if (b[k] > max_b)
			max_b = b[k];
		k++;
	}
	printf("min_a %d, max_a %d, min_b %d, max_b %d\n", min_a, max_a, min_b, max_b);









}

int	main(int argc, char *argv[])
{
	static int	max = 0;

	if (argc == 2)
	{
		ft_read(max, argv[1]);
	}
	return (0);
}








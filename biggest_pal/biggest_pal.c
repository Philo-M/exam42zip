/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biggest_pal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imarushe <imarushe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 10:38:08 by imarushe          #+#    #+#             */
/*   Updated: 2022/01/19 11:06:36 by imarushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int	i;
	int	start;
	int	end;
	int	max;
	int	big;

	i = 1;
	max = 1;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			start = i - 1;
			end = i + 1;
			while (start >= 0 && argv[1][end] != '\0' && argv[1][start] == argv[1][end])
			{
				if (end - start >= max)
				{
					max = end - start;
					big = start;
				}
				start--;
				end++;
			}
			start = i - 1;
			end = i;
			while (start >= 0 && argv[1][end] != '\0' && argv[1][start] == argv[1][end])
			{
				if (end - start >= max)
				{
					max = end - start;
					big = start;
				}
				start--;
				end++;
			}
			i++;
		}
		printf("big %d, max %d\n", big, max);
		i = 0;
		while (i <= max)
		{
			write(1, &argv[1][big + i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

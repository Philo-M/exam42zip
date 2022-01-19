/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imarushe <imarushe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 08:59:49 by imarushe          #+#    #+#             */
/*   Updated: 2022/01/19 09:05:50 by imarushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int		i;
	char	temp[256] = {0};

	i = 0;
	if (argc == 3)
	{
		while (argv[1][i])
		{
			if (!temp[(int)argv[1][i]])
			{
				temp[(int)argv[1][i]] = 1;
				write(1, &argv[1][i], 1);
			}
			i++;
		}
		i = 0;
		while (argv[2][i])
		{
			if (!temp[(int)argv[2][i]])
			{
				temp[(int)argv[2][i]] = 1;
				write(1, &argv[2][i], 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

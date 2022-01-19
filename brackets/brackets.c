/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imarushe <imarushe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:09:09 by imarushe          #+#    #+#             */
/*   Updated: 2022/01/19 16:29:34 by imarushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_is_close(char left, char right)
{
	if (left == '(' && right == ')')
		return (1);
	else if (left == '{' && right == '}')
		return (1);
	else if (left == '[' && right == ']')
		return (1);
	else
		return (0);
}

int	main(int argc, char *argv[])
{
	int		i;
	int		j;
	int		open;
	char	left[256];

	i = 1;
	if (argc > 1)
	{
		while (argv[i])
		{
			open = 0;
			j = 0;
			while (argv[i][j])
			{
				if (open && ft_is_close(left[open], argv[i][j]))
					open--;
				if (argv[i][j] == '(' || argv[i][j] == '{' || argv[i][j] == '[')
				{
					open++;
					left[open] = argv[i][j];
				}
				j++;
			}
			if (open)
				write(1, "Error\n", 6);
			else
				write(1, "OK\n", 3);
			i++;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}

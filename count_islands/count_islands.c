/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_islands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imarushe <imarushe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 10:57:55 by imarushe          #+#    #+#             */
/*   Updated: 2022/01/28 15:09:12 by imarushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

char	**ft_split(char *str)
{
	int		i;
	int		j;
	int		k;
	char	**result;

	i = 0;
	j = 0;
	result = malloc(sizeof(char *) * 1000);
	if (!result)
		return (NULL);
	while (str[i])
	{
		while (str[i] && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
			i++;
		if (str[i] && !(str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		{
			k = 0;
			result[j] = malloc(sizeof(char) * 1000);
			if (!result[j])
				return (NULL);
			while (str[i] && !(str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
			{
				result[j][k] = str[i];
				k++;
				i++;
			}
			result[j][k] = '\0';
			j++;
		}
	}
	result[j] = NULL;
	return (result);
}

char	**ft_read(char *file)
{
	int		fd;
	char	*buffer;
	char	**result;

	buffer = malloc(sizeof(char) * 1024 * 1000);
	if (!buffer)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	read(fd, buffer, 1024000);
	result = ft_split(buffer);
	free(buffer);
	return (result);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_fillin(int i, int j, int x, int y, char **map, int ile)
{
	map[i][j] = ile + 48;
	if (i > 0 && map[i - 1][j] == 'X')
		ft_fillin(i - 1, j, x, y, map, ile);
	if (j > 0 && map[i][j - 1] == 'X')
		ft_fillin(i, j - 1, x, y, map, ile);
	if (i + 1 < y && map[i + 1][j] == 'X')
		ft_fillin(i + 1, j, x, y, map, ile);
	if (j + 1 < x && map[i][j + 1] == 'X')
		ft_fillin(i, j + 1, x, y, map, ile);
}

int	main(int argc, char *argv[])
{
	char	**map;
	int		x;
	int		y;
	int		i;
	int		j;
	int		ile;


	i = 0;
	y = 0;
	ile = 0;
	if (argc == 2)
	{
		map = ft_read(argv[1]);
		x = ft_strlen(map[y]);
		while (map[y])
		{
			if (ft_strlen(map[y]) != x)
			{
				write(1, "\n", 1);
				return (1);
			}
			y++;
		}
		printf("x %d, y %d\n", x, y);
		
		while(ile < 10)
		{
			while (i < y)
			{
				j = 0;
				while (j < x)
				{
					while(map[i][j] == '.' || map[i][j] <= ile + 48)
						j++;
					printf("j afer '.' %d\n", j);
					if (map[i][j] == 'X')
						ft_fillin(i, j, x, y, map, ile);
					j++;
				}
				i++;
			}
			ile++;
		}
		i = 0;
		while (map[i])
		{
			printf("%s\n", map[i]);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

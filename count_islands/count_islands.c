/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_islands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imarushe <imarushe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 10:57:55 by imarushe          #+#    #+#             */
/*   Updated: 2022/02/08 18:01:15 by imarushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

char	**ft_split(char *str, int x, int y)
{
	int		i;
	int		j;
	int		k;
	char	**result;

	i = 0;
	j = 0;
	result = malloc(sizeof(char *) * (y + 1));
	if (!result)
		return (NULL);
	while (str[i])
	{
		while (str[i] && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
			i++;
		if (str[i] && !(str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		{
			k = 0;
			result[j] = malloc(sizeof(char) * (x + 1));
			if (!result[j])
			{
				while (j-- >= 0)	
					free(result[j]);
				free(result);
				return (NULL);
			}
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

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
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

int	ft_count(char *file)
{
	char	**map;
	char	*buffer;
	size_t	size;
	int		bread;
	int		x;
	int		y;
	int		i;
	int		j;
	int		fd;
	int		ile;
	
	// Determine size of the file, allocate buffer and read the file
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	buffer = malloc(sizeof(char) * 4096);
	if (!buffer)
		return (0);
	size = 0;
	while ((bread = read(fd, buffer, 1)) > 0)
		size += bread;
	free(buffer);
	close(fd);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	printf("size %ld\n",size);	
	buffer = malloc(sizeof(char) * (size + 1));
	if (!buffer)
		return (0);
	i = 0;
	while ((size_t)i <= size)
	{
		buffer[i] = 0;
		i++;
	}
	if (read(fd, buffer, size) <= 0)
	{
		free(buffer);
		return (0);
	}
	close(fd);

	// Calculate rows(x), columns(y) and check conditions
	x = 0;
	while (buffer[x] != '\n')
		x++;
	i = 0;
	y = 0;
	while (buffer[i])
	{
		if (buffer[i] != '.' && buffer[i] != 'X' && buffer[i] != '\n')
		{
			free(buffer);
			return (0);
		}
		if (buffer[i] == '\n')
		{
			y++;
			//printf("i %d, x %d, y %d, check %d\n", i, x, y, i-x*y-y+1);
			if(x && i-x*y-y+1)
			{
				free(buffer);
				return (0);
			} 	
		}
		i++;
	}

	// Keep the map int the array of arrays and free buffer
	map = ft_split(buffer, x, y);
	free(buffer);

	// Iterate over the islands (max 10), columns and rows 
	i = 0;
	ile = 0;
	while (ile < 10)
	{
		while (i < y) // && ile < 10) // keep 11th in 'X'
		{
			j = 0;
			while (j < x) //  && ile < 10) // keep 11th in 'X'
			{
				while (map[i][j] == '.' || (map[i][j] >= '0' && map[i][j] <= ile + 48))
					j++;
				if (map[i][j] == 'X')
				{
					/* Return an error if the map contains more then 10 islands
					if (ile == 10)
					{
						i = 0;
						while (map[i])
						{
							free(map[i]);
							i++;
						}
						free(map[i]);
						free(map);
						return (0);
					} */

					//Fillin the whole island
					ft_fillin(i, j, x, y, map, ile);
					ile++;
				}
				j++;
			}
			i++;
		}
		ile++;
	}
	// Print the map
	i = 0;
	while (map[i])
	{
		ft_putstr(map[i]);
		write(1, "\n", 1);
		i++;
	}
	// Free the array
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map[i]);
	free(map);
	return (1);
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		if (ft_count(argv[1]))
			return (0);
	}
	write(1, "\n", 1);
	return (0);
}

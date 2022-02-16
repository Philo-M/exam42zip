#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

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
				i++;
				k++;
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

void	ft_fill(int i, int j, int x, int y, int ile, char **map)
{
	map[i][j] = ile + 48;
	if (i > 0 && map[i-1][j] == 'X')
		ft_fill(i-1, j, x, y, ile, map);
	if (j > 0 && map[i][j-1] == 'X')
		ft_fill(i, j-1, x, y, ile, map);
	if (i+1<y && map[i+1][j] == 'X')
		ft_fill(i+1, j, x, y, ile, map);
	if (j+1<x && map[i][j+1] == 'X')
		ft_fill(i, j+1, x, y, ile, map);
}

int	ft_count(char *file)
{
	int		i;
	int		j;
	int		x;
	int		y;
	int		fd;
	int		ile;
	size_t	size;
	char	*buffer;
	char	**map;


	fd = open (file, O_RDONLY);
	if (fd < 0)
		return (0);
	buffer = malloc(sizeof(char) * 1024);
	if (!buffer)
		return (0);
	i = 0;
	while (i < 1024)
	{
		buffer[i] = 0;
		i++;
	}
	size = 0;
	while ((i = read(fd, buffer, 1024)) > 0)
		size += i;
	close(fd);
	free(buffer);
	fd = open (file, O_RDONLY);
	if (fd < 0)
		return (0);
	buffer = malloc(sizeof(char) * (size + 1));
	if (!buffer)
		return (0);
	i = 0;
	while ((size_t)i <= size)
	{
		buffer[i] = 0;
		i++;
	}
	if (read(fd, buffer,size) <= 0)
	{
		free(buffer);
		return (0);
	}
	close(fd);
	
	x = 0;
	while (buffer[x] && buffer[x] != '\n')
		x++;
	if (!x)
	{
		free(buffer);
		return (0);
	}
	i = 0;
	y = 0;
	fd = 1;
	while (buffer[i])
	{
		if (buffer[i] != '.' && buffer[i] != 'X' && buffer[i] != '\n')
		{
			free(buffer);
			return (0);
		}
		if (buffer[i] == '\n')
		{
			if (fd - 1 != x)
			{
				free(buffer);
				return (0);
			}
			y++;
			fd = 0;
		}
		i++;
		fd++;
	}
	
	map = ft_split(buffer, x, y);
	free(buffer);
	
	i = 0;
	ile = 0;	
	while (ile < 10)
	{
		while (i < y)
		{
			j = 0;
			while (j < x)
			{
				if (map[i][j] == '.' && (map[i][j] >= '0' && map[i][j] <= ile + 48))
					j++;
				if (map[i][j] == 'X')
				{
					ft_fill(i, j, x, y, ile, map);
					ile++;
				}
				j++;
			}
			i++;
		}
		ile++;
	}

	i = 0;
	while (map[i])
	{
		ft_putstr(map[i]);
		write(1, "\n", 1);
		free(map[i]);
		i++;
	}
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








































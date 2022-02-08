#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int			ft_strlen(char *str)
{
	int		index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

char		*ft_strdup(char *str)
{
	char 	*ret;
	int		index;

	index = 0;
	ret = malloc(sizeof(char) * ft_strlen(str) + 1);
	while (str[index])
		ret[index] = str[index++];
	ret[index] = '\0';
	return (ret);
}

void	ft_strcpy(char *dst, char *src)
{
	int	index;

	index = 0;
	while (src[index])
		dst[index] = src[index++];
	dst[index] = '\0';
}

char	*ft_strjoin(char *dst, char *src)
{
	char	*ret;
	int		index;
	int		count;

	index = 0;
	count = 0;
	ret = malloc(sizeof(char) * ft_strlen(dst) + ft_strlen(src) + 1);
	while (dst[index])
		ret[index] = dst[index++];
	while (src[count])
		ret[index++] = src[count++];
	ret[index] = '\0';
	return (ret);
}

void	ft_strfusion(char **dst, char *str)
{
	char	*ret;

	ret = ft_strjoin(*dst, str);
	free(*dst);
	*dst = ret;
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

char		*read_file(char *str, int fd)
{
	int		ret;
	char	*tmp;

	tmp = malloc(sizeof(char*) * 43);
	if (!tmp)
		return (NULL);
	ret = read(fd, tmp, 42);
	tmp[ret] = '\0';
	if (ret < 1)
		return (NULL);
	return (tmp);
}

int			space_len(char *str)
{
	int		ret;

	ret = 0;
	while (str[ret] && str[ret] != '\n')
		ret++;
	return (ret);
}

char		*read_f(char *str)
{
	int		fd;
	char 	*tmp;
	char	*all;

	fd = open(str, O_RDONLY, 0);
	all = malloc(sizeof(char));
	tmp = malloc(sizeof(char));
	while (tmp)
	{
		if (tmp)
			free(tmp);
		tmp = NULL;
		tmp = read_file(str, fd);
		if (tmp)
			ft_strfusion(&all, tmp);
	}
	free(tmp);
	close(fd);
	return (all);
}

void		brute(char *str, int size, int num, int index)
{
	if (str[index] && str[index] == 'X')
	{
		str[index] = num + 48;
		if (index > 0)
			brute(str, size, num, (index - 1));
		brute(str, size, num, (index + 1));
		if (index > size)
			brute(str, size, num, (index - size - 1));
		brute(str, size, num, (index + size + 1));
	}
}

void		count_island(char *str)
{
	char	*file;
	int		index;
	int		num;

	index = -1;
	num = 0;
	file = read_f(str);
	while (file[++index])
		if (file[index] == 'X')
			brute(file, space_len(file), num++, index);
	ft_putstr(file);
	free(file);
}

int			main(int argc, char **argv)
{
	char	*tmp;
	char	*str;

	if (argc == 2)
		count_island(argv[1]);
	write(1, "\n", 1);
	return (0);
}

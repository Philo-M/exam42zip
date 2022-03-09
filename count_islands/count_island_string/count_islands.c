/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_islands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmandel <pmandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 11:38:21 by pmandel           #+#    #+#             */
/*   Updated: 2022/03/09 16:19:49 by pmandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int	ft_read(int fd, char **str, int len)
{
	char	c;
	int		len_r;

	len_r = read(fd, &c, 1);
	if (len_r < 0)
		return (0);
	else if (len_r > 0)
	{
		ft_read(fd, str, len + 1);
		(*str)[len] = c;
	}
	else
	{
		*str = (char *)malloc(sizeof(char) * (len + 1));
		if (*str == NULL)
			return (0);
		(*str)[len] = '\0';
	}
	return (1);
}

int	ft_strlen_c(char *str, char c)
{
	int	i = 0;

	while (str[i] && str[i] != c)
		i++;
	return (i);
}

int	ft_check(char *str)
{
	int	len_0 = ft_strlen_c(str, '\n') + 1;
	int	i = 0;

	if (len_0 > 1024)
		return (0);
	while (str[i])
	{
		if (((str[i] == '\n' || str[i] == '\0') && ((i + 1) % len_0 != 0)) || 
			(str[i] != '\n' && str[i] != '\0' && str[i] != 'X' && str[i] != '.'))
			return (0);
		i++;
	}
	return (1);
}

void	ft_fill(char *str, int i, int nb)
{
	int	len_0 = ft_strlen_c(str, '\n') + 1;
	int	len_f = ft_strlen_c(str, '\0') + 1;

	if (i < len_f && i >= 0 && str[i] == 'X')
	{
		str[i] = '0' + nb;
		ft_fill(str, i + 1, nb);
		ft_fill(str, i + len_0, nb);
		ft_fill(str, i - 1, nb);
		ft_fill(str, i - len_0, nb);
	}
}

int	main(int argc, char **argv)
{
	int		fd;
	char	*str;
	int		i = 0;
	int		nb = 0;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd > 0 && ft_read(fd, &str, 0) == 1 && ft_check(str) == 1)
		{
			while (str[i])
			{
				if (str[i] == 'X')
				{
					ft_fill(str, i, nb);
					nb++;
				}
				i++;
			}
			if (nb <= 10)
			{
				i = 0;
				while (str[i])
				{
					write(1, &str[i], 1);
					i++;
				}
			}
			else
				write(1, "\n", 1);
			free(str);
		}
		else
			write(1, "\n", 1);
		close(fd);
	}
	else
		write(1, "\n", 1);
	return (0);
}
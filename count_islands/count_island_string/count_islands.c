/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_islands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmandel <pmandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:09:04 by pmandel           #+#    #+#             */
/*   Updated: 2022/02/09 18:41:06 by pmandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "count_islands.h"

static void	filerecord(char **str, int fd, int len)
{
	char	c;

	if (read(fd, &c, 1) > 0)
	{
		filerecord(str, fd, len + 1);
		(*str)[len] = c;
	}
	else
	{
		*str = (char *)malloc(sizeof(char) * (len + 1));
		if (str == NULL)
			return;
		(*str)[len] = '\0';
	}
}

static int	ft_check(char *str)
{
	int		len_str;
	int		len_0;
	int		i;

	len_str = ft_strlen_c(str, '\0') + 1;
	len_0 = ft_strlen_c(str, '\n') + 1;
	i = 0;
	if (len_0 > 0)
	{
		while (i < len_str)
		{
			if (((str[i] == '\n' || str[i] == '\0') && (((i + 1) % len_0) != 0)) || 
				(str[i] != '.' && str[i] != 'X' && str[i] != '\n' && str[i] != '\0'))
				return (0);
			i++;
		}
	}
	return (1);
}

static void	ft_fill_island(char *str, int i, int nb)
{
	int		len_str;
	int		len_0;

	len_str = ft_strlen_c(str, '\0') + 1;
	len_0 = ft_strlen_c(str, '\n') + 1;
	if (((i + 1) % len_0 != 0 ) && i < len_str && str[i] == 'X')
	{
		str[i] = nb;
		ft_fill_island(str, i + 1, nb);
		ft_fill_island(str, i + len_0, nb);
		ft_fill_island(str, i - 1, nb);
		ft_fill_island(str, i - len_0, nb);
	}
}

static int	ft_parse(char *str)
{
	int	i;
	int	len_str;
	int	nb;

	len_str = ft_strlen_c(str, '\0') + 1;
	nb = '0';
	i = 0;
	while (i < len_str)
	{
		if (str[i] == 'X')
		{
			ft_fill_island(str, i, nb);
			nb = nb + 1;
		}
		i++;
	}
	return (nb);
}

int	main(int argc, char **argv)
{
	int		fd;
	char	*str;
	int		nb;
	
	if (argc== 2)
	{
		fd = open(argv[1], O_RDONLY);
		filerecord(&str, fd, 0);
		if (ft_check(str) == 1)
		{
			nb = ft_parse(str);
			if (nb <= '0' + 10)
				ft_putstr(str);
		}
		ft_putchar('\n');
		close(fd);
		free (str);
	}
	return (0);
}

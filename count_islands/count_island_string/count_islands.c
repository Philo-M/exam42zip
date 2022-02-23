/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_islands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmandel <pmandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:28:45 by pmandel           #+#    #+#             */
/*   Updated: 2022/02/23 15:00:57 by pmandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int	ft_read(int fd, char **str, int len)
{
	int		len_read;
	char	c;

	len_read = read(fd, &c, 1);
	if (len_read < 0)
		return (0);
	else if (len_read > 0)
	{
		ft_read(fd, str, len + 1);
		(*str)[len] = c;
	}
	else
	{
		*str = (char *)malloc(sizeof(char) * (len + 1));
		(*str)[len] = '\0';
	}
	return (1);
}

int	ft_strlen_c(char *str, char c)
{
	int	i = 0;

	while (str[i] && str[i] != c)
		i++;
	return(i);
}

int	ft_check(char *str)
{
	int	i = 0;
	int	len_0 = 0;

	len_0 = ft_strlen_c(str, '\n') + 1;
	if (len_0 > 1024)
		return (0);
	while (str[i])
	{
		if (((str[i] == '\n' || str[i] == '\0') && ((i + 1) % len_0 != 0)) ||
			!(str[i] == '\n' || str[i] == '\0' || str[i] == 'X' || str[i] == '.'))
			return (0);
		i++;
	}
	return (1);
}

void	ft_fill(char *str, int	i, int	nb)
{
	int	len_0 = ft_strlen_c(str, '\n') + 1;
	int	len_f = ft_strlen_c(str, '\0') + 1;

	if (str[i] == 'X' && i < len_f)
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
	char	*str = NULL;
	int		nb = 0;
	int		i = 0;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd > 0 && ft_read(fd, &str, 0) > 0 && ft_check(str) == 1)
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
					ft_putchar(str[i]);
					i++;
				}
			}
			free(str);
		}
	}
	ft_putchar('\n');
}
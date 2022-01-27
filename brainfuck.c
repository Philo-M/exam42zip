
#include <unistd.h>

int	ft_go_right( char *line, int ptr)
{
	int step;

	step = 1;
	ptr++;
	while (step > 0)
	{
		if (line[ptr] == '[')
			step++;
		else if (line[ptr] == ']')
			step--;
		ptr++;
	}
	return (ptr);
}

int	ft_go_left( char *line, int ptr)
{
	int step;

	step = 1;
	ptr--;
	while (step > 0)
	{
		if (line[ptr] == ']')
			step++;
		else if (line[ptr] == '[')
			step--;
		ptr--;
	}
	return (ptr);
}

int	main(int argc, char *argv[])
{
	int		i;
	int		ptr;
	char	line[2048] = {0};

	i = 0;
	ptr = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (argv[1][i] == '>')
				ptr++;
			else if (argv[1][i] == '<')
				ptr--;
			else if (argv[1][i] == '+')
				line[ptr]++;
			else if (argv[1][i] == '-')
				line[ptr]--;
			else if (argv[1][i] == '.')
				write(1, &line[ptr], 1);
			else if (argv[1][i] == '[' && line[ptr] == 0)
				i = ft_go_right(argv[1], i);
			else if (argv[1][i] == ']' && line[ptr] != 0)
				i = ft_go_left(argv[1], i);
			i++;
		}
	}
	else	
		write(1, "\n", 1);
	return (0);
}

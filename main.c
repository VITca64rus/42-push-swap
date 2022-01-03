static void	go_to(const char *str, int *i, int *znak)
{
	while (str[*i] == ' ' || str[*i] == '\t' || str[*i] == '\n' \
			|| str[*i] == '\v' || str[*i] == '\f' || str[*i] == '\r')
		*i = *i + 1;
	if (str[*i] == '-')
	{
		*znak = -1;
		*i = *i + 1;
	}
	else if (str[*i] == '+')
		*i = *i + 1;
}

int	ft_atoi(const char *str)
{
	long int	res;
	int			i;
	int			znak;

	res = 0;
	i = 0;
	znak = 1;
	go_to(str, &i, &znak);
	while (str[i] >= '0' && str[i] <= '9')
	{	
		if (znak * res < -2147483648)
			return (0);
		else if (res > 2147483647)
			return (-1);
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return ((int)res * znak);
}

int	ft_check_argv(int argc, char **argv)
{
	int	i;
	int j;

	i = 1;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		write(1, "No argumets", 12);

	else
	{
		if (ft_check_argv(argc, argv) == 1)
		{
			write(1, "work", 5);
		}
		else
			write(1, "Error", 6);
	}
	return (0);
}
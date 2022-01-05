/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazelda <sazelda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:39:20 by sazelda           #+#    #+#             */
/*   Updated: 2022/01/05 15:49:40 by sazelda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_number(char *a)
{
	int	i;

	i = 0;
	while (a[i] != '\0')
	{
		if ((a[i] < '0' || a[i] > '9') && (a[i] != '-' && i == 0))
			return (0);
		i++;
	}
	if (i > 11)
		return (0);
	if (i == 10 && ft_atoi(a) < 1000000000)
		return (0);
	else if (i == 11 && ft_atoi(a) > -1000000000)
		return (0);
	return (1);
}

static int	ft_ravn_int(char *a, char *b, t_list **list)
{
	if (ft_atoi(a) == ft_atoi(b) || ft_is_number(a) == 0)
	{
		ft_list_clear(*list);
		return (0);
	}
	return (1);
}

static t_list	*ft_check_argv(int argc, char **argv)
{
	int		j;
	t_list	*list_el;
	t_list	*list;
	//char	**arg;

	list = ((void *)0);
	argc--;
	if (argc == 1)
		argv = ft_split(argv[1], ' ');

	printf("%s %s %s", argv[0], argv[1], argv[2]);
	while (argc > 1)
	{
		j = argc - 1;
		while (j > 0)
		{
			if (ft_ravn_int(argv[argc], argv[j], &list) == 0)
				return (0);
			j--;
		}
		list_el = ft_lstnew(ft_atoi(argv[argc]));
		ft_lstadd_front(&list, list_el);
		argc--;
	}
	list_el = ft_lstnew(ft_atoi(argv[argc]));
	ft_lstadd_front(&list, list_el);
	return (list);
}

int	main(int argc, char **argv)
{
	int		a;
	t_list	*list;
	t_list	*p;

	list = ft_check_argv(argc, argv);
	if (list != 0)
	{
		if (ft_lstsize(list) == 3)
			ft_sort_three(list);
		else if (ft_lstsize(list) == 5)
		{
			ft_add_id_sort(list);
			ft_sort_five(list);
		}
		else
			ft_list_sort(&list, ft_lstsize(list));
	}
	else
		write(1, "Error", 6);
	ft_list_clear(list);
	return (0);
}

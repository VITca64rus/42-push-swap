/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazelda <sazelda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:10:05 by sazelda           #+#    #+#             */
/*   Updated: 2022/01/06 16:10:41 by sazelda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_ravn_int(char *a, char *b, t_list **list)
{
	if (ft_atoi(a) == ft_atoi(b) || ft_is_number(a) == 0 \
		|| ft_is_number(b) == 0)
	{
		ft_list_clear(*list);
		*list = ((void *)0);
		return (0);
	}
	return (1);
}

static void	ft_free_argv(char **argv, int count)
{
	int	j;

	j = 0;
	while (j < count)
	{
		free(argv[j]);
		j++;
	}
	free(argv);
}

static int	ft_check_str(int *argc, char ***argv, int *flag)
{
	*flag = *argc;
	if (*argc == 1)
	{
		*argv = ft_split((*argv)[1], ' ');
		*argc = 0;
		while ((*argv)[*argc])
			*argc = *argc + 1;
		*argc = *argc - 1;
	}
	if (*argc == 0 && ft_is_number((*argv)[0]) == 0 && *flag == 1)
	{
		ft_free_argv((*argv), 1);
		return (0);
	}
	return (1);
}

static int	ft_loop_in(int *argc, char **argv, int flag, t_list **list)
{
	int		count;
	int		j;
	t_list	*list_el;

	count = *argc;
	while ((*argc > 1 && flag > 1) || (*argc >= 1 && flag == 1))
	{
		j = *argc - 1;
		while ((j > 0 && flag > 1) || (j >= 0 && flag == 1))
		{
			if (ft_ravn_int(argv[*argc], argv[j], list) == 0)
			{
				if (flag == 1)
					ft_free_argv(argv, count + 1);
				return (0);
			}
			j--;
		}
		list_el = ft_lstnew(ft_atoi(argv[*argc]));
		ft_lstadd_front(list, list_el);
		*argc = *argc - 1;
	}
	return (1);
}

t_list	*ft_check_argv(int argc, char **argv)
{
	int		j;
	t_list	*list_el;
	t_list	*list;
	int		flag;
	int		count;

	list = ((void *)0);
	argc--;
	if (ft_check_str(&argc, &argv, &flag) == 0)
		return (0);
	if (ft_loop_in(&argc, argv, flag, &list) == 0)
		return (0);
	list_el = ft_lstnew(ft_atoi(argv[argc]));
	ft_lstadd_front(&list, list_el);
	j = 0;
	if (flag == 1)
		ft_free_argv(argv, ft_lstsize(list));
	return (list);
}

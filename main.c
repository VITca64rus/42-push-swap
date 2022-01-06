/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazelda <sazelda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:39:20 by sazelda           #+#    #+#             */
/*   Updated: 2022/01/06 16:11:01 by sazelda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_number(char *a)
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

int	main(int argc, char **argv)
{
	t_list	*list;

	list = ft_check_argv(argc, argv);
	if (list != 0)
	{
		if (ft_lstsize(list) == 3)
		{
			ft_sort_three(&list);
		}
		else if (ft_lstsize(list) == 5)
		{
			ft_add_id_sort(list);
			ft_sort_five(&list);
		}
		else
			ft_list_sort(&list, ft_lstsize(list));
	}
	else
		write(1, "Error\n", 7);
	ft_list_clear(list);
	return (0);
}

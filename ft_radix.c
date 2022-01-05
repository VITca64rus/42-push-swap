/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazelda <sazelda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:59:44 by sazelda           #+#    #+#             */
/*   Updated: 2022/01/05 14:00:38 by sazelda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_work_a(t_list **a, t_list **b, int j)
{
	t_list	*ptr;

	ptr = 0;
	if (((*a)->p_num_sort >> j & 1) == 0)
	{
		ptr = *a;
		*a = (*a)->next;
		ptr->next = ((void *)0);
		ft_lstadd_front(b, ptr);
		write(1, "pb\n", 3);
	}
	else
	{
		ptr = ft_lstlast(*a);
		ptr->next = *a;
		*a = (*a)->next;
		ptr->next->next = ((void *)0);
		write(1, "ra\n", 3);
	}
}

static void	ft_work_b(t_list **a, t_list *b)
{
	t_list	*ptr;

	ptr = 0;
	while (b)
	{
		ptr = b;
		b = b->next;
		ptr->next = ((void *)0);
		ft_lstadd_front(a, ptr);
		write(1, "pa\n", 3);
	}
}

void	ft_list_sort(t_list **a, int n)
{
	t_list	*b;
	t_list	*bptr;
	t_list	*ptr;
	int		i;
	int		j;

	ptr = 0;
	j = 0;
	ft_add_id_sort(*a);
	while (ft_sorted(*a) != 1)
	{
		b = ((void *)0);
		i = 0;
		while (i < n)
		{
			ft_work_a(a, &b, j);
			i++;
		}
		bptr = b;
		ft_work_b(a, b);
		j++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazelda <sazelda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:38:04 by sazelda           #+#    #+#             */
/*   Updated: 2022/01/05 20:10:13 by sazelda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sa(t_list **a)
{
	int	buf;

	buf = 0;
	write (1, "sa\n", 3);
	buf = (*a)->num;
	(*a)->num = (*a)->next->num;
	(*a)->next->num = buf;
	*a = (*a)->next;
}

void	ft_sort_three(t_list **a)
{
	int		buf;
	t_list	*start;

	start = *a;
	buf = 0;
	if ((*a)->num < (*a)->next->num)
		(*a) = (*a)->next;
	else
	{
		ft_sa(a);
	}
	if ((*a)->num > (*a)->next->num)
	{
		write (1, "rra\n", 4);
		(*a) = start;
		buf = (*a)->num;
		(*a)->num = (*a)->next->next->num;
		(*a)->next->next->num = (*a)->next->num;
		(*a)->next->num = buf;
		if ((*a)->num > (*a)->next->num)
			write (1, "sa\n", 3);
	}
	*a = start;
}

static void	ft_pb_ra_s(t_list **a, t_list **b)
{
	t_list	*ptr;

	ptr = 0;
	if ((*a)->p_num_sort == 0 || (*a)->p_num_sort == 1)
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

void	ft_sort_five(t_list **a)
{
	t_list	*ptr;
	t_list	*b;
	int		i;

	b = 0;
	ptr = 0;
	i = 0;
	while (i < 5)
	{
		ft_pb_ra_s(a, &b);
		i++;
	}
	ft_sort_three(a);
	if (b->p_num_sort < b->next->p_num_sort)
		write(1, "sb\n", 3);
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

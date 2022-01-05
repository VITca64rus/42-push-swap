/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazelda <sazelda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:39:20 by sazelda           #+#    #+#             */
/*   Updated: 2022/01/05 13:22:59 by sazelda          ###   ########.fr       */
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
	if (i == 10)
	{
		if (ft_atoi(a) >= 1000000000 && ft_atoi(a) <= 2147483647)
			return (1);
		else
			return (0);
	}
	else if (i == 11)
	{
		if (ft_atoi(a) >= -2147483648 && ft_atoi(a) <= -1000000000)
			return (1);
		else
			return (0);
	}
	return (1);
}

t_list	*ft_check_argv(int argc, char **argv)
{
	int		i;
	int		j;
	t_list	*list_el;
	t_list	*list;

	list = ((void *)0);
	i = argc - 1;
	if (i == 0)
		write(1, "No arguments\n", 13);
	while (i > 1)
	{
		j = i - 1;
		while (j > 0)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]) \
				|| ft_is_number(argv[i]) == 0)
			{
				ft_list_clear(list);
				return (0);
			}
			j--;
		}
		list_el = ft_lstnew(ft_atoi(argv[i]));
		ft_lstadd_front(&list, list_el);
		i--;
	}
	list_el = ft_lstnew(ft_atoi(argv[i]));
	ft_lstadd_front(&list, list_el);
	return (list);
}

void	ft_sort_array(int **arr, int size)
{
	int	i;
	int	j;
	int	buff;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1)
		{
			if ((*arr)[j] > (*arr)[j + 1])
			{
				buff = (*arr)[j];
				(*arr)[j] = (*arr)[j + 1];
				(*arr)[j + 1] = buff;
			}
			j++;
		}
		i++;
	}
}

void	ft_add_id_sort(t_list *list)
{
	int		*arr;
	int		i;
	int		size;
	t_list	*p;

	p = list;
	size = ft_lstsize(list);
	i = 0;
	arr = (int *)malloc(sizeof(int) * ft_lstsize(list));
	while (list)
	{
		arr[i] = list->num;
		i++;
		list = list->next;
	}
	ft_sort_array(&arr, size);
	list = p;
	while (p)
	{
		i = 0;
		while (arr[i] != p->num)
			i++;
		p->p_num_sort = i;
		p = p->next;
	}
	free(arr);
}

int	ft_sorted(t_list *a)
{
	while (a->next)
	{
		if (a->next->p_num_sort == a->p_num_sort + 1)
			a = a->next;
		else
			return (0);
	}
	return (1);
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
	while (ft_sorted(*a) != 1)
	{
		b = ((void *)0);
		i = 0;
		while (i < n)
		{
			if (((*a)->p_num_sort >> j & 1) == 0)
			{
				ptr = *a;
				*a = (*a)->next;
				ptr->next = ((void *)0);
				ft_lstadd_front(&b, ptr);
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
			i++;
		}
		bptr = b;
		while (b)
		{
			ptr = b;
			b = b->next;
			ptr->next = ((void *)0);
			ft_lstadd_front(a, ptr);
			write(1, "pa\n", 3);
		}
		j++;
	}
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
		{
			ft_add_id_sort(list);
			ft_list_sort(&list, ft_lstsize(list));
		}
	}
	else
		write(1, "Error", 6);
	ft_list_clear(list);
	return (0);
}

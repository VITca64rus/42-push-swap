/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazelda <sazelda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 14:02:23 by sazelda           #+#    #+#             */
/*   Updated: 2022/01/05 14:10:14 by sazelda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort_array(int **arr, int size)
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

static int	*ft_create_arr(t_list *list)
{
	int	*arr;
	int	i;

	arr = (int *)malloc(sizeof(int) * ft_lstsize(list));
	if (!arr)
		return (0);
	i = 0;
	while (list)
	{
		arr[i] = list->num;
		i++;
		list = list->next;
	}
	return (arr);
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
	arr = ft_create_arr(list);
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

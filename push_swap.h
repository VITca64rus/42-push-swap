/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazelda <sazelda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:42:11 by sazelda           #+#    #+#             */
/*   Updated: 2022/01/06 16:11:15 by sazelda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_list
{
	int				num;
	int				p_num_sort;
	struct s_list	*next;
}	t_list;

void	ft_sort_three(t_list **a);
void	ft_sort_five(t_list **a);
t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
void	ft_list_clear(t_list *list);
int		ft_atoi(const char *str);
void	ft_list_sort(t_list **a, int n);
void	ft_add_id_sort(t_list *list);
int		ft_sorted(t_list *a);
t_list	*ft_check_argv(int argc, char **argv);
int		ft_is_number(char *a);

#endif
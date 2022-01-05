#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int	num;
	int	p_num_sort;
	struct s_list	*next;
}	t_list;

void	ft_sort_three(t_list *a);
void	ft_sort_five(t_list *a);
t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
int		ft_atoi(const char *str);

#endif
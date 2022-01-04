typedef struct s_list
{
	int	num;
	int	p_num_sort;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(void *content)
{
	t_list	*res;

	res = (t_list *)malloc(sizeof(t_list));
	if (!res)
		return ((void *)0);
	res->num = (int)content;
	res->next = ((void *)0);
	return (res);
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst)
		new->next = *lst;
	else
		new->next = ((void *)0);
	*lst = new;
}

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

t_list	*ft_check_argv(int argc, char **argv)
{
	int	i;
	int j;
	t_list	*list_el;
	t_list	*list;

	list = ((void *)0);
	i = argc - 1;;
	while (i > 1)
	{
		j = i - 1;
		while (j > 0)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
			{
				//CLEAR FIX_ME
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

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	ft_sort_array(int **arr, int size)
{
	int i;
	int j;
	int buff;

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
	int	*arr;
	int	i;
	int size;
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
		while (arr[i] != p->num && arr[i])
			i++;
		p->p_num_sort = i;
		p = p->next;
	}
	free(arr);
}

int	main(int argc, char **argv)
{
	int a;
	t_list	*list;

	if (argc == 1)
		write(1, "No argumets", 12);

	else
	{
		list = ft_check_argv(argc, argv);
		if (list != 0)
		{
			ft_add_id_sort(list);
		}
		else
			write(1, "Error", 6);
	}
	return (0);
}
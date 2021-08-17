#include "array.h"

static t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (!(lst->next))
			break ;
		lst = lst->next;
	}
	return (lst);
}

static void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
}

t_list	*declare_an_array(char *type, long long size)
{
	int		idx;
	t_list	*ret_arr;
	t_list	*new_arr;
	t_list 	*cur_arr;

	idx = 0;
	ret_arr = new_element(idx, type);
	cur_arr = ret_arr;
	while (++idx < size)
	{
		new_arr = new_element(idx, type);
		ft_lstadd_back(&cur_arr, new_arr);
		cur_arr = new_arr;
	}
	return (ret_arr);
}

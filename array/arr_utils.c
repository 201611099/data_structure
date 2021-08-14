#include "array.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (!(lst->next))
			break ;
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
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

void	print_element(t_list *arr, long long index)
{
	t_list	*cur_arr;

	cur_arr = arr;
	while (cur_arr)
	{
		if (cur_arr->index == index)
		{
			if (!strcmp(cur_arr->type, "char"))
				printf("element[%d]: %c\n", (int)index, cur_arr->char_ctnt);
			else if (!strcmp(cur_arr->type, "int"))
				printf("element[%d]: %d\n", (int)index, cur_arr->int_ctnt);
			return ;
		}
		cur_arr = cur_arr->next;
	}
}
#include "list.h"

void	remove_element_idx(t_list *lst, int index)
{
	t_list	*cur_lst;
	t_list	*pre_lst;
	int		cnt;

	cnt = 0;
	cur_lst = lst;
	pre_lst = 0;
	while (cur_lst)
	{
		if (cnt == index)
		{
			pre_lst->next = cur_lst->next;
			free(cur_lst);
			cur_lst = 0;
			return ;
		}
		++cnt;
		pre_lst = cur_lst;
		cur_lst = cur_lst->next;
	}
}

void	remove_element_data(t_list *lst, int data)
{
	t_list	*cur_lst;
	t_list	*pre_lst;

	cur_lst = lst;
	pre_lst = 0;
	while (cur_lst)
	{
		if (cur_lst->data == data)
		{
			pre_lst->next = cur_lst->next;
			free(cur_lst);
			cur_lst = 0;
			return ;
		}
		pre_lst = cur_lst;
		cur_lst = cur_lst->next;
	}
}

void	remove_all(t_list *lst)
{
	t_list	*cur_lst;

	while (lst)
	{
		cur_lst = lst->next;		
		free(lst);
		lst = cur_lst;
	}
}

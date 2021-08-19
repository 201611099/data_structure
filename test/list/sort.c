#include "list.h"

t_list	*sort_list_asc(t_list *lst)
{
	t_list	*cur_lst;
	t_list	*ret_lst;
	int		min;
	int		cnt;

	cnt = 0;
	while (count_element(lst) > 0)
	{
		min = 2147483647;
		cur_lst = lst;
		while (cur_lst)
		{
			if (cur_lst->data < min)
				min = cur_lst->data;
			cur_lst = cur_lst->next;
		}
		remove_element_data(&lst, min);
		if (cnt == 0)
			ret_lst = new_element(min);
		else
			insert_last_element(ret_lst, min);
		++cnt;
	}
	return (ret_lst);
}

t_list	*sort_list_desc(t_list *lst)
{
	t_list	*cur_lst;
	t_list	*ret_lst;
	int		max;
	int		cnt;

	cnt = 0;
	while (count_element(lst) > 0)
	{
		max = -2147483648;
		cur_lst = lst;
		while (cur_lst)
		{
			if (cur_lst->data > max)
				max = cur_lst->data;
			cur_lst = cur_lst->next;
		}
		remove_element_data(&lst, max);
		if (cnt == 0)
			ret_lst = new_element(max);
		else
			insert_last_element(ret_lst, max);
		++cnt;
	}
	return (ret_lst);
}

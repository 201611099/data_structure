#include "list.h"

/*
1. delete all //
2. add -> new node //
3. remove //
4. getData //
5. element count //
6. setData //
*/

t_list	*new_element(int data)
{
	t_list	*elem;

	elem = (t_list *)malloc(sizeof(t_list));
	if (!elem)
		return (0);
	elem->data = data;
	elem->next = 0;
	return (elem);
}

int	get_element_data(t_list *lst, int index)
{
	t_list	*cur_lst;
	int		cnt;

	cnt = 0;
	cur_lst = lst;
	while (cur_lst)
	{
		if (cnt == index)
			return (cur_lst->data);
		++cnt;
		cur_lst = cur_lst->next;
	}
}

int	find_element_idx(t_list *lst, int data) // 중복 값이 있는 경우 제일 처음 인덱스 반환
{
	t_list	*cur_lst;
	int		cnt;

	cnt = 0;
	cur_lst = lst;
	while (cur_lst)
	{
		if (cur_lst->data == data)
			return (cnt);
		++cnt;
		cur_lst = cur_lst->next;
	}
	return (-1);
}

int	count_element(t_list *lst)
{
	t_list	*cur_lst;
	int		cnt;

	cnt = 0;
	cur_lst = lst;
	while (cur_lst)
	{
		++cnt;
		cur_lst = cur_lst->next;
	}
	return (cnt);
}

void	set_element_by_index(t_list *lst, int index, int new_data)
{
	t_list	*cur_lst;
	int		cnt;

	cnt = 0;
	cur_lst = lst;
	while (cur_lst)
	{
		if (cnt == index)
		{
			cur_lst->data = new_data;
			return ;
		}
		++cnt;
		cur_lst = cur_lst->next;
	}
}

void	set_element_by_data(t_list *lst, int data, int new_data) // 중복 값이 있는 경우 제일 처음 인덱스 반환
{
	t_list	*cur_lst;
	int		cnt;

	cnt = 0;
	cur_lst = lst;
	while (cur_lst)
	{
		if (cur_lst->data == data)
			cur_lst->data = new_data;
		++cnt;
		cur_lst = cur_lst->next;
	}
}

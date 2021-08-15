#include "db_cc_list.h"

/*
1. delete all //
2. add -> new node //
3. remove //
4. getData //
5. element count //
6. setData //
*/

int	get_element_data(t_cc_list *lst, int index) //index번째 요소를 가져오는
{
	t_cc_list	*cur_lst;
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
	return (0);
}

int	find_element_idx(t_cc_list *lst, int data) // 중복 값이 있는 경우 제일 처음 인덱스 반환
{
	t_cc_list	*cur_lst;
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

void	set_element_by_index(t_cc_list *lst, int index, int new_data)
{
	t_cc_list	*cur_lst;
	int		cnt;
	int		num;

	cnt = 0;
	num = count_element(lst);
	cur_lst = lst;
	while (num-- > 0)
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

void	set_element_by_data(t_cc_list *lst, int data, int new_data) // 중복 값이 있는 경우 제일 처음 인덱스 반환
{
	t_cc_list	*cur_lst;
	int			num;

	num = count_element(lst);
	cur_lst = lst;
	while (num-- > 0)
	{
		if (cur_lst->data == data)
			cur_lst->data = new_data;
		cur_lst = cur_lst->next;
	}
}

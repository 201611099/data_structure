#include "db_list.h"

void	remove_element_idx(t_db_list **lst, int index) //해당 인덱스 요소 제거
{
	t_db_list	*cur_lst;
	t_db_list	*pre_lst;
	int		cnt;

	cnt = 0;
	cur_lst = *lst;
	pre_lst = 0;
	while (cur_lst)
	{
		if (cnt == index) //앞->next = 뒤 , 뒤->prev = 앞
		{
			if (cnt != 0)
			{
				pre_lst->next = cur_lst->next;	
				if (cur_lst->next != 0)
					cur_lst->next->prev = pre_lst;
			}
			else
			{
				if (cur_lst->next != 0)
					cur_lst->next->prev = 0;
				*lst = cur_lst->next;								
			}
			free(cur_lst);
			cur_lst = 0;
			return ;
		}
		++cnt;
		pre_lst = cur_lst;
		cur_lst = cur_lst->next;
	}
}

void	remove_element_data(t_db_list **lst, int data) //해당 데이터를 가진 첫번째 노드 삭제
{
	t_db_list	*cur_lst;
	t_db_list	*pre_lst;

	cur_lst = *lst;
	pre_lst = 0;
	while (cur_lst)
	{
		if (cur_lst->data == data)
		{
			if (pre_lst != 0)
			{
				pre_lst->next = cur_lst->next;
				if (cur_lst->next != 0)
					cur_lst->next->prev = pre_lst;
			}
			else
			{
				if (cur_lst->next != 0)
					cur_lst->next->prev = 0;
				*lst = cur_lst->next;
			}
			free(cur_lst);
			cur_lst = 0;
			return ;
		}
		pre_lst = cur_lst;
		cur_lst = cur_lst->next;
	}
}

void	remove_all(t_db_list **lst)
{
	t_db_list	*cur_lst;
	int			num;

	num = count_element(*lst);
	while (num-- > 0)
	{
		cur_lst = (*lst)->next;
		free(*lst);
		*lst = cur_lst;
	}
	*lst = 0;
}

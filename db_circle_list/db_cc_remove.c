#include "db_cc_list.h"

void	remove_element_idx(t_cc_list **lst, int index) //해당 인덱스 요소 제거
{
	t_cc_list	*cur_lst;
	t_cc_list	*pre_lst;
	int			cnt;
	int			num;

	cnt = 0;
	num = count_element(*lst);
	cur_lst = *lst;
	pre_lst = 0;
	while (cur_lst)
	{
		if (cnt == index)
		{
			if (num == 1)
			{
				free(*lst);
				*lst = 0;
				return ;
			}
			if (cnt == num - 1) //마지막 요소를 지우려고 할 때
			{
				cur_lst->prev->next = *lst;
				(*lst)->prev = cur_lst->prev;
			}
			else if (cnt == 0) //첫번째 요소를 지우려고 할 때
			{
				cur_lst->next->prev = (*lst)->prev;
				*lst = cur_lst->next;								
			}
			else
			{
				pre_lst->next = cur_lst->next;	
				cur_lst->next->prev = pre_lst;
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

void	remove_element_data(t_cc_list **lst, int data) //해당 데이터를 가진 첫번째 노드 삭제
{
	t_cc_list	*cur_lst;
	t_cc_list	*pre_lst;

	cur_lst = *lst;
	pre_lst = 0;
	while (cur_lst)
	{
		if (cur_lst->data == data)
		{
			if (count_element(*lst) == 1)
			{
				free(*lst);
				*lst = 0;
				return ;
			}
			if (pre_lst == 0) //첫번째 노드를 지우려고 할 때
			{
				cur_lst->next->prev = (*lst)->prev; //90 -> prev = 50
				(*lst)->prev->next = cur_lst->next; //50 -> next = 90
				*lst = cur_lst->next; //lst = 90;
			}
			else if (cur_lst->next == *lst) //마지막 노드를 지우려고 할 때
			{
				cur_lst->prev->next = *lst; //1 -> next = -214
				(*lst)->prev = cur_lst->prev; //-214 -> prev = 1
			}
			else
			{
				pre_lst->next = cur_lst->next;
				cur_lst->next->prev = pre_lst;
			}
			free(cur_lst);
			cur_lst = 0;
			return ;
		}
		pre_lst = cur_lst;
		cur_lst = cur_lst->next;
	}
}

void	remove_all(t_cc_list **lst)
{
	t_cc_list	*cur_lst;
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

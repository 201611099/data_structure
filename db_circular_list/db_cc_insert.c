#include "db_cc_list.h"

t_cc_list	*new_element(int data)
{
	t_cc_list	*new;

	new = (t_cc_list *)malloc(sizeof(t_cc_list));
	if (!new)
		return (0);
	new->data = data;
	new->prev = new;
	new->next = new;
	return (new);
}

void	insert_last_element(t_cc_list *lst, int data)
{
	t_cc_list	*new;
	t_cc_list	*cur_lst;
	
	new = new_element(data);
	if(new == 0)
		return ;
	cur_lst = lst;
	while (cur_lst->next != lst)
		cur_lst = cur_lst->next;
	lst->prev = new;
	cur_lst->next = new;
	new->prev = cur_lst;
	new->next = lst;
}

void	insert_front_element(t_cc_list **lst, int data)
{
	t_cc_list	*new;
	
	new = new_element(data);
	if(new == 0)
		return ;
	(*lst)->prev->next = new; //마지막 노드의 next -> new
	new->prev = (*lst)->prev;
	(*lst)->prev = new;
	new->next = *lst;
	*lst = new;
}

void	insert_element(t_cc_list *lst, int data, int index)
{
	int			cnt;
	t_cc_list 	*new;
	t_cc_list	*cur_lst;
	
	cnt = 1;
	new = new_element(data);
	if (new == 0)
		return ;
	cur_lst = lst->next; 
	while (cur_lst)
	{
		if (cnt == index) 
		{	
			cur_lst->prev->next = new; 
			new->prev = cur_lst->prev; 
			new->next = cur_lst; 
			cur_lst->prev = new; 
			return ; 
		}
		++cnt;
		cur_lst = cur_lst->next;
	}
}

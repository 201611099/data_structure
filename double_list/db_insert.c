#include "db_list.h"

t_db_list	*new_element(int data)
{
	t_db_list	*elem;

	elem = (t_db_list *)malloc(sizeof(t_db_list));
	if (!elem)
		return (0);
	elem->data = data;
	elem->prev = 0;
	elem->next = 0;
	return (elem);
}

void	insert_last_element(t_db_list *lst, int data)
{
	t_db_list	*new;
	t_db_list	*cur_lst;
	
	new = new_element(data);
	if(new == 0)
		return ;
	cur_lst = lst;
	while (cur_lst->next)
		cur_lst = cur_lst->next;
	cur_lst->next = new;
	new->prev = cur_lst;
}

void	insert_front_element(t_db_list **lst, int data)
{
	t_db_list	*new;
	
	new = new_element(data);
	if(new == 0)
		return ;
	(*lst)->prev = new;
	new->next = *lst;
	*lst = new;
}

void	insert_element(t_db_list *lst, int data, int index)
{
	int		cnt;
	t_db_list 	*elem;
	t_db_list	*cur_lst;
	
	cnt = 1;
	elem = new_element(data);
	if (elem == 0)
		return ;
	cur_lst = lst->next; 
	while (cur_lst)
	{
		if (cnt == index) 
		{	
			cur_lst->prev->next = elem; 
			elem->prev = cur_lst->prev; 
			elem->next = cur_lst; 
			cur_lst->prev = elem; 
			return ; 
		}
		++cnt;
		cur_lst = cur_lst->next;
	}
}

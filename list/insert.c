#include "list.h"

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

void	insert_last_element(t_list *lst, int data)
{
	t_list	*new;
	t_list	*cur_lst;
	
	new = new_element(data);
	if(new == 0)
		return ;
	cur_lst = lst;
	while (cur_lst->next)
		cur_lst = cur_lst->next;
	cur_lst->next = new;
}

void	insert_front_element(t_list **lst, int data)
{
	t_list	*new;
	
	new = new_element(data);
	if(new == 0)
		return ;
	new->next = *lst;
	*lst = new;
}

void	insert_element(t_list *lst, int data, int index)
{
	int		cnt;
	t_list 	*elem;
	t_list	*cur_lst;
	
	cnt = 1;
	elem = new_element(data);
	if (elem == 0)
		return ;
	cur_lst = lst;
	while (cur_lst)
	{
		if (cnt == index)
		{	
			elem->next = cur_lst->next; 
			cur_lst->next = elem; 
			return ;
		}
		++cnt;
		cur_lst = cur_lst->next;
	}
}

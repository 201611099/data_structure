#include "list.h"

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

void	print_list_all(t_list *lst)
{
	t_list	*cur_lst;
	int		idx;

	idx = 0;
	cur_lst = lst;
	while (cur_lst)
	{
		printf("list %d data = %d\n", idx++, cur_lst->data);
		cur_lst = cur_lst->next;
	}
}
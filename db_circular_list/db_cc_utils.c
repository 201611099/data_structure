#include "db_cc_list.h"

int	count_element(t_cc_list *lst)
{
	t_cc_list	*cur_lst;
	int		cnt;

	if (lst == 0)
		return (0);
	cnt = 1;
	cur_lst = lst;
	while (cur_lst->next != lst)
	{
		++cnt;
		cur_lst = cur_lst->next;
	}
	return (cnt);
}

void	print_cc_list_all(t_cc_list *lst)
{
	t_cc_list	*cur_lst;
	int		idx;
	int		num;

	idx = 0;
	cur_lst = lst;
	num = count_element(lst);
	while (num-- > 0)
	{
		printf("list %d data = %d\n", idx++, cur_lst->data);
		cur_lst = cur_lst->next;
	}
}
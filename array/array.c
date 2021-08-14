#include "array.h"

t_list	*new_element(int idx, char *type)
{
	t_list *ret;

	ret = (t_list *)malloc(sizeof(t_list)); //numb[0]
	ret->next = 0;
	ret->index = idx;
	ret->type = type;
	return (ret);
}

t_list	*declare_an_array(char *type, long long size)
{
	int		idx;
	t_list	*ret_arr;
	t_list	*new_arr;
	t_list 	*curr_arr;

	//size 음수 예외처리 
	idx = 0;
	ret_arr = new_element(idx, type);
	curr_arr = ret_arr;
	while (++idx < size)
	{
		new_arr = new_element(idx, type);
		ft_lstadd_back(&curr_arr, new_arr);
		curr_arr = new_arr;
	}
	return (ret_arr);
}

int	return_value_of_array(t_list *array, long long index)
{
	t_list	*cur_arr;

	cur_arr = array;
	while (cur_arr)
	{
		if (cur_arr->index == index)
		{	
			if (!strcmp(cur_arr->type, "char"))
				return (cur_arr->char_ctnt);
			else if (!strcmp(cur_arr->type, "int"))
				return (cur_arr->int_ctnt);
		}
		cur_arr = cur_arr->next;
	}
	return (-1);
}

void	insert_value(t_list *arr, long long index, long long value)
{	
	t_list	*curr_arr;

	curr_arr = arr;
	while (curr_arr)
	{
		if (curr_arr->index == index)
		{
			if (!strcmp(arr->type, "char"))
				curr_arr->char_ctnt = (char)value;
			else if (!strcmp(arr->type, "int"))
				curr_arr->int_ctnt = (int)value;
			return ;
		}
		curr_arr = curr_arr->next;
	}
}

void	initialize_an_array(t_list *array, long long value)
{
	t_list	*cur_arr;
	
	cur_arr = array;
	while (cur_arr)
	{
		cur_arr->char_ctnt = 0;
		cur_arr->int_ctnt = 0;
		cur_arr = cur_arr->next;
	}
	insert_value(array, 0, value);
	return ;
}

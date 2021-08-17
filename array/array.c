#include "array.h"

void	print_element(t_list *arr, long long index)
{
	t_list	*cur_arr;

	cur_arr = arr;
	while (cur_arr)
	{
		if (cur_arr->index == index)
		{
			if (!strcmp(cur_arr->type, "char"))
				printf("array[%d]: %c\n", (int)index, cur_arr->char_data);
			else if (!strcmp(cur_arr->type, "int"))
				printf("array[%d]: %d\n", (int)index, cur_arr->int_data);
			return ;
		}
		cur_arr = cur_arr->next;
	}
}

t_list	*new_element(int idx, char *type)
{
	t_list *ret;

	ret = (t_list *)malloc(sizeof(t_list)); //numb[0]
	ret->next = 0;
	ret->index = idx;
	ret->type = type;
	return (ret);
}


int	return_value_of_array(t_list *arr, long long index)
{
	t_list	*cur_arr;

	cur_arr = arr;
	while (cur_arr)
	{
		if (cur_arr->index == index)
		{	
			if (!strcmp(cur_arr->type, "char"))
				return (cur_arr->char_data);
			else if (!strcmp(cur_arr->type, "int"))
				return (cur_arr->int_data);
		}
		cur_arr = cur_arr->next;
	}
	return (-1);
}

void	insert_value(t_list *arr, long long index, long long value)
{	
	t_list	*cur_arr;

	cur_arr = arr;
	while (cur_arr)
	{
		if (cur_arr->index == index)
		{
			if (!strcmp(arr->type, "char"))
				cur_arr->char_data = (char)value;
			else if (!strcmp(arr->type, "int"))
				cur_arr->int_data = (int)value;
			return ;
		}
		cur_arr = cur_arr->next;
	}
}

void	initialize_an_array(t_list *arr, long long value)
{
	t_list	*cur_arr;
	
	cur_arr = arr;
	while (cur_arr)
	{
		cur_arr->char_data = 0;
		cur_arr->int_data = 0;
		cur_arr = cur_arr->next;
	}
	insert_value(arr, 0, value);
	return ;
}

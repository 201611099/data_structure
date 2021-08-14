#ifndef ARRAY_H
# define ARRAY_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>

typedef struct s_list
{
	char	char_ctnt;
	int		int_ctnt;
	long long	index;
	struct s_list	*next;
	char	*type;
}	t_list;


t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new_lst);
void	print_element(t_list *arr, long long index);

t_list	*new_element(int idx, char *type);
void	insert_value(t_list *arr, long long index, long long value);

t_list	*declare_an_array(char *type, long long size);
void	initialize_an_array(t_list *array, long long value);
int		return_value_of_array(t_list *array, long long index);

#endif
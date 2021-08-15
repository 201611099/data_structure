#ifndef LIST_H
# define LIST_H

# include <stdio.h>
# include <stdlib.h>

typedef struct	s_list
{
	int				data;
	struct s_list	*next;
} t_list;

/*
** insert.c
*/
t_list	*new_element(int data);
void	insert_last_element(t_list *lst, int data);
void	insert_front_element(t_list **lst, int data);
void	insert_element(t_list *lst, int data, int index);

/*
** remove.c
*/
void	remove_element_idx(t_list **lst, int index);
void	remove_element_data(t_list **lst, int data);
void	remove_all(t_list **lst);

/*
**list.c
*/
int		get_element_data(t_list *lst, int index);
int		find_element_idx(t_list *lst, int data); // 중복 값이 있는 경우 제일 처음 인덱스 반환
void	set_element_by_index(t_list *lst, int index, int new_data);
void	set_element_by_data(t_list *lst, int data, int new_data); // 중복 값이 있는 경우 제일 처음 인덱스 반환

/*
**utils.c
*/
int		count_element(t_list *lst);
void	print_list_all(t_list *lst);

/*
** sort.c
*/
t_list	*sort_list_asc(t_list *lst);
t_list	*sort_list_desc(t_list *lst);


#endif
#ifndef DB_CC_LIST_H
# define DB_CC_LIST_H

# include <stdio.h>
# include <stdlib.h>

typedef struct s_cc_list
{
	int						data;
	struct s_cc_list	*prev;
	struct s_cc_list	*next;
} t_cc_list;

/*
** db_cc_insert.c
*/
t_cc_list	*new_element(int data);
void	insert_last_element(t_cc_list *lst, int data);
void	insert_front_element(t_cc_list **lst, int data);
void	insert_element(t_cc_list *lst, int data, int index);

/*
** db_cc_remove.c
*/
void	remove_element_idx(t_cc_list **lst, int index);
void	remove_element_data(t_cc_list **lst, int data);
void	remove_all(t_cc_list **lst);

/*
** db_cc_list.c
*/
int		get_element_data(t_cc_list *lst, int index);
int		find_element_idx(t_cc_list *lst, int data); // 중복 값이 있는 경우 제일 처음 인덱스 반환
void	set_element_by_index(t_cc_list *lst, int index, int new_data);
void	set_element_by_data(t_cc_list *lst, int data, int new_data); // 중복 값이 있는 경우 제일 처음 인덱스 반환

/*
** db_cc_utils.c
*/
int		count_element(t_cc_list *lst);
void	print_cc_list_all(t_cc_list *lst);

/*
** db_cc_sort.c
*/
t_cc_list	*sort_cc_list_asc(t_cc_list *lst);
t_cc_list	*sort_cc_list_desc(t_cc_list *lst);


#endif
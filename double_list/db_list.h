#ifndef DB_LIST_H
# define DB_LIST_H

# include <stdio.h>
# include <stdlib.h>

typedef struct s_db_list
{
	int						data;
	struct s_db_list	*prev;
	struct s_db_list	*next;
} t_db_list;

/*
** db_insert.c
*/
t_db_list	*new_element(int data);
void	insert_last_element(t_db_list *lst, int data);
void	insert_front_element(t_db_list **lst, int data);
void	insert_element(t_db_list *lst, int data, int index);

/*
** db_remove.c
*/
void	remove_element_idx(t_db_list **lst, int index);
void	remove_element_data(t_db_list **lst, int data);
void	remove_all(t_db_list **lst);

/*
** db_list.c
*/
int		get_element_data(t_db_list *lst, int index);
int		find_element_idx(t_db_list *lst, int data); // 중복 값이 있는 경우 제일 처음 인덱스 반환
void	set_element_by_index(t_db_list *lst, int index, int new_data);
void	set_element_by_data(t_db_list *lst, int data, int new_data); // 중복 값이 있는 경우 제일 처음 인덱스 반환

/*
** db_utils.c
*/
int		count_element(t_db_list *lst);
void	print_db_list_all(t_db_list *lst);

/*
** db_sort.c
*/
t_db_list	*sort_db_list_asc(t_db_list *lst);
t_db_list	*sort_db_list_desc(t_db_list *lst);


#endif
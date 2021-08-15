#include "db_list.h"

int main()
{
	t_db_list *list;
	t_db_list *asc_list;
	t_db_list *desc_list;

	//test case: -2147, 100, 0, 50
	list = new_element(100); //생성(100이란 데이터를 가진 노드 1개 생성)
	
	insert_last_element(list, 50); //100 50
	insert_front_element(&list, -21473648); //-2147 100 50
	insert_element(list, 0, 2); //-2147 100 0 50
	print_db_list_all(list); //-2147 100 0 50
	
	printf("list->next->next->prev->data: %d\n", list->next->next->prev->data); //100이 나와야 함

	printf("\ncount_element: %d\n\n", count_element(list)); //연결리스트 노드의 개수
	printf("get data by index %d: %d\n", 1, get_element_data(list, 1)); //index가 1인 노드의 데이타 가져오기
	printf("set index 1 data -> 90\n");
	set_element_by_index(list, 1, 90);
	printf("get data by index %d: %d\n\n", 1, get_element_data(list, 1)); //index가 1인 노드의 바뀐 데이타 가져오기

	printf("find index by data %d : %d\n", 0, find_element_idx(list, 0)); //data가 0인 노드의 인덱스 가져오기
	set_element_by_data(list, 0, 1);
	printf("set data 0 -> 1\n");
	printf("find index by data %d : %d\n\n", 1, find_element_idx(list, 1)); //data가 0인 노드의 인덱스 가져오기

	print_db_list_all(list); //-2147 90 1 50

	asc_list = sort_db_list_asc(list); //오름차순 정렬
	printf("\nasc_list---\n");
	print_db_list_all(asc_list);
	
	desc_list = sort_db_list_desc(asc_list); //내림차순 정렬
	printf("\ndesc_list---\n");
	print_db_list_all(desc_list);

	printf("\ndesc_list---after remove data 50\n");
	remove_element_idx(&desc_list, 1);
	print_db_list_all(desc_list);

	printf("\ndesc_list---after remove data 1\n");
	remove_element_data(&desc_list, 1);
	print_db_list_all(desc_list);

	printf("\ndesc_list---after remove all\n");
	remove_all(&desc_list);
	print_db_list_all(desc_list);
}
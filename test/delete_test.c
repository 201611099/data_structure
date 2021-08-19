#include "list/list.h"

int main()
{
	int size = 2000;
	int idx = 0;

	printf("\n사이즈: %d, 삭제하려는 데이터의 인덱스: %d\n", size, idx);

	t_list *list;
	int array[size];

	for(int i = 0; i < size - 1; i++)
		array[i] = i;
	
	list = new_element(0);
	for (int i = 1; i < size; i++)
		insert_last_element(list, i);

	//데이터 삭제

	
	//1. 배열
	printf("\n삭제 전 array[%d]: %d\n", idx, array[idx]);
	clock_t start1 = clock();
	for (int i = idx; i < size - 1; i++)
		array[i] = array[i + 1];
	clock_t end1 = clock();
	printf("배열 -> 데이터 삭제에 걸린 시간: %lf\n", (double)(end1 - start1)/CLOCKS_PER_SEC);
	printf("삭제 후 array[%d]: %d\n\n", idx, array[idx]);

	//2. 연결리스트
	printf("삭제 전 list[%d]: %d\n", idx, get_element_data(list, idx));
	clock_t start2 = clock();
	remove_element_idx(&list, idx);
	clock_t end2 = clock();
	printf("연결리스트 -> 데이터 삭제에 걸린 시간: %lf\n", (double)(end2 - start2)/CLOCKS_PER_SEC);
	printf("삭제 후 list[%d]: %d\n\n", idx, get_element_data(list, idx));

	//-> 배열과 링크드리스트의 크기가 작을 땐 어떤 인덱스의 데이터를 삭제하든 별 차이가 없고 배열이 더 빠를 때가 많음
	//-> 배열과 링크드리스트의 크기가 2000 이상으로 커지고 인덱스가 작으면 작을수록 연결리스트가 더 빠름  
}

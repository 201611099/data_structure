#include "list/list.h"

int main()
{
	int size = 1000; 
	int data = 42; 
	int idx = 1;

	printf("\n사이즈: %d, 추가하려는 데이터: %d, 추가하려는 위치: 인덱스 %d\n", size, data, idx);

	t_list *list;
	int array[size];

	for(int i = 0; i < size - 1; i++)
		array[i] = i;
	
	list = new_element(0);
	for (int i = 1; i < size; i++)
		insert_last_element(list, i);

	//데이터 추가

	
	//1. 배열
	printf("\n추가 전 array[%d]: %d\n", idx, array[idx]);
	clock_t start1 = clock();
	for (int i = size - 1; i > idx; i--)
		array[i] = array[i - 1];
	array[idx] = data;
	clock_t end1 = clock();
	printf("배열 -> 데이터 추가에 걸린 시간: %lf\n", (double)(end1 - start1)/CLOCKS_PER_SEC);
	printf("추가 후 array[%d]: %d\n\n", idx, array[idx]);

	//2. 연결리스트
	printf("추가 전 list[%d]: %d\n", idx, get_element_data(list, idx));
	clock_t start2 = clock();
	insert_element(list, data, idx);	
	clock_t end2 = clock();
	printf("연결리스트 -> 데이터 추가에 걸린 시간: %lf\n", (double)(end2 - start2)/CLOCKS_PER_SEC);
	printf("추가 후 list[%d]: %d\n\n", idx, get_element_data(list, idx));

	//-> 인덱스가 작을 땐 연결리스트가 빠름. 인덱스가 배열의 크기에 가까워지면 배열이 더 빠름
}

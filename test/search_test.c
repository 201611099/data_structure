#include "list/list.h"

int main()
{
	int size = 1000;
	int idx = 900;
	
	printf("\n사이즈: %d, 찾으려는 데이터의 인덱스: %d\n", size, idx);

	t_list *list;
	int array[size];

	for(int i = 0; i < size; i++)
		array[i] = i;
	
	list = new_element(0);
	for (int i = 1; i < size; i++)
		insert_last_element(list, i);

	//데이터 탐색

	
	//1. 배열
	clock_t start1 = clock();
	int data1 = array[idx];
	clock_t end1 = clock();
	printf("\n배열 -> 데이터 탐색에 걸린 시간: %lf\n", (double)(end1 - start1)/CLOCKS_PER_SEC);
	printf("array[%d]: %d\n\n", idx, data1);

	//2. 연결리스트
	clock_t start2 = clock();
	int data2 = get_element_data(list, idx);
	clock_t end2 = clock();
	printf("연결리스트 -> 데이터 탐색에 걸린 시간: %lf\n", (double)(end2 - start2)/CLOCKS_PER_SEC);
	printf("list[%d]: %d\n\n", idx, data2);

	//-> 인덱스가 작을 땐 연결리스트가 빠름. 인덱스가 1000에 가까워지면 배열이 더 빠름
}

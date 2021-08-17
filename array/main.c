#include "array.h"

int main(void)
{
	t_list *numb;
	
	printf("----------declare_an_array----------\n");
	numb = declare_an_array("int", 4);
	printf("\n");
	printf("----------initialize_an_array----------\n");
	initialize_an_array(numb, 1);
	for (int i = 0; i < 4; i++)
		print_element(numb, i);
	printf("\n");
	printf("----------insert_value----------\n");
	insert_value(numb, 1, 10);
	for (int i = 0; i < 4; i++)
		print_element(numb, i);
	printf("\n");
	printf("-----------return_value_of_array----------\n");
	printf("");
	printf("array[1]: %d\n", return_value_of_array(numb, 1));
	printf("array[2]: %d\n", return_value_of_array(numb, 2));
	printf("array[3]: %d\n", return_value_of_array(numb, 3));
}


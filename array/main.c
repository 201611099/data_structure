#include "array.h"

int main(void)
{
	t_list *numb;
	
	numb = declare_an_array("char", 4);
	initialize_an_array(numb, 'a');
	insert_value(numb, 1, 65);
	for (int i = 0; i < 4; i++)
		print_element(numb, i);
	printf("numb[1]: %d\n", return_value_of_array(numb, 1));
	printf("numb[2]: %d\n", return_value_of_array(numb, 2));
	printf("numb[3]: %d\n", return_value_of_array(numb, 3));
	print_element(numb, 1);
}


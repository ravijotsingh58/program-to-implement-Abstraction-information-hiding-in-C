#include<stdlib.h>
#include "listClassAbstraction.h"

int reverse(struct list_t* source, struct list_t* dest){
	list_clear(dest);
	for(size_t i = list_size(source)-1;i >=0; i--){
		int item;
		if(list_get(source, i, &item)){
			return -1;
		}

		list_add(dest, item);
	}
	return 0;
}

int main(int argc, char** argv){
	struct list_t* list1 = list_malloc();
	struct list_t* list2 = list_malloc();

	//Construction

	list_init(list1);
	list_init(list2);

	list_add(list1, 4);
	list_add(list1, 6);
	list_add(list1, 1);
	list_add(list1, 5);

	list_add(list2, 9);

	reverse(list1, list2);

	list_print(list1);
	list_print(list2);

	//Destruction
	//printf("%d ", list_size(list1));

	list_destroy(list1);
	list_destroy(list2);

	free(list1);
	free(list2);
	return 0;
}

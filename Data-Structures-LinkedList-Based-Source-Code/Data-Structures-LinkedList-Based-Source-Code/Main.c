#include <stdio.h>
#include "LinkedList.h"

int main(void) {
	LinkedList* myList = NULL;

	if (is_empty(myList)) {
		printf("List is Empty\n");
	}
	init(&myList, 2);
	delete_by_index(&myList, 0);

	push_back(&myList, 3);
	push_front(&myList, 1);
	push_front(&myList, 0);

	display(myList); 

	delete_by_index(&myList, 1);

	display_reverse(myList); 
	if (!is_empty(myList)) {
		printf("List is NOT Empty\n");
	}
	printf("Size: %d\n", myList->size);

	return 0;
}
#pragma once
#include "LinkedList.h"

/*Initializes list with first element and sets relations to NULLs. Here HEAD id TAIL.*/
void init(LinkedList** listPtr, int value) {
	*listPtr = (LinkedList*)malloc(sizeof(LinkedList));
	if (!listPtr) {
		perror("Error while allocating LinkedList object in `init`");
		exit(1);
	}

	Node* new_node = (Node*)malloc(sizeof(Node));
	if (!new_node) {
		perror("Error while allocating memory for new node in method `init`");
		exit(1);
	}
	new_node->value = value;
	new_node->next = NULL;
	new_node->prev = NULL;

	(*listPtr)->head = new_node;
	(*listPtr)->tail = new_node;
	(*listPtr)->size = 1;
}

/*Adds an element after TAIL && sets TAIL to the new node*/
void push_back(LinkedList** listPtr, int value) {
	if ((*listPtr)->size == 0) {
		init(listPtr, value);
		return;
	}

	Node* new_node = (Node*)malloc(sizeof(Node));
	if (!new_node) {
		perror("Error while allocating memory for new node in method `push_back`");
		exit(1);
	}
	new_node->value = value;
	new_node->next = NULL;
	new_node->prev = (*listPtr)->tail;

	(*listPtr)->tail->next = new_node;
	(*listPtr)->tail = new_node;
	(*listPtr)->size++;
}

/*Adds an element before HEAD && sets HEAD to the new node*/
void push_front(LinkedList** listPtr, int value) {
	if ((*listPtr)->size == 0) {
		init(listPtr, value);
		return;
	}

	Node* new_node = (Node*)malloc(sizeof(Node));
	if (!new_node) {
		perror("Error while allocating memory for new node in method `push_front`");
		exit(1);
	}
	new_node->value = value;
	new_node->next = (*listPtr)->head;
	new_node->prev = NULL;

	(*listPtr)->head->prev = new_node;
	(*listPtr)->head = new_node;
	(*listPtr)->size++;
}

/*Inserts new node to index' position*/
void insert_by_index(LinkedList** listPtr, int value, int index) {
	if (index >= (*listPtr)->size) {
		perror("Out of index in method `insert_by_index`");
		exit(3);
	}
	/*No elements case*/
	if ((*listPtr)->size == 0) {
		init(listPtr, value);
	}
	else {
		Node* new_node = (Node*)malloc(sizeof(Node));
		if (!new_node) {
			perror("Error while allocating memory for new node in method `insert_by_index`");
			exit(1);
		}
		new_node->value = value;

		Node* it = (*listPtr)->head;
		for (int i = 0; i < index; i++) {
			it = it->next;
		}

		new_node->next = it;
		new_node->prev = it->prev;
		if (it->prev)
			it->prev->next = new_node;
		it->prev = new_node;

		if ((*listPtr)->head == it) {
			(*listPtr)->head = new_node;
		}
	}
	(*listPtr)->size++;
}

/*displays list from head to tail*/
void display(LinkedList* listPtr) {
	Node* it = listPtr->head;
	while (it) {
		printf("%d ", it->value);
		it = it->next;
	}
	putchar('\n');
}

/*displays list from tail to head*/
void display_reverse(LinkedList* listPtr) {
	Node* it = listPtr->tail;
	while (it) {
		printf("%d ", it->value);
		it = it->prev;
	}
	putchar('\n');
}

/*deletes and frees memory of list in given index*/
void delete_by_index(LinkedList** listPtr, int index) {
	if (index >= (*listPtr)->size) {
		perror("Out of index in method `delete_by_index`");
		exit(2);
	}

	/*deleting the only element*/
	if ((*listPtr)->size == 1) {
		(*listPtr)->head = NULL;
		(*listPtr)->tail = NULL;
	}
	/*delete head*/
	else if (index == 0) {
		Node* aux = (*listPtr)->head;
		(*listPtr)->head->next->prev = NULL;
		(*listPtr)->head = (*listPtr)->head->next;
		free(aux);
	}
	/*delete tail*/
	else if (index == (*listPtr)->size - 1) {
		Node* aux = (*listPtr)->tail;
		(*listPtr)->tail->prev->next = NULL;
		(*listPtr)->tail = (*listPtr)->tail->prev;
		free(aux);
	}
	else {
		Node* it = (*listPtr)->head;
		for (int i = 0; i < index; i++) {
			it = it->next;
		}
		it->prev->next = it->next;
		it->next->prev = it->prev;
		free(it);
	}
	(*listPtr)->size--;
}

bool is_empty(LinkedList* listPtr) {
	if (!listPtr) return true;
	if (listPtr->size > 0) {
		return false;
	}
	return true;
}
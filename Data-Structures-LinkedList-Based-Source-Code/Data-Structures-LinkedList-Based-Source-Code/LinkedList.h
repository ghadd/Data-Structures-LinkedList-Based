#pragma once

#include <stdio.h>
#include <stdlib.h>

/*A single element of Linked Structure*/
typedef struct Node {
	int value;
	struct Node* next;
	struct Node* prev;
} Node;

/*Linked list data itself*/
typedef struct LinkedList {
	Node* head;
	Node* tail;
	int size;
} LinkedList;

typedef unsigned int bool;
#define true 1
#define false 0

/*in order to prevent from copying all the elements of structure (12 bytes) passing a pointer to use only 4 bytes xD*/
void display(LinkedList* listPtr);
void display_reverse(LinkedList* listPtr);

bool is_empty(LinkedList* listPtr);

void init(LinkedList** listPtr, int value);
void push_back(LinkedList** listPtr, int value);
void push_front(LinkedList** listPtr, int value);
//void insert_by_index(LinkedList* listPtr, int value, int index);
//void insert_by_node(LinkedList* listPtr, int value, Node* prevNode);
void delete_by_index(LinkedList** listPtr, int index);
//void delete_by_node(LinkedList* listPtr, Node* toDelete);
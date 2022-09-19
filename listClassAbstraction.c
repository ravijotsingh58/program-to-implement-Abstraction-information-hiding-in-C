#include<stdio.h>
#include<stdlib.h>
//#include "listClassAbstraction.h"

#define MAX_SIZE 10

// define a allias type bool_t;

typedef int bool_t;

// define the type list_t

typedef struct{
	size_t size;
	int* items;
}list_t;

//Private behaviour which checks if list is full

bool_t __list_is_full(list_t* list){
	return (list->size == MAX_SIZE);
}

// Another private behavior which check the index

bool_t __check_index(list_t* list, const int index){
	return (index >= 0 && index <= list->size);
}

// Allocate memory for list object

list_t* list_malloc(){
	return (list_t*)malloc(sizeof(list_t));
}

// Constructor of list object

void list_init(list_t* list){
	list->size = 0;
	// Allocate from heap memory
	list->items = (int*)malloc(MAX_SIZE * sizeof(int));
}

// Destructor of list object

void list_destroy(list_t* list){
	free(list->items);
}

int list_add(list_t* list, const int item){
	// usage of private behavior
	if(__list_is_full(list)){
		return -1;
	}
	list->items[list->size++] = item;
	return 0;
}

int list_get(list_t* list, const int index, int* result){
	if(__check_index(list, index)){
		*result = list->items[index];
		return 0;
	}
	return -1;
}

void list_clear(list_t* list){
	list->size = 0;
}

size_t list_size(list_t* list){
	return list->size;
}

void list_print(list_t* list){
	printf("[");
	for(size_t i = 0;i< list->size;i++){
		printf("%d ", list->items[i]);
	}printf("]\n");
}

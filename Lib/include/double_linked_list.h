#pragma once

#include <stdio.h>

typedef struct node node_t;

typedef struct list {
	node_t* head;
	node_t* tail;
	size_t length;
} list_t;

struct node {
	int data;
	node_t* prev_node;
	node_t* next_node;
};

void init_list(list_t* list);
void release_list(list_t* list);

void print_list(list_t* list);

void insert_front(list_t* list, int data);
void insert_back(list_t* list, int data);
void insert_at_list(list_t* list, int data, size_t idx);
void insert_sorted(list_t* sorted_list, int data);

void remove_front(list_t* list);
void remove_back(list_t* list);
void remove_at_node(list_t* list, size_t idx);

void search_node(list_t* list, int data);

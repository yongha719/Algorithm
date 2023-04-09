#pragma once

#include <stdio.h>

typedef struct
{
	double* datas;
	size_t length;
	size_t capacity;
	
	int entry_pos;
	int exit_pos;

	int use_ring_buffer;
} queue_t;

void init_queue(queue_t* queue, size_t capacity, int use_ring_buffer);
void release_queue(queue_t* queue);

void enqueue(queue_t* queue, double data);
double dequeue(queue_t* queue);

void print_queue(queue_t* queue);

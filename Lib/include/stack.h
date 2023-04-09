#pragma once

#include <stdio.h>

typedef struct
{
	double* datas;
	size_t length;
	size_t capacity;
} stack_t;

void init_stack(stack_t* stack, size_t capacity);
void release_stack(stack_t* stack);

void push_stack(stack_t* stack, double data);
void pop_stack(stack_t* stack);
double top_stack(stack_t* stack);

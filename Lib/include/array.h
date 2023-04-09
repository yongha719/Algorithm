#pragma once

#include <stdio.h>

typedef struct {
    int* datas;
    size_t length;
    size_t capacity;
} array_t;

void init_arr(array_t* arr, size_t capacity);
void release_arr(array_t* arr);

void insert_arr(array_t* arr, size_t idx, int data);
void insert_arr_unordered(array_t* arr, size_t idx, int data);
void remove_arr(array_t* arr, size_t idx);
void remove_arr_unordered(array_t* arr, size_t idx);
int search_arr(array_t* arr, int data);

void print_arr(array_t* arr);

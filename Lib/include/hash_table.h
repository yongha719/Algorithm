#pragma once

#include <stdio.h>

typedef struct {
    int* datas;
    size_t length;
    size_t capacity;
} hash_table_t;

void init_hash_table(hash_table_t* hash_table, size_t capacity);
void release_hash_table(hash_table_t* hash_table);

void insert_hash_table(hash_table_t* hash_table, int data);
int contains_hash_table(hash_table_t* hash_table, int data);

void print_hash_table(hash_table_t* hash_table);

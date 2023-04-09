#pragma once

#include <stdio.h>

typedef struct {
	char* key;
	int value;
} pair_t;

typedef struct {
	pair_t** pair_arrs;
	size_t capacity;
} dictionary_t;

void init_dictionary(dictionary_t* dictionary, size_t capacity);
void release_dictionary(dictionary_t* dictionary);

void add_dictionary(dictionary_t* dictionary, char* key, int value);
void remove_dictionary(dictionary_t* dictionary, char* key);
int contains_dictionary(dictionary_t* dictionary, char* key);

void print_dictionary(dictionary_t* dictionary);
int get_value(dictionary_t* dictionary, char* key);

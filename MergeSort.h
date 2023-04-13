#pragma once
#include <iostream>

#include "DoubleLinkedList.h"

template <typename T>
void merge(DoubleLinkedList<T>& list, int left, int right)
{
	int mid = (left + right) / 2;

	std::cout << "length " << right << '\n';

	int* temp = new int[right - left + 1];

	int l = left;
	int m = mid + 1;

	int i = left;
	int test = left;

	while (l <= mid && m <= right)
	{
		if (list[l] <= list[m]) {
			temp[i++] = list[l++];
		}
		else {
			temp[i++] = list[m++];
		}
	}

	while (l <= mid)
		temp[i++] = list[l++];
	while (m <= right)
		temp[i++] = list[m++];


	while (left <= right)
	{
		list[left] = temp[left];
		left++;
	}
}

template <typename T>
void mergesort(DoubleLinkedList<T>& list, int left, int right)
{
	if (left >= right)
		return;

	int mid = (left + right) / 2;

	mergesort(list, left, mid);
	mergesort(list, mid + 1, right);
	merge(list, left, right);
}

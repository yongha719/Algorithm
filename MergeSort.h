#pragma once
#include "DoubleLinkedList.h"
#include "utility.h"

template <typename T>
void merge(DoubleLinkedList<T>& list, int left, int right)
{
	int mid = (left + right) / 2;

	std::cout << "size " << right - left << '\n';

	int* temp = new int[right + 1];

	int l = left;
	int m = mid + 1;

	int i = left;
	int test = left;

	while (l <= mid && m <= right)
	{
		if (list[l] <= list[m]) {
			swap(list[i++], list[l++]);
		}
		else {
			swap(list[i++], list[m++]);
		}
	}

	while (l <= mid)
		swap(list[i++], list[l++]);
	while (m <= right)
		swap(list[i++], list[m++]);


	/*while (left <= right)
	{
		list[left] = temp[left];
		left++;
	}*/

	delete[] temp;
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

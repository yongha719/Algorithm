#pragma once
#include "DoubleLinkedList.h"
#include "utility.h"

template <typename T>
int partition(DoubleLinkedList<T>& list, int left, int right) {
	T pivot = list[right];

	int i = (left - 1);

	for (int j = left; j < right; j++) {
		if (list[j] < pivot) {
			++i;
			swap(list[i], list[j]);
		}
	}

	int pivotpos = i + 1; // swap이 한번도 안 일어나면 i가 -1이라 더해줌

	swap(list[pivotpos], list[right]);

	return pivotpos;
}

template <typename T>
void quicksort(DoubleLinkedList<T>& list)
{
	quicksortrecursive(list, 0, list.Length() - 1);
}

template <typename T>
void quicksortrecursive(DoubleLinkedList<T>& list, int left, int right) {
	if (left >= right)
		return;

	int pivotpos = partition(list, left, right);

	quicksortrecursive(list, left, pivotpos - 1);
	quicksortrecursive(list, pivotpos + 1, right);
}
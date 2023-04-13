#include <iostream>

#include "DoubleLinkedList.h"
#include "MergeSort.h"
#include "QuickSort.h"

using namespace std;

int main()
{
	DoubleLinkedList<int> list;
	list = { 2, 4, 1, 5, 3, 3, 5, 5 };
	list[5] = 1000;

	mergesort(list, 0, list.Length() - 1);

	quicksort(list);

	for (int i = 0; i < list.Length(); i++) {
		cout << list[i] << '\n';
	}	

	system("pause");

	return 0;
}
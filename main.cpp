#include <assert.h>
#include <iostream>
#include <string.h>

#include "DoubleLinkedList.h"

using namespace std;

enum Order
{
	Order_Exit, Order_Add, Order_Remove, Order_Print
};


int main()
{
	DoubleLinkedList<int> list;

	list.Add(3);
	list.Add(10);
	list.Add(4);
	list.Add(12, 10);

	int num = list[1];

	list.Remove(num);
	list.RemoveAt(0);

	cout << list[1];

	return 0;
}
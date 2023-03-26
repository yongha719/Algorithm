#include <iostream>
#include <assert.h>

#include "DoubleLinkedList.h"

Node* head = nullptr;
Node* curnode = nullptr;

Node* Add(Node* const node)
{
	// 현재 노드가 NULL이 아닐때
	if (curnode != nullptr) {
		curnode->nextnode = node;
		curnode->prevnode = curnode;
		curnode = node;
		return curnode;
	}

	// 처음 들어오는 노드이므로 초기화
	if (head == nullptr) {
		head = node;
		curnode = head;
		return curnode;
	}

	// 추가 못 할시 nullptr 반환하고 그냥 리턴
	return nullptr;
}

//template <typename T>
void Remove(int node)
{

}

void PrintNodes()
{
	if (head != nullptr) {
		Node* printnode = head;
		while (printnode->nextnode != nullptr) {
			std::cout << printnode->data << '\n';
			printnode = printnode->nextnode;
		}
	}
}

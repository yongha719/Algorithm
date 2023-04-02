#include <iostream>
#include <assert.h>

#include "DoubleLinkedList.h"

// c++ 예외 클래스
// https://learn.microsoft.com/ko-kr/cpp/standard-library/stdexcept?view=msvc-170

template<typename T>
Node<T>* DoubleLinkedList<T>::FindByIndex(int index)
{
	if (index < 0 && size < index)
		throw std::invalid_argument("index is negative");

	Node<T*> findnode = head;

	int i;
	for (i = 0; i < index && findnode != nullptr; i++)
		findnode = findnode->nextnode;

	if (i != index)
		throw std::out_of_range("index is out of range");

	return findnode;
}

template<typename T>
Node<T>* DoubleLinkedList<T>::FindByData(T data)
{
	Node<T>* findnode = head;

	while (findnode != nullptr && findnode->data != data)
		findnode = findnode->nextnode;

	return findnode;
}

template <typename T>
void DoubleLinkedList<T>::Add(T data) {
	Node<T>* newnode = new Node<T>(data);

	if (head != nullptr) {
		tail->nextnode = newnode;
		newnode->prevnode = tail;
		tail = newnode;
	}
	else {
		head = newnode;
		tail = newnode;
	}

	size++;
}

template<typename T>
void DoubleLinkedList<T>::Add(T data, int index)
{
	Node<T>* newnode = new Node<T>(data);

	if (head != nullptr) {
		if (index == 0) {
			newnode->nextnode = head;
			head->prevnode = newnode;
			head = newnode;
		}
		else if (index >= size) {
			newnode->prevnode = tail;
			tail->nextnode = newnode;
			tail = newnode;
		}
		else {
			Node<T>* prevnode = FindByIndex(index - 1);
			Node<T>* nextnode = prevnode->nextnode;

			prevnode->nextnode = newnode;
			newnode->prevnode = prevnode;

			newnode->nextnode = nextnode;
			nextnode->prevnode = newnode;
		}
	}
	else {
		head = newnode;
		tail = newnode;
	}

	size++;
}

template<typename T>
void DoubleLinkedList<T>::Remove(T data)
{
	Node<T>* removenode = head;

	while (removenode != nullptr && removenode->data != data)
		removenode = removenode->nextnode;

	if (removenode == nullptr)
		return;

	if (removenode == head) {
		head = removenode->nextnode;

		if (head != nullptr)
			head->prevnode = nullptr;
	}
	else {
		// 가독성 너무 별론데
		removenode->prevnode->nextnode = removenode->nextnode;

		if (removenode->nextnode != nullptr)
			removenode->nextnode->prevnode = removenode->prevnode;
	}

	delete removenode;
}

template<typename T>
void DoubleLinkedList<T>::RemoveAt(int data)
{
	Node<T>* removenode = FindByIndex(data);

	if (removenode == nullptr)
		return;

	if (removenode == head) {
		head = removenode->nextnode;

		if (head != nullptr)
			head->prevnode = nullptr;
	}
	else {
		removenode->prevnode->nextnode = removenode->nextnode;

		if (removenode->nextnode != nullptr)
			removenode->nextnode->prevnode = removenode->prevnode;
	}

	delete removenode;
	removenode = nullptr;
}

template<typename T>
void DoubleLinkedList<T>::Clear()
{
	Node<T>* deletenode = nullptr;

	while (head != nullptr && head->nextnode != nullptr)
	{
		deletenode = head;
		head = head->nextnode;
		head->prevnode = nullptr;
		delete deletenode;
		deletenode = nullptr;
	}

	if (head != nullptr) {
		delete head;
		head = nullptr;
	}

	tail = nullptr;
}




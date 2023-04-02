#pragma once

template <typename T>
struct Node
{
	T data;
	Node<T>* prevnode;
	Node<T>* nextnode;

	Node(T _data) {
		data = _data;
		prevnode = nullptr;
		nextnode = nullptr;
	}

};

template <typename T>
class DoubleLinkedList
{
private:
	Node<T>* head;
	Node<T>* tail;
	int size = 0;

	Node<T>* FindByIndex(int index);
	Node<T>* FindByData(T data);

public:
	DoubleLinkedList() {
		head = nullptr;
		tail = nullptr;
	}

	~DoubleLinkedList() {
		Clear();
	}

	int Length() {
		return size;
	}

	void Add(T data);
	void Add(T data, int index);
	void Remove(T data);
	void RemoveAt(int data);
	void Clear();

	T operator [](int data) {
		Node<T>* indexnode = head;

		for (int i = 0; i < data; i++) {
			indexnode = indexnode->nextnode;
		}

		return indexnode->data;
	}
};

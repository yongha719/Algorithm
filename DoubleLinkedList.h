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

public:

	DoubleLinkedList() {
		head = nullptr;
		tail = nullptr;
	}

	~DoubleLinkedList() {
		Node<T>* deletenode = nullptr;

		while (head->nextnode != nullptr)
		{
			deletenode = head;
			head = head->nextnode;
			delete deletenode;
		}
	}

	int Length() {
		return size;
	}

};


//Node* Add(Node* node);
//void Remove(int node);
//void PrintNodes();
//bool Contains(Node* node);

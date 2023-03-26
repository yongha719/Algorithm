#pragma once

struct Node
{
	Node* prevnode;
	Node* nextnode;
	int data;
};

Node* Add(Node* node);
void Remove(int node);
void PrintNodes();

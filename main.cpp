#include <assert.h>
#include <iostream>
#include <string.h>

#include "DoubleLinkedList.h"

using namespace std;

int main()
{
	string input;
	int num;

	while (true)
	{
		cin >> input;
		cout << '\n';

		if (input == "1") {
			cout << "추가할 정수 값을 입력해주세요";
			cin >> num;
			cin.clear();

			Node* node = (Node*)malloc(sizeof(Node));

			assert(node != nullptr);

			node->data = num;
			Add(node);
			continue;
		}

		if (input == "2")
		{
			PrintNodes();
		}
	}

	return 0;
}
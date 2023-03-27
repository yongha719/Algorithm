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
	int input;
	int num;

	while (true)
	{
		cin >> input;
		cout << '\n';

		if (input == Order_Exit) {
			cout << "프로그램을 종료합니다.";
			break;
		}

		if (input == Order_Add) {
			cout << "추가할 정수 값을 입력해주세요 : ";
			cin >> num;
			cin.clear();

			Node* node = (Node*)malloc(sizeof(Node));

			assert(node != nullptr);

			node->data = num;
			Add(node);
			continue;
		}

		if (input == Order_Remove)
		{
			cout << "삭제할 정수 값을 입력해주세요 : ";
			cin >> num;
			cin.clear();

			if (Remove(num) == false) {
				cout << "삭제할 노드는 존재하지 않는 값입니다.\n";
			}

			continue;
		}

		if (input == Order_Print) {
			PrintNodes();
			continue;
		}

		cout << "잘못된 숫자를 입력하셨습니다.\n";
	}

	return 0;
}
#include <iostream>
#include <string.h>
// BOJ - 1406 Editor
#define MAX_STACK_SIZE		600001

using namespace std;

struct Stack {
	char * data;
	int size;

	Stack() {
		data = new char[MAX_STACK_SIZE];
		size = 0;
	}

	void push(char chr) {
		data[size++] = chr;
	}

	bool empty(void) {
		if (size == 0)
			return true;
		return false;
	}

	char pop(void) {
		if (empty())
			return -1;
		return data[--size];
	}
};

int main(void) {
	char input[MAX_STACK_SIZE];
	int strSize, M, frontSize, rearSize;
	char option, pInput;
	Stack front, rear;

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> input; cin >> M;
	strSize = strlen(input);
	for (int i = 0; i < strSize; i++)
		front.push(input[i]);

	while (M--) {
		cin >> option;

		switch (option){
		case 'L':
			if (front.empty())
				break;
			rear.push(front.pop());
			break;
		case 'D':
			if (rear.empty())
				break;
			front.push(rear.pop());
			break;
		case 'B':
			if (front.empty())
				break;
			front.pop();
			break;
		case 'P':
			cin >> pInput;
			strSize = front.size + rear.size;
			strSize++;
			if (strSize == MAX_STACK_SIZE) {
				strSize--;
				break;
			}
			front.push(pInput);
		default:
			break;
		}
	}
	frontSize = front.size;
	rearSize = rear.size;

	for (int i = 0; i < frontSize; i++)
		input[frontSize - 1 - i] = front.pop();
	for (int i = 0; i < frontSize; i++)
		cout << input[i];
	for (int i = 0; i < rearSize; i++)
		cout << rear.pop();

	return 0;
}
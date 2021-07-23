#include <iostream>
#include <string.h>
// BOJ - 10845 Queue
#define MAX_SIZE	100000

using namespace std;

struct Queue {
	int data[MAX_SIZE];
	int front, rear;

	Queue() {
		front = 0;
		rear = 0;
	}

	void push(int num) {
		data[rear++] = num;
	}

	bool empty() {
		if (front == rear)
			return true;
		return false;
	}

	int pop() {
		if (empty())
			return -1;
		return data[front++];
	}

	int size() {
		return rear - front;
	}

	int qFront() {
		if (empty())
			return -1;
		return data[front];
	}

	int qBack() {
		if (empty())
			return -1;
		return data[rear - 1];
	}
};

int whatOption(char *option) {
	if (!strcmp(option, "push"))
		return 1;
	else if (!strcmp(option, "pop"))
		return 2;
	else if (!strcmp(option, "front"))
		return 3;
	else if (!strcmp(option, "back"))
		return 4;
	else if (!strcmp(option, "size"))
		return 5;
	else if (!strcmp(option, "empty"))
		return 6;
	else
		return -1;
}

int main(void) {
	int N, num;
	char option[10];
	Queue q;

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;

	while (N--) {
		cin >> option;

		switch (whatOption(option)) {
		case 1:
			cin >> num;
			q.push(num);
			break;
		case 2:
			cout << q.pop() << '\n';
			break;
		case 3:
			cout << q.qFront() << '\n';
			break;
		case 4:
			cout << q.qBack() << '\n';
			break;
		case 5:
			cout << q.size() << '\n';
			break;
		case 6:
			cout << q.empty() << '\n';
			break;
		default: break;
		}
	}

	return 0;
}
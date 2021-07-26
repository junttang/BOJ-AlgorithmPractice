#include <iostream>
#include <string.h>
// BOJ - 10866 Deque

/*
덱은, 입력 사이즈가 커질수록, 결국 순회적인 배열보다는
연결리스트를 사용하는 것이 당연해진다. 이때, 더블리연결이
필요하다. 이유는? 싱글링크드인 경우 back 관련 연산 시
순회가 필요해지는데 이러면 시간복잡도 노력이 무의미해지므로
*/

using namespace std;

struct _node {
	int data;
	struct _node * left;
	struct _node * right;
};

struct Deque {
	struct _node * head, * tail;
	int size;

	Deque() {
		head = tail = NULL;
		size = 0;
	}

	void push_front(int num) {
		struct _node * newNode = new struct _node;

		newNode->data = num;
		newNode->left = NULL;
		newNode->right = NULL;

		if (size == 0) {
			head = newNode;
			tail = newNode;
		}

		else {
			newNode->right = head;
			head->left = newNode;
			head = newNode;
		}

		size++;
	}

	void push_back(int num) {
		struct _node * newNode = new struct _node;

		newNode->data = num;
		newNode->left = NULL;
		newNode->right = NULL;

		if (size == 0) {
			head = newNode;
			tail = newNode;
		}

		else {
			tail->right = newNode;
			newNode->left = tail;
			tail = newNode;
		}

		size++;
	}

	bool empty() {
		if (size == 0)
			return true;
		return false;
	}

	int pop_front() {
		int delNum;
		struct _node * delNode;

		if (empty())
			return -1;

		delNode = head;
		delNum = delNode->data;
		if (size == 1)
			head = tail = NULL;
		else {
			head = head->right;
			head->left = NULL;
		}

		delete delNode;
		size--;

		return delNum;
	}

	int pop_back() {
		int delNum;
		struct _node * delNode;

		if (empty())
			return -1;

		delNode = tail;
		delNum = delNode->data;
		if (size == 1)
			head = tail = NULL;
		else {
			tail = tail->left;
			tail->right = NULL;
		}

		delete delNode;
		size--;

		return delNum;
	}

	int front() {
		if (empty())
			return -1;
		return head->data;
	}

	int back() {
		if (empty())
			return -1;
		return tail->data;
	}
};

int whatIsOption(char * option) {
	if (!strcmp(option, "push_front")) return 1;
	else if (!strcmp(option, "push_back")) return 2;
	else if (!strcmp(option, "pop_front")) return 3;
	else if (!strcmp(option, "pop_back")) return 4;
	else if (!strcmp(option, "size")) return 5;
	else if (!strcmp(option, "empty")) return 6;
	else if (!strcmp(option, "front")) return 7;
	else if (!strcmp(option, "back")) return 8;
}

int main(void) {
	int N, num;
	char option[20];
	Deque dq;

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;

	while (N--) {
		cin >> option;

		switch (whatIsOption(option)) {
		case 1: cin >> num; dq.push_front(num); break;
		case 2: cin >> num; dq.push_back(num); break;
		case 3: cout << dq.pop_front() << '\n'; break;
		case 4: cout << dq.pop_back() << '\n'; break;
		case 5: cout << dq.size << '\n'; break;
		case 6: cout << dq.empty() << '\n'; break;
		case 7: cout << dq.front() << '\n'; break;
		case 8: cout << dq.back() << '\n';
		default: break;
		}
	}

	return 0;
}
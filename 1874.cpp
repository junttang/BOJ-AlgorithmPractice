#include <iostream>
// BOJ - 1874 Stack Sequence
#define MAX_NUM		100000

using namespace std;

typedef struct node {
	char plusminus;
	struct node * link;
}Node;

struct Stack {
	int data[MAX_NUM + 1];
	int size;

	Stack() {
		size = 0;
	}

	void push(int num) {
		data[size] = num;
		size += 1;
	}

	bool empty() {
		if (size == 0)
			return true;
		return false;
	}

	int pop() {
		if (empty())
			return -1;
		size -= 1;
		return data[size];
	}

	int top() {
		if (empty())
			return -1;
		return data[size - 1];
	}
};

Node* connect(Node**tail, char info) {
	Node * temp = new Node;

	temp->plusminus = info;
	(*tail)->link = temp;
	*tail = temp;

	return *tail;
}

int main(void) {
	int n, k, arr, flag = 0;
	char print[MAX_NUM + 1];
	int printIdx = 0;
	Stack s;
	Node * head = new Node;
	Node * tail = head;

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);		

	cin >> n; cin >> arr;

	if (n == 1 && arr != 1) {
		cout << "NO\n";
		return 0;
	}
	n--;

	for (k = 1; k <= arr; k++) {
		s.push(k);
		tail = connect(&tail, '+');
	}
	s.pop();
	tail = connect(&tail, '-');

	while (n--) {
		cin >> arr;

		if (arr > s.top()) {
			for (; k <= arr; k++) {
				s.push(k);
				tail = connect(&tail, '+');
			}
			if (s.top() == arr) {
				s.pop();
				tail = connect(&tail, '-');
			}
			else flag = 1;
		}

		else if (arr == s.top()) {
			s.pop();
			tail = connect(&tail, '-');
		}

		else flag = 1;
	}
	tail->link = NULL;

	if (flag)
		cout << "NO\n";
	else {
		head = head->link;
		while (head) {
			cout << head->plusminus << "\n";
			head = head->link;
		}
	}

	return 0;
}
// 4 3 6 8 7 5 2 1
// 1 2 3 4
// 1 2 3			4
// 1 2				43
// 1 2 5 6			43
// 1 2 5			436
// 1 2 5 7 8		436
// 1 2 5 7			4368
// 1 2 5			43687
// 1 2				436875
// ...				43687521

// ���� 42..�̷����̸�
// 1 2 3 4
// 1 2 3			4
// 1 2 3 -> �Ұ�

// ��, AB������ ������, B�� A���� ū �Ŵ� ������ �ȵȴ�.
// �׸��� B�� A	���� �ϳ� �����ŵ� ������ �ȵȴ�.
// �׷��� B�� A ���� �� �̻� ������ �װŴ� �Ұ����ϴ�.
// ���� ����ó�� ���ص� ������ ��?

/*
��� Ʋ�� ���� : ����� �� �ܼ��� �迭�� ó���ؼ� �׷���. �ܼ��� ���� 8�� ������
8���� �ξ� ū ũ���� �޸� ������ �ʿ��ѵ�, ���� �װ��� �����ߴ�.
*/
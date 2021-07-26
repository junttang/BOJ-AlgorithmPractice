#include <iostream>
// BOJ - 1158 �����۽�
#define MAX_NUM		100000
/*
�ʱ⿡ �Ǽ��� ���� : ������ ���� ����.
�� ��° ���⿡�� Ʋ�� ����
-> �ᱹ ���� �ۼ��� ť�� naive�ϰ� �迭�� �̿��� ť�ε�,
�̷��� ť�� ��� �迭 ũ�⸦ �ʰ��ϴ� �Է��� �߻��� �� ������
�� ����ؾ��Ѵ�. �� ���, ���� ��� 5000 5000�� �ԷµǴ� ���
�迭 ũ�⸦ �ʰ��� front, rear �޸� ������ �߻��Ѵ�. ����
�Ʒ��� �����ڵ�ó�� front�� rear�� MAX_NUM�� �������� ���� ó
���� �ʿ��ϴ�. �̶�, push�� pop�� �����ϰ� �Ͼ�鼭 pop�� ��
�� �� �Ͼ ť�� �پ��� ���·� ������ ����ǹǷ�, ��������
�����Ǵ� ť�� ���� �ʿ�� ����. ���� �Ʒ�ó�� �����ϰ� ���ǹ�
�� �߰����� �������� ť�� ���ư��� ���ָ� �ȴ�.
*/

using namespace std;

struct Queue {
	int data[MAX_NUM];
	int front, rear;

	Queue() {
		front = 0;
		rear = 0;
	}

	void push(int num) {
		data[rear++] = num;
		if (rear == MAX_NUM)
			rear = 0;
	}

	bool empty() {
		if (front == rear)
			return true;
		return false;
	}

	int pop() {
		int value;
		if (empty())
			return -1;
		value = data[front++];
		if (front == MAX_NUM)
			front = 0;
		return value;
	}
};

int main(void) {
	int N, K, temp;
	Queue q;

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K;
	temp = N;

	for (int i = 1; i <= N; i++)
		q.push(i);

	while (N--) {
		if (N == temp - 1) cout << '<';
		for (int i=0;i<K - 1;i++)
			q.push(q.pop());
		if (N == 0) cout << q.pop() << '>';
		else cout << q.pop() << ", ";
	}

	return 0;
}
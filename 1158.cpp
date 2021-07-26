#include <iostream>
// BOJ - 1158 조세퍼스
#define MAX_NUM		100000
/*
초기에 실수한 이유 : 집중을 하지 않음.
두 번째 제출에서 틀린 이유
-> 결국 내가 작성한 큐는 naive하게 배열을 이용한 큐인데,
이러한 큐의 경우 배열 크기를 초과하는 입력이 발생할 수 있음을
늘 고려해야한다. 이 경우, 예를 들어 5000 5000이 입력되는 경우
배열 크기를 초과한 front, rear 메모리 접근이 발생한다. 따라서
아래의 정해코드처럼 front와 rear가 MAX_NUM과 같아졌을 때의 처
리가 필요하다. 이때, push와 pop이 균일하게 일어나면서 pop이 한
번 더 일어나 큐가 줄어드는 형태로 문제가 진행되므로, 동적으로
유지되는 큐를 만들 필요는 없다. 따라서 아래처럼 간단하게 조건문
을 추가시켜 원형으로 큐가 돌아가게 해주면 된다.
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
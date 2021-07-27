#include <iostream>
#include <stack>
// BOJ - 17298 NGE ��ū��

/*
�̷��� ������ �ٽ��� ������ ������ �����ϴµ��� �ִ�.
�ᱹ �� �������� ������ �ʿ��ߴ� ���� ū ������,
"5 2 7�� ������ �ִ� ��� NGE ������ 7 7 -1�ε�,
5�� �ٷ� ������ ���� ���� 5���� ���� ���, ��, ����ó��
2�� �� ���, 5�� ŵ�صΰ�, 2�� ���ؼ� �ٽ� ���� ����(�ٷ�
������ ���� ���� ��)�� �ؼ� 7�̴ϱ� �� ũ�Ƿ� 2�� �ε��� 1��
7��, �׸��� pop�� �� ��, ���ÿ� �����ִ� ģ���� 5�� ���ؼ��� 7��
5���� �� ũ�Ƿ� 5�� �ε��� 0�� 7�� �־��ִ� ����"
�ٷ� �� �κп��� "ŵ��"���� ������ ������ ������ �����ؾ��Ѵ�.
*/

using namespace std;

int main(void) {
	int N, *arr, *nge, n;
	stack<int> s;

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	arr = new int[N];
	nge = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> n;
		arr[i] = n;
	}

	s.push(0);
	for (int i = 1; i < N; i++) {
		if (arr[s.top()] < arr[i]) {
			while (!s.empty() && arr[s.top()] < arr[i]) {
				nge[s.top()] = arr[i];
				s.pop();
			}
		}
		s.push(i);
	}
	while (!s.empty()) {
		nge[s.top()] = -1;
		s.pop();
	}

	for (int i = 0; i < N; i++)
		cout << nge[i] << ' ';

	return 0;
}
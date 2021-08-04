#include <iostream>
// BOJ - 11052 Buying Cards
#define MAX_CARDS		1000
using namespace std;

/*
���� �� ������ �ִ� ��ȭ��.
��ó��, �� �� �̻��� �迭 ���� ����(���� ��� �ִ�)
�� �̿��� ��ȭ���� �����ؾ��ϴ� ��쵵 �ִ�.

�̷��� ����, ���� �� ���Ǳ�� ��ȭ���踦 �ľ��ϸ� �ȴ�.
*/

int D[MAX_CARDS + 1];
int P[MAX_CARDS + 1];

void makeDArray(int N) {
	int temp;
	// D[i] = max(P[j] + D[i-j])
	for (int i = 1; i <= N; i++) {
		temp = 0;
		for (int j = 1; j < N, j <= i; j++) {
			if (D[i - j] + P[j] > temp)
				temp = D[i - j] + P[j];
		}
		D[i] = temp;
	}
}

int main(void) {
	int N;

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> P[i];
	makeDArray(N);
	cout << D[N];

	return 0;
}
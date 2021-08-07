#include <iostream>
// BOJ - 14002 LIS 4
#define MAX_LEN		1000
using namespace std;
// A[i] : ����
int A[MAX_LEN + 1];
int D[MAX_LEN + 1];
int V[MAX_LEN + 1];	// ��Ʈ��ŷ�� ���� �ε��� ��� �迭
int LISIdx = 1;		// ��Ʈ��ŷ�� ����
// D[i] : ������ ��Ұ� A[i]�� LIS�� ����

/*
�Ⱦ �κм����� ��ҵ��� ����ϴ�, ��, ��Ʈ��ŷ�� �ʿ���
�����̴�.

��Ʈ��ŷ���� ���� ����� �����ϸ�, �Ϲ������δ� ���� ����
�ε����� ����� �迭�� �����Ͽ� ����� �����ϰ� �Ѵ�.
*/

int makeDArray(int N) {
	int max = 1;
	D[1] = 1;

	for (int i = 2; i <= N; i++) {
		D[i] = 1;
		V[i] = i;
		for (int j = 1; j < i; j++) {
			if (A[j] < A[i] && D[i] < D[j] + 1) {
				D[i] = D[j] + 1;
				V[i] = j;
				if (D[i] > max) { max = D[i]; LISIdx = i; }
			}
		}
	}

	return max;
}

void printVArray(int len) {
	int * printIdx;
	printIdx = new int[len];

	for (int i = 0; i < len; i++) {
		printIdx[len - 1 - i] = LISIdx;
		LISIdx = V[LISIdx];
	}

	for (int i = 0; i < len; i++)
		cout << A[printIdx[i]] << ' ';

	delete[] printIdx;
}

int main(void) {
	int N, len;

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> A[i];
	cout << (len = makeDArray(N)) << '\n';
	printVArray(len);

	return 0;
}
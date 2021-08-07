#include <iostream>
// BOJ - 11053 LIS
#define MAX_LEN		1000
using namespace std;
// A[i] : ����
int A[MAX_LEN + 1];
int D[MAX_LEN + 1];
// D[i] : ������ ��Ұ� A[i]�� LIS�� ����

/*
DP���� ��ȭ���� �Ϲ����� �ǹ̸� �ݵ�� ����Ǽ��θ�
�ٶ� �ʿ䰡 ������ Ȯ���� �� �ִ� ����

D[i] < D[j] + 1�̶�� ������ �߿�. �̰� ������ Ȥ����
D�� �迭�� 1 2 3 2 �� ���� ���� �� ������ �� ����.
*/

int makeDArray(int N) {
	int max = 1;
	D[1] = 1;

	for (int i = 2; i <= N; i++) {
		D[i] = 1;
		for (int j = 1; j < i; j++) {
			if (A[j] < A[i] && D[i] < D[j] + 1) {
				D[i] = D[j] + 1;
				if (D[i] > max) max = D[i];
			}
		}
	}

	return max;
}

int main(void) {
	int N;

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> A[i];
	cout << makeDArray(N);

	return 0;
}
#include <iostream>
// BOJ - 2225 �պ���
#define DIVISOR		1000000000
#define MAX_NUM		200
using namespace std;
// D[K][N] : K���� ������ N�� ����� ����Ǽ�
long long D[MAX_NUM + 1][MAX_NUM + 1];
// N = L + N-L -> D[K][N] = sum(D[K-1][N-L]) L: 0~N
long long makeDArray(int K, int N) {
	long long sum;

	for (int i = 0; i <= N; i++)
		D[1][i] = 1;

	for (int i = 2; i <= K; i++) {
		for (int j = 0; j <= N; j++) {	// N = 0 �� ���� �߿���.
			sum = 0;	// N=0�̶�� �ؼ� D�� �� 0������ ���� �ƴϱ� ����
			for (int l = 0; l <= j; l++)
				sum += D[i - 1][j - l] % DIVISOR;
			D[i][j] = sum % DIVISOR;
		}
	}

	return D[K][N] % DIVISOR;
}

int main(void) {
	int N, K;

	cin >> N >> K;
	cout << makeDArray(K, N);

	return 0;
}

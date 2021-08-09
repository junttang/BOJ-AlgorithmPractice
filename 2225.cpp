#include <iostream>
// BOJ - 2225 합분해
#define DIVISOR		1000000000
#define MAX_NUM		200
using namespace std;
// D[K][N] : K개의 정수로 N을 만드는 경우의수
long long D[MAX_NUM + 1][MAX_NUM + 1];
// N = L + N-L -> D[K][N] = sum(D[K-1][N-L]) L: 0~N
long long makeDArray(int K, int N) {
	long long sum;

	for (int i = 0; i <= N; i++)
		D[1][i] = 1;

	for (int i = 2; i <= K; i++) {
		for (int j = 0; j <= N; j++) {	// N = 0 일 때가 중요함.
			sum = 0;	// N=0이라고 해서 D가 꼭 0가지인 것이 아니기 때문
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

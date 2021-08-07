#include <iostream>
// BOJ - 2193 이친수
#define MAX_NUM		90

using namespace std;
// D[i][j] : 길이가 j이고, i로 끝나는 경우의 수
long long D[MAX_NUM + 1][2];
// D[i][0] = D[i-1][0] + D[i-1][1]
long long makeDArray(long long N) {
	D[1][1] = 1;

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= 1; j++) {
			if (j == 0)
				D[i][j] = D[i - 1][0] + D[i - 1][1];
			else
				D[i][j] = D[i - 1][0];
		}
	}

	return D[N][0] + D[N][1];
}

int main(void) {
	long long N;

	cin >> N;
	cout << makeDArray(N);

	return 0;
}
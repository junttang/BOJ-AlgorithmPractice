#include <iostream>
// BOJ - 1309 Zoo
#define MAX_SIZE	100000
#define DIVISOR		9901
using namespace std;
// D[i][j] : i번째줄 우리. 마지막 j꼴로 배치 경우의수
long long D[MAX_SIZE + 1][4]; 
// 옵션 1은 무배치, 2는 우배치, 3은 좌배치
long long makeDArray(int N) {
	D[1][1] = 1; D[1][2] = 1; D[1][3] = 1;

	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= 3; j++) {
			switch (j) {
			case 1: D[i][j] = D[i - 1][1] % DIVISOR 
				+ D[i - 1][2] % DIVISOR 
				+ D[i - 1][3] % DIVISOR; break;
			case 2: D[i][j] = D[i - 1][1] % DIVISOR 
				+ D[i - 1][3] % DIVISOR; break;
			case 3: D[i][j] = D[i - 1][1] % DIVISOR
				+ D[i - 1][2] % DIVISOR; break;
			}
		}
	}

	return D[N][1] % DIVISOR + D[N][2] % DIVISOR + D[N][3] % DIVISOR;
}

int main(void) {
	int N;

	cin >> N;
	cout << makeDArray(N) % DIVISOR;

	return 0;
}

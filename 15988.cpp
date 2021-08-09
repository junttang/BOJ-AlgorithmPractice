#include <iostream>
// BOJ - 15988 Adding 1,2,3 - 3
#define MAX_NUM		1000000
#define DIVISOR		1000000009
using namespace std;

long long D[MAX_NUM + 1][4];
// D[i][j] = D[i-j][1] + D[i-j][2] + D[i-j][3]
void makeDArray(void) {
	D[1][1] = 1; D[2][1] = 1; D[2][2] = 1;
	D[3][1] = 2; D[3][2] = 1; D[3][3] = 1;
	for (int i = 4; i <= MAX_NUM; i++) {
		for (int j = 1; j <= 3; j++)
			D[i][j] = D[i - j][1] % DIVISOR 
			+ D[i - j][2] % DIVISOR + D[i - j][3] % DIVISOR;
	}
}

int main(void) {
	int T, n;
	long long d;

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	makeDArray();

	while (T--) {
		cin >> n;
		d = D[n][1] % DIVISOR + D[n][2] % DIVISOR + D[n][3] % DIVISOR;
		cout << d % DIVISOR << '\n';		// 이 부분 늘 조심하자
	}

	return 0;
}
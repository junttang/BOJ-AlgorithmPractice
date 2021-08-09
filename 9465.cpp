#include <iostream>
// BOJ - 9465 Sticker
#define MAX_LINE	100000
using namespace std;
// D[i][j] : 우측 마지막 꼴이 j인, 가로줄이 i개에서 max
int D[MAX_LINE + 1][4]; // 1 무배치, 2 위배치, 3 하배치
// D[i][1] = D[i-1][2] ~~
/*
점화식의 일반항의 의미를 경우의 수로 두는지, 최댓값으로 두는지
합으로 두는지 등이 DP 문제 풀이의 매우 중요한 요소이다.

그리고, 늘 그렇듯, 마지막 요소에 주목하는 센스도 중요하다.
*/
int makeDArray(int**st, int n) {
	D[1][2] = st[0][1]; D[1][3] = st[1][1];

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= 3; j++) {
			switch (j) {
			case 1: D[i][j] = (D[i - 1][1] >= D[i - 1][2] ?
				D[i - 1][1] : D[i - 1][2]) >= D[i - 1][3] ?
				(D[i - 1][1] >= D[i - 1][2] ? D[i - 1][1] : D[i - 1][2])
				: D[i - 1][3]; break;
			case 2: D[i][j] = (D[i - 1][1] >= D[i - 1][3] ?
				D[i - 1][1] : D[i - 1][3]) + st[0][i]; break;
			case 3: D[i][j] = (D[i - 1][2] >= D[i - 1][1] ?
				D[i - 1][2] : D[i - 1][1]) + st[1][i]; break;
			}
		}
	}

	return (D[n][1] >= D[n][2] ? D[n][1] : D[n][2]) >= D[n][3] ?
		(D[n][1] >= D[n][2] ? D[n][1] : D[n][2]) : D[n][3];
}

void resetDArray(int n) {
	for (int i = 0; i <= n; i++) {
		for (int j = 1; j <= 3; j++)
			D[i][j] = 0;
	}
}

int main(void) {
	int T, n;
	int **st;

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	while (T--) {
		cin >> n;

		st = new int*[2];
		st[0] = new int[n + 1];
		st[1] = new int[n + 1];
		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= n; j++)
				cin >> st[i][j];
		}
		cout << makeDArray(st, n) << '\n';
		
		delete[] st[0]; delete[] st[1];
		delete[] st; resetDArray(n);
	}

	return 0;
}
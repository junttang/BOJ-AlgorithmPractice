#include <iostream>
// BOJ - 9465 Sticker
#define MAX_LINE	100000
using namespace std;
// D[i][j] : ���� ������ ���� j��, �������� i������ max
int D[MAX_LINE + 1][4]; // 1 ����ġ, 2 ����ġ, 3 �Ϲ�ġ
// D[i][1] = D[i-1][2] ~~
/*
��ȭ���� �Ϲ����� �ǹ̸� ����� ���� �δ���, �ִ����� �δ���
������ �δ��� ���� DP ���� Ǯ���� �ſ� �߿��� ����̴�.

�׸���, �� �׷���, ������ ��ҿ� �ָ��ϴ� ������ �߿��ϴ�.
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
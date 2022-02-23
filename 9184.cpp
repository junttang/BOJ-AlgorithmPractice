#include <iostream>
// BOJ - 9184 Funny Function Running
using namespace std;

int W[101][101][101];

void solve(void) {
	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 101; j++)
			for (int k = 0; k < 101; k++)
				W[i][j][k] = 1;

	for (int i = 51; i < 101; i++) {
		for (int j = 51; j < 101; j++) {
			for (int k = 51; k < 101; k++) {
				if (i < j && j < k)
					W[i][j][k] = W[i][j][k - 1] + W[i][j - 1][k - 1]
					- W[i][j - 1][k];
				else
					W[i][j][k] = W[i - 1][j][k] + W[i - 1][j - 1][k]
					+ W[i - 1][j][k - 1] - W[i - 1][j - 1][k - 1];
			}
		}
	}

	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			for (int k = 0; k < 101; k++) {
				if (i > 70 || j > 70 || k > 70)
					W[i][j][k] = W[70][70][70];
				if (i <= 50 || j <= 50 || k <= 50)
					W[i][j][k] = 1;
			}
		}
	}
}
				

int main(void) {
	int a, b, c;
	
	solve();
	while (1) {
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) break;
		cout << "w(" << a << ", " << b << ", " << c 
			<< ") = " << W[a + 50][b + 50][c + 50] << '\n';
	}

	return 0;
}
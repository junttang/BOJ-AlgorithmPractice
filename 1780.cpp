#include <iostream>
// BOJ - 1780 Number of Papers
using namespace std;

int paper[2188][2188];
int oneCnt, zeroCnt, minusCnt;

void solve(int n, int w, int h) {
	int minus = 0, zero = 0, one = 0;

	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) {
			if (paper[w + i][h + j] == 1) one++;
			else if (paper[w + i][h + j] == 0) zero++;
			else minus++;
		}

	if (one == (n*n)) { oneCnt++; return; }
	if (zero == (n*n)) { zeroCnt++; return; }
	if (minus == (n*n)) { minusCnt++; return; }

	solve(n / 3, w, h); solve(n / 3, w + n / 3, h); solve(n / 3, w, h + n / 3); 
	solve(n / 3, w + n / 3, h + n / 3); solve(n / 3, w + 2 * n / 3, h); solve(n / 3, w, h + 2 * n / 3);
	solve(n / 3, w + 2 * n / 3, h + 2 * n / 3); solve(n / 3, w + 2 * n / 3, h + n / 3); solve(n / 3, w + n / 3, h + 2 * n / 3);
}

int main(void) {
	int n;

	cin >> n;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++) 
			cin >> paper[i][j];
	solve(n, 1, 1);
	cout << minusCnt << '\n' << zeroCnt << '\n' << oneCnt;

	return 0;
}
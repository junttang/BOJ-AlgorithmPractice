#include <iostream>
#include <algorithm>
// BOJ - 9663 N-Queen
using namespace std;

int board[15][15];
int cnt, waycnt;

void updateBoard(int n, int x, int y, int option) {
	for (int i = 0; i < n; i++) {
		board[i][y] += option; board[x][i] += option;
	}

	int i = x, j = y;
	while (i >= 0 && j >= 0 && i < n && j < n) board[i++][j++] += option;
	i = x, j = y;
	while (i >= 0 && j >= 0 && i < n && j < n) board[i--][j++] += option;
	i = x, j = y;
	while (i >= 0 && j >= 0 && i < n && j < n) board[i++][j--] += option;
	i = x, j = y;
	while (i >= 0 && j >= 0 && i < n && j < n) board[i--][j--] += option;
	board[x][y] -= 5 * option;
}

void solve(int n, int x, int y) {
	if (cnt == n) { waycnt++; return; }

	for (int j = 0; j < n; j++) {
		if (board[x][j] == 0) {
			updateBoard(n, x, j, 1); cnt++;
			solve(n, x + 1, j);
			updateBoard(n, x, j, -1); cnt--;
		}
	}

	return;
}

int main(void) {
	int n;

	cin >> n;
	solve(n, 0, 0);
	cout << waycnt;
		
	return 0;
}
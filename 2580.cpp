#include <iostream>
// BOJ - 2580 Sudoku
using namespace std;

int board[9][9];
bool already[10];
int proper[10];
int zeros, zerocnt;

void check(int x, int y) {
	int xx = (x / 3) * 3, yy = (y / 3) * 3;

	for (int i = 0; i < 10; i++) already[i] = false;
	for (int i = 0; i < 9; i++) {
		already[board[i][y]] = true;
		already[board[x][i]] = true;
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			already[board[xx + i][yy + j]] = true;
	}
}

bool propercheck(int x, int y, int k) {
	int xx = (x / 3) * 3, yy = (y / 3) * 3;

	for (int i = 0; i < 9; i++)
		if (board[i][y] == k) return false;
	for (int i = 0; i < 9; i++)
		if (board[x][i] == k) return false;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			if (board[xx + i][yy + j] == k)
				return false;
	}

	return true;
}

bool sudoku(int n) {
	if (zerocnt == zeros) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++)
				cout << board[i][j] << ' ';
			cout << endl;
		}
		return true;
	}

	int i = n / 9, j = n % 9;

	if (board[i][j] == 0) {	
		for (int k = 1; k <= 9; k++) {
			check(i, j);

			if (already[k] == false && propercheck(i, j, k)) {
				board[i][j] = k; already[k] = true; zerocnt++;
				if (sudoku(n + 1)) return true;
				board[i][j] = 0; already[k] = false; zerocnt--;
			}
		}
	}
	else return sudoku(n + 1);

	return false;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> board[i][j];
			if (board[i][j] == 0) zeros++;
		}
	}
	sudoku(0);

	return 0;
}

/*
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0

0 3 5 4 6 9 2 7 8
7 8 2 1 0 5 6 0 9
0 6 0 2 7 8 1 3 5
3 2 1 0 4 6 8 9 7
8 0 4 9 1 3 5 0 6
5 9 6 8 2 0 4 1 3
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0

0 2 0 9 0 5 0 0 0
5 9 0 0 3 0 2 0 0
7 0 0 6 0 2 0 0 5
0 0 9 3 5 0 4 6 0
0 5 4 0 0 0 7 8 0
0 8 3 0 2 7 5 0 0
8 0 0 2 0 9 0 0 4
0 0 5 0 4 0 0 2 6
0 0 0 5 0 3 0 7 0
*/
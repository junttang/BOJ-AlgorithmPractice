#include <iostream>
// BOJ - 2630 Making Colorpaper
using namespace std;

bool paper[129][129];
int blueCnt, whiteCnt;

void solve(int n, int w, int h) {
	int white = 0, blue = 0;

	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) {
			if (paper[w + i][h + j]) blue++;
			else white++;
		}

	if (blue == (n * n)) {
		blueCnt++; return;
	}
	if (white == (n * n)) {
		whiteCnt++; return;
	}

	solve(n / 2, w, h);
	solve(n / 2, w + n / 2, h);
	solve(n / 2, w, h + n / 2);
	solve(n / 2, w + n / 2, h + n / 2);
}

int main(void) {
	int n;
	
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> paper[i][j];
	solve(n, 1, 1);
	cout << whiteCnt << '\n' << blueCnt;

	return 0;
}
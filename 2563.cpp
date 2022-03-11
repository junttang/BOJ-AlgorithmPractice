#include <iostream>
// BOJ - 2563 Colorpaper
using namespace std;

bool paper[101][101];

int solve(void) {
	int cnt = 0;

	for (int i = 1; i <= 100; i++) 
		for (int j = 1; j <= 100; j++) 
			if (paper[i][j]) cnt++;

	return cnt;
}

int main(void) {
	int n, x, y;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		for (int j = 0; j < 10; j++) 
			for (int k = 0; k < 10; k++) 
				paper[x + j][y + k] = true;
	}
	cout << solve();

	return 0;
}
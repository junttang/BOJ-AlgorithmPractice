#include <iostream>
// BOJ - 1992 Quadtree
using namespace std;

bool video[65][65];

void solve(int n, int w, int h) {
	int zero = 0, one = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (video[w + i][h + j]) one++;
			else zero++;
		}
	
	if (one == (n * n)) { cout << 1; return; }
	if (zero == (n * n)) { cout << 0; return; }

	cout << '(';
	solve(n / 2, w, h);
	solve(n / 2, w, h + n / 2);
	solve(n / 2, w + n / 2, h);
	solve(n / 2, w + n / 2, h + n / 2);
	cout << ')';
}

int main(void) {
	int n; char temp;

	cin >> n;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++) 
			{ cin >> temp; video[i][j] = temp - 48; }
	solve(n, 1, 1);

	return 0;
}
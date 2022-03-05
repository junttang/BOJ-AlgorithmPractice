#include <iostream>
// BOJ - 1010 Laying Bridge
using namespace std;

int c[31][31];

void make_combination(void) {
	for (int i = 1; i <= 30; i++) { c[i][0] = 1; c[i][i] = 1; }
	for (int i = 1; i <= 30; i++) 
		for (int j = 1; j < i; j++) 
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
}

int main(void) {
	int t, n, m;

	make_combination();
	cin >> t;
	while (t--) {
		cin >> n >> m;
		cout << c[m][n] << '\n';
	}

	return 0;
}

/*

2 2 : 1
2 3 : 3
2 4 : 6
2 5 : 10

mCn = m-1Cn-1 + m-1Cn

*/
#include <iostream>
// BOJ - 1904 01Tile
#define MAX_LEN 1000000
#define DIVISOR 15746
using namespace std;		

int oo[MAX_LEN + 1];	// 00으로 시작하는 길이 N의 2진수	
int l[MAX_LEN + 1];		// 1로 시작하는 길이 N의 2진수

int solve(int n) {
	oo[0] = oo[1] = 0; oo[2] = 1;
	l[0] = 0; l[1] = 1; l[2] = 1;

	for (int i = 3; i <= n; i++) {
		oo[i] = (oo[i - 2] % DIVISOR + l[i - 2] % DIVISOR) % DIVISOR;
		l[i] = (oo[i - 1] % DIVISOR + l[i - 1] % DIVISOR) % DIVISOR;
	}

	return (oo[n] % DIVISOR + l[n] % DIVISOR) % DIVISOR;
}

int main(void) {
	int n;

	cin >> n;
	cout << solve(n);

	return 0;
}
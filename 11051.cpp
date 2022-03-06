#include <iostream>
// BOJ - 11051 Binomial Coefficient 2
using namespace std;
#define DIV  10007
int c[1001][1001];	// nCk = n-1Ck-1 + n-1Ck

void make_combination(int n, int k) { 
	for (int i = 1; i <= n; i++) { c[i][0] = 1; c[i][i] = 1; }
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++)
			c[i][j] = (c[i - 1][j - 1] % DIV + c[i - 1][j] % DIV) % DIV;
	}
	cout << c[n][k];
}

int main(void) {
	int n, k;

	cin >> n >> k;
	make_combination(n , k);

	return 0;
}
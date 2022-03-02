#include <iostream>
#include <algorithm>
// BOJ - 9251 LCS
using namespace std;

char a[1002], b[1002];
int LCS[1001][1001];

int solve(void) {
	int i, j;

	for (i = 1; a[i]; i++) {
		for (j = 1; b[j]; j++) 
			LCS[i][j] = max({ LCS[i][j - 1], LCS[i - 1][j], 
				LCS[i - 1][j - 1] + (a[i] == b[j]) });
	}

	return LCS[i - 1][j - 1];
}

int main(void) {
	cin >> a + 1 >> b + 1;
	cout << solve();

	return 0;
}
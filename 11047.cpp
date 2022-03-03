#include <iostream>
// BOJ - 11047 Coin 0
using namespace std;

int coin[11];

int solve(int n, int k) {
	int cnt = 0, temp;
	for (int i = n; i >= 0; i--) {
		if (k <= 0) break;
		if (k - coin[i] >= 0) {
			temp = coin[i];
			for (; k - temp >= 0;) { temp += coin[i]; cnt++; }
			if (temp > k) temp -= coin[i];
			k -= temp;
		}
	}

	return cnt;
}

int main(void) {
	int n, k;

	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> coin[i];
	cout << solve(n, k);

	return 0;
}
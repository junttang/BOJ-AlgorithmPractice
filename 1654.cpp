#include <iostream>
// BOJ - 1654 Cutting LAN Cable
using namespace std;

int len[10000], k, n;

int solve(int right) {
	int left = 1, mid, div, ans = right;

	while (left <= right) {
		mid = (left + right) / 2; div = 0;
		if (left == right) {
			for (int i = 0; i < k; i++) div += (len[i] / mid);
			if (div >= n) ans = mid;
			else ans = mid - 1;
			break;
		}

		for (int i = 0; i < k; i++) div += (len[i] / mid);
		if (div >= n) left = mid + 1;
		else right = mid;
	}

	return ans;
}

int main(void) {
	int temp, max_L = 0;
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		cin >> temp; len[i] = temp;
		if (temp > max_L) max_L = temp;
	}
	cout << solve(max_L);

	return 0;
}
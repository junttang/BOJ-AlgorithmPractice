#include <iostream>
#include <algorithm>
// BOJ - 1725 Histogram
#define MAX_SIZE 100000
using namespace std;

int h[MAX_SIZE + 1];

long long overlapLR(int left, int right, int mid) {
	int go_left = mid, go_right = mid, min_h = h[mid];
	long long max_area = h[mid];

	while (go_left > left || go_right < right) {
		if (go_right < right && (go_left == left || h[go_left - 1] < h[go_right + 1])) {
			go_right++;
			min_h = min(min_h, h[go_right]);
		}
		else {
			go_left--;
			min_h = min(min_h, h[go_left]);
		}
		max_area = max(max_area, (long long)min_h * (long long)(go_right - go_left + 1));
	}

	return max_area;
}

long long solve(int left, int right) {
	if (left > right) return 0LL;
	if (left == right) return (long long)h[left];
	long long max_L, max_R, max_M;
	int mid = (left + right) / 2;

	max_L = solve(left, mid);
	max_R = solve(mid + 1, right);
	max_M = overlapLR(left, right, mid);
	return max({ max_L, max_R, max_M });
}

int main(void) {
	int n;

	cin >> n; if (n == 0) break;
	for (int i = 1; i <= n; i++) cin >> h[i];
	cout << solve(1, n) << '\n';

	return 0;
}
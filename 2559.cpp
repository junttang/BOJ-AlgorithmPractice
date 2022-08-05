#include <iostream>
#include <limits.h>
// BOJ - 2559 Sequence
using namespace std;

int psum[100001];

int main(void) {
	int n, k, t, max = INT_MIN;

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> t;
		psum[i] = psum[i - 1] + t;
	}
	for (int i = k; i <= n; i++) {
		t = psum[i] - psum[i - k];
		if (t > max) max = t;
	}
	cout << max;

	return 0;
}

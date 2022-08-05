#include <iostream>
// BOJ - 11659 Summing each range 4
using namespace std;

int psum[100001];

int main(void) {
	int n, m, a, b, temp;
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> temp;
		psum[i] = psum[i - 1] + temp;
	}
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		cout << (psum[b] - psum[a - 1]) << '\n';
	}

	return 0;
}

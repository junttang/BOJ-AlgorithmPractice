#include <iostream>
// BOJ - 1476 Date Calculation
using namespace std;

int main(void) {
	int E, S, M;
	int e, s, m;

	cin >> E >> S >> M;

	for (int i = 1;; i++) {	// 브루트포스적 측면 : 일일이 전부 검사
		e = i % 15;
		if (e == 0) e = 15;

		s = i % 28;
		if (s == 0) s = 28;

		m = i % 19;
		if (m == 0) m = 19;

		if (e == E && s == S && m == M) {
			cout << i;
			break;
		}
	}

	return 0;
}
#include <iostream>
// BOJ - 1009 Distributive Processing
using namespace std;
// 항상 예외 처리를 잘하자.
int solve(int a, int b) { // 1 ~ a^b
	int temp = 1;
	for (int i = 0; i < b; i++) { temp *= a; temp %= 10; }
	if (temp == 0) temp = 10;
	return temp;
}

int main(void) {
	int t, a, b;

	cin >> t;
	while (t--) {
		cin >> a >> b;
		cout << solve(a, b) << '\n';
	}

	return 0;
}
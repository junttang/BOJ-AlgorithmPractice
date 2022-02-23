#include <iostream>
// BOJ - 1003 Fibonacci
using namespace std;

int fibozero[41];
int fiboone[41];

void fibonacci(int n) {
	fibozero[0] = 1; fiboone[0] = 0;
	fibozero[1] = 0; fiboone[1] = 1;
	fibozero[2] = 1; fiboone[2] = 1;
	for (int i = 3; i <= n; i++) {
		fibozero[i] = fibozero[i - 2] + fibozero[i - 1];
		fiboone[i] = fiboone[i - 2] + fiboone[i - 1];
	}
}

int main(void) {
	int t, n;

	cin >> t;
	while (t--) {
		cin >> n;
		fibonacci(n);
		cout << fibozero[n] << ' ' << fiboone[n] << '\n';
	}

	return 0;
}
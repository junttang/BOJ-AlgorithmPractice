#include <iostream>
// BOJ 24416 - Algorithm Class - Fibonacci Number 1
using namespace std;

int cnt_recursive, cnt_dynamic;

void fib_recursive(int n) {
	if (n == 1 || n == 2) {
		cnt_recursive++;
		return;
	}

	fib_recursive(n - 1); 
	fib_recursive(n - 2);
}

void fib_dynamic(int n) {
	for (int i = 3; i <= n; i++)
		cnt_dynamic++;
}

int main(void) {
	int n;
	cin >> n;

	fib_recursive(n); fib_dynamic(n);
	cout << cnt_recursive << ' ' << cnt_dynamic;

	return 0;
}

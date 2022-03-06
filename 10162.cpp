#include <iostream>
// BOJ - 10162 Microwave
using namespace std;

void solve(int time) { 
	int a, b, c;
	if (time % 10 != 0) { cout << -1; return; }

	a = time / 300;
	time %= 300;
	b = time / 60;
	time %= 60;
	c = time / 10;

	cout << a << ' ' << b << ' ' << c;
}

int main(void) {
	int t;

	cin >> t;
	solve(t);

	return 0;
}
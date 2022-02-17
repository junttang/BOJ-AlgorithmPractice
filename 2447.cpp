#include <iostream>
// BOJ - 2447 Star - 10
using namespace std;

void print(int i, int j, int n) {
	if ((i / n) % 3 == 1 && (j / n) % 3 == 1)
		cout << ' ';

	else {
		if (n / 3 == 0) cout << '*';
		else print(i, j, n / 3);
	}
}

int main(void) {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			print(i, j, n);
		cout << '\n';
	}
}
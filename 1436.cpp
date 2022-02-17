#include <iostream>
#include <stdio.h>
// BOJ - 1436 Movie Director Shwom(?)
using namespace std;

char num[100];

void solve(int n) {
	int cnt = 0;
	
	for (int i = 666;; i++) {
		bool find = false;

		sprintf(num, "%d", i);

		for (int j = 0; j < 100; j++) {
			if (num[j] == '6' && num[j + 1] == '6' && num[j + 2] == '6') {
				find = true;
				break;
			}
		}

		if (find) cnt++;

		if (cnt == n) {
			cout << i;
			break;
		}
	}
}

int main(void) {
	int n;

	cin >> n;
	solve(n);

	return 0;
}
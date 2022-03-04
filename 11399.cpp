#include <iostream>
#include <algorithm>
// BOJ - 11399 ATM
using namespace std;

int p[1000];

int solve(int n) {
	int sum = 0;
	sort(p, p + n);

	for (int i = 0; i < n; i++)
		for (int j = n - i - 1; j >= 0; j--) 
			sum += p[i];

	return sum;
}

int main(void) {
	int n;

	cin >> n;
	for (int i = 0; i < n; i++) cin >> p[i];
	cout << solve(n);

	return 0;
}
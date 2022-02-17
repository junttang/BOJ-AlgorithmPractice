#include <iostream>
// BOJ - 10989 Sorting 3
using namespace std;

int num[10001];

int main(void) {
	int n, k;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k;
		num[k]++;
	}

	for (int i = 1; i < 10001; i++) {
		if (num[i] > 0) 
			for (int j = 0; j < num[i]; j++) cout << i << '\n';
	}

	return 0;
}
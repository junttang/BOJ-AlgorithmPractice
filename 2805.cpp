#include <iostream>
// BOJ - 2805 Cutting trees
using namespace std;

int tree[1000001];
int max_height = 0;

void search_height(int n, int m, int a, int b) {
	long long sum = 0;
	int mid, ret;

	if (b >= a) {
		mid = (a + b) / 2;

		for (int i = 1; i <= n; i++) {
			if (tree[i] - mid > 0)
				sum += (tree[i] - mid);
		}

;		if (sum >= (long long)m) {
			if (mid >= max_height) 
				max_height = mid;
			search_height(n, m, mid + 1, b);
		}
		else search_height(n, m, a, mid - 1);
	}
}

int main(void) {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) 
		cin >> tree[i];

	search_height(n, m, 1, 2000000000);
	cout << max_height;

	return 0;
}

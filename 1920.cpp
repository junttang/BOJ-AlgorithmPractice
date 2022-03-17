#include <iostream>
#include <algorithm>
// BOJ - 1920 Number Search
#define MAX_SIZE	100000
using namespace std;

int a[MAX_SIZE + 1], target[MAX_SIZE + 1];

bool binary_search(int left, int right, int target) {
	if (left > right) return false;
	if (left == right) { if (a[left] == target) return true; else return false; }

	int mid = (left + right) / 2;
	if (a[mid] == target) return true;

	if (target < a[mid]) return binary_search(left, mid, target);
	else return binary_search(mid + 1, right, target);
}

int main(void) {
	int n, m;
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	cin >> m;
	for (int i = 1; i <= m; i++) cin >> target[i];

	sort(a + 1, a + n + 1);
	for (int i = 1; i <= m; i++) cout << binary_search(1, n, target[i]) << '\n';

	return 0;
}
#include <iostream>
#include <algorithm>
// BOJ - 1931 Assign Conference Room 
using namespace std;

typedef struct { int start, end; } Conf;
Conf arr[100000];

bool pred(Conf a, Conf b) { 
	if (a.end < b.end) return true;
	else if (a.end == b.end && a.start < b.start) return true;
	return false; 
}

int solve(int n) {
	int cnt = 0, j;
	sort(arr, arr + n, pred);

	for (int i = 0; i < n; ) {
		for (j = i + 1; j < n; j++) {
			if (arr[j].start >= arr[i].end) break;
		}
		i = j;
		cnt++;
	}

	return cnt;
}

int main(void) {
	int n;
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) { cin >> arr[i].start >> arr[i].end; }
	cout << solve(n);

	return 0;
}
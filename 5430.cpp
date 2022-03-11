#include <iostream>
#include <string.h>
// BOJ - 5430 AC
using namespace std;

char p[100001];
int lst[100000], lstSize;

void solve(void) {
	bool reverse = false; 
	int left_D = 0, right_D = 0, total, printCnt = 0;

	for (int i = 0; i < strlen(p); i++) {
		if (p[i] == 'D') {
			if (reverse) right_D++;
			else left_D++;
		}
		else {
			if (reverse) reverse = false;
			else reverse = true;
		}
	}

	total = lstSize - (left_D + right_D);
	if (total < 0) { cout << "error\n"; return; }

	cout << '[';
	if (reverse) {
		for (int i = lstSize - right_D - 1; i >= left_D; i--) {
			cout << lst[i]; printCnt++;
			if (printCnt != total) cout << ',';
		}
	}
	else {
		for (int i = left_D; i < lstSize - right_D; i++) {
			cout << lst[i]; printCnt++;
			if (printCnt != total) cout << ',';
		}
	}
	cout << "]\n";
}

int main(void) {
	int t, n; char temp;
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		lstSize = 0; cin >> p >> n; 

		for (int i = 0; i < n; i++) { cin >> temp >> lst[i]; lstSize++; }
		cin >> temp;
		if (n == 0) cin >> temp;
		
		solve();
	}

	return 0;
}
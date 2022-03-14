#include <iostream>
// BOJ - 6764 Sounds fishy!
using namespace std;

int fish[4];

void solve(void) {
	int a = fish[3] - fish[2], b = fish[2] - fish[1], c = fish[1] - fish[0];
	if (a > 0 && b > 0 && c > 0) cout << "Fish Rising";
	else if (a < 0 && b < 0 && c < 0) cout << "Fish Diving";
	else if (a == b && b == c && c == 0) cout << "Fish At Constant Depth";
	else cout << "No Fish";
}

int main(void) {
	for (int i = 0; i < 4; i++) cin >> fish[i];
	solve();
	return 0;
}
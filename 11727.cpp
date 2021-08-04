#include <iostream>
// BOJ - 11727 2xN Tile
#define MAX_TILE		1000

using namespace std;

int T[MAX_TILE + 1];

void makeTArray(int n) {
	T[1] = 1;
	T[2] = 3;
	for (int i = 3; i <= n; i++)
		T[i] = (T[i - 1] + T[i - 2] + T[i - 2]) % 10007;
}

int main(void) {
	int n;

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	makeTArray(n);
	cout << T[n];

	return 0;
}
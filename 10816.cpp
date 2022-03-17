#include <iostream>
// BOJ - 10816 Number Card 2
#define MAX_SIZE	500000
#define HASH_SIZE	10000000
using namespace std;

int target[MAX_SIZE + 1], cnt[2*HASH_SIZE + 1];

int main(void) {
	int n, m, temp;
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) { cin >> temp; cnt[temp + HASH_SIZE]++; }
	cin >> m;
	for (int i = 1; i <= m; i++) cin >> target[i];

	for (int i = 1; i <= m; i++) 
		cout << cnt[target[i] + HASH_SIZE] << '\n';

	return 0;
}
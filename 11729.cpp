#include <iostream>
// BOJ - 11729 Hanoi Tower Moving Order
using namespace std;

void hanoi(int n, int from, int through, int to) {
	if (n >= 1) {
		hanoi(n - 1, from, to, through);
		cout << from << " " << to << '\n';
		hanoi(n - 1, through, from, to);
	}
}

int main(void) {
	int n, cnt = 1;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	
	for (int i = 0; i < n; i++) cnt *= 2;
	cnt--; cout << cnt << '\n';
	hanoi(n, 1, 2, 3);

	return 0;
}
#include <iostream>
// BOJ - 17103 Goldbach Partition
#define MAX_NUM		1000000

using namespace std;

bool check[MAX_NUM + 1];
int prime[MAX_NUM];
int pn = 0;

void Euclid(void) {
	for (int i = 2; i <= MAX_NUM; i++) {
		if (check[i] == false) {
			prime[pn++] = i;
			for (int j = 2 * i; j <= MAX_NUM; j += i) {
				check[j] = true;
			}
		}
	}
}
// 10 = 5 + 5, 3+7
// 12 = 5 + 7,
int main(void) {
	int T, N, cnt;

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	Euclid();

	cin >> T;

	while (T--) {
		cin >> N;
		cnt = 0;

		for (int i = 0; prime[i] <= N / 2; i++) {
			if (check[N - prime[i]] == false)
				cnt++;
		}

		cout << cnt << '\n';
	}

	return 0;
}
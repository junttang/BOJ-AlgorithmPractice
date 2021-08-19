#include <iostream>
// BOJ - 6064 카잉 달력
using namespace std;

int main(void) {
	int T;
	int M, N, x, y, temp, nofoundflag = 0, i;

	cin >> T;
	while (T--) {
		cin >> M >> N >> x >> y;

		nofoundflag = 1;
		for (i = x; i <= M * N; i += M) { // 이 상한 찾는 것이 힘들었음.
			temp = i % N;			// M*N이 정확한 값은 아니지만,
			if (temp == 0) temp = N;	// 유효함은 확인이 가능하므로 사용하자!

			if (temp == y) {
				nofoundflag = 0;
				break;
			}
		}

		if (nofoundflag) cout << -1 << '\n';
		else cout << i << '\n';
	}

	return 0;
}
#include <iostream>
// BOJ - 9095 1,2,3 Adding
// D[N] : N을 1,2,3으로 만드는 경우의 수
#define MAX_NUM			11
using namespace std;

/*
결국, D[n]의 의미를 설정하고,
그것을 토대로 점화식을 세우는 것이 가장 중요하다.
*/

int D[MAX_NUM + 1];

void makeDArray(void) {
	D[1] = 1;
	D[2] = 2;
	D[3] = 4;
	for (int i = 4; i <= MAX_NUM; i++)
		D[i] = D[i - 1] + D[i - 2] + D[i - 3];
}

int main(void) {
	int T, n;

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	makeDArray();
	cin >> T;

	while (T--) {
		cin >> n;
		cout << D[n] << '\n';
	}

	return 0;
}
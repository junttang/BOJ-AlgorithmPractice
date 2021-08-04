#include <iostream>
// BOJ - 1463 Make 1
#define MAX_NUM		1000000

using namespace std;
// D[n] = n을 1로 만드는 최소 연산 횟수
// DP 문제의 핵심은 점화식 설정
int D[MAX_NUM + 1];

void makeDArray(int n) {
	D[1] = 0;
	for (int i = 2; i <= n; i++) {
		D[i] = D[i - 1] + 1;
		if (i % 2 == 0 && D[i] >= D[i/2] + 1)
			D[i] = D[i / 2] + 1;
		if (i % 3 == 0 && D[i] >= D[i / 3] + 1)
			D[i] = D[i / 3] + 1;
	}
}

int main(void) {
	int N;

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	makeDArray(N);
	cout << D[N];

	return 0;
}
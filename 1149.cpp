#include <iostream>
// BOJ - 1149 RGB Street
#define MAX_HOUSE		1000
using namespace std;
// 0은 R, 1은 G, 2는 B를 뜻한다.
int price[MAX_HOUSE + 1][4];
int D[MAX_HOUSE + 1][4];
// D[i][j] : i개 집을 칠하는 최소값. 마지막 집이 j색으로 칠해짐.
int makeDArray(int N) { // D[i][1] = min(D[i-1][2], D[i-1][3]) + pr[i][1]
	D[1][1] = price[1][1]; D[1][2] = price[1][2]; D[1][3] = price[1][3];

	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= 3; j++) {
			switch (j) {
			case 1: D[i][1] = (D[i - 1][2] <= D[i - 1][3] ? 
				D[i - 1][2] : D[i - 1][3]) + price[i][1]; break;
			case 2: D[i][2] = (D[i - 1][1] <= D[i - 1][3] ?
				D[i - 1][1] : D[i - 1][3]) + price[i][2]; break;
			case 3: D[i][3] = (D[i - 1][2] <= D[i - 1][1] ?
				D[i - 1][2] : D[i - 1][1]) + price[i][3]; break;
			}
		}
	}

	return (D[N][1] <= D[N][2] ? D[N][1] : D[N][2]) <= D[N][3] ?
		(D[N][1] <= D[N][2] ? D[N][1] : D[N][2]) : D[N][3];
}

int main(void) {
	int N;

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> price[i + 1][1] >> price[i + 1][2] >> price[i + 1][3];
	cout << makeDArray(N);

	return 0;
}
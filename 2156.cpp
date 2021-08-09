#include <iostream>
// BOJ - 2156 Drink Grape Wine
#define MAX_NUM		10000
using namespace std;

int A[MAX_NUM + 1];	// 포도주 양
long long D[MAX_NUM + 1][3]; // 0 안마심, 1 한잔, 2 두잔
// D[i][j] : i개 포도주 최대로 마신 양, 마지막은 j꼴로 마심
long long makeDArray(int n) {
	int higher;

	D[1][1] = A[1]; 
	D[2][0] = A[1]; // 이 예외처리를 하지 않아 틀렸다.
	D[2][1] = A[1];	// DP 점화식 설계 시 예외 처리를 정말 꼼꼼히 해야한다.
	D[2][2] = A[1] + A[2];

	for (int i = 3; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			switch (j) {
			case 0: higher = (D[i - 1][0] >= D[i - 1][1] ? D[i - 1][0] : D[i - 1][1]);
				D[i][j] = (higher >= D[i - 1][2] ? higher : D[i - 1][2]); break;
			case 1: D[i][j] = D[i - 1][0] + A[i]; break;
			case 2: D[i][j] = D[i - 2][0] + A[i] + A[i - 1]; break;
			}
		}
	}

	higher = (D[n][0] >= D[n][1] ? D[n][0] : D[n][1]);
	return higher >= D[n][2] ? higher : D[n][2];
}

int main(void) {
	int n;

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> A[i];
	cout << makeDArray(n);

	return 0;
}
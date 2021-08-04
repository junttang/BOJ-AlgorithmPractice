#include <iostream>
// BOJ - 11052 Buying Cards
#define MAX_CARDS		1000
using namespace std;

/*
조금 더 난도가 있는 점화식.
이처럼, 두 개 이상의 배열 간의 관계(예를 들어 최댓값)
를 이용한 점화식을 구성해야하는 경우도 있다.

이러한 경우는, 조금 더 주의깊게 점화관계를 파악하면 된다.
*/

int D[MAX_CARDS + 1];
int P[MAX_CARDS + 1];

void makeDArray(int N) {
	int temp;
	// D[i] = max(P[j] + D[i-j])
	for (int i = 1; i <= N; i++) {
		temp = 0;
		for (int j = 1; j < N, j <= i; j++) {
			if (D[i - j] + P[j] > temp)
				temp = D[i - j] + P[j];
		}
		D[i] = temp;
	}
}

int main(void) {
	int N;

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> P[i];
	makeDArray(N);
	cout << D[N];

	return 0;
}
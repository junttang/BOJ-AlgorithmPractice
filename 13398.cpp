#include <iostream>
// BOJ - 13398 연속합2
#define MAX_NUM		100000
using namespace std;

/*
너무나 어렵게 해결한 문제. 결국 핵심은, '수를 최대 하나 제거하는 것도 포함한
상황에서의 최대 연속합'을 구현하는 것인데,

1) 기본(생략x 상황) 연속합을 우선적으로 D배열과 max로 구해놓고,
2) DRight, 즉, 여기선 D[i][2]로 상징되는, A[i]를 포함하여, A[i]에서 시작하는
최대 연속합을 구현하는 것이 중요했다.
3) 왜냐하면, A[i] 생략 시의 최대 연속합을 의미하는 DExclusive는 결국
max(D[i-1][1],D[i-1][0]) : A[i] 앞에서의 최대 기본 연속합
DRight = D[i+1][2] : A[i+1]부터 시작하는 최대 기본 연속합
의 합이기 때문이다.

4)위의 1)~3)을 이해하는 것이 주요했다.

*/

int A[MAX_NUM + 1];	// D[i][j] : A[i]까지의 최대 연속합
int D[MAX_NUM + 1][3]; // 0은 '에서 시작', 1은 '앞과 연속', 2는 'i시작의 최대연속합'
int DExclusive[MAX_NUM + 1]; // 수 한 개 제외 시의 최대 연속합
// D[i][0] = A[i], D[i][1] = max(D[i-1][0],D[i-1][1]) + A[i] 
int makeDArray(int n) {
	int max, temp;
	D[1][0] = A[1]; D[1][1] = A[1];
	max = D[1][0];

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 2; j++) {
			switch (j) {
			case 0: D[i][j] = A[i]; break;
			case 1: D[i][j] = (D[i - 1][0] >= D[i - 1][1] ?
				D[i - 1][0] : D[i - 1][1]) + A[i]; break;
			}
		}
		temp = (D[i][1] >= D[i][0] ? D[i][1] : D[i][0]);
		if (temp >= max)
			max = temp;
	}

	D[n][2] = A[n];
	for (int i = n - 1; i >= 0; i--) {
		D[i][2] = A[i];
		if (D[i][2] < D[i + 1][2] + A[i])
			D[i][2] = D[i + 1][2] + A[i];
	}

	for (int i = 2; i < n; i++) {
		DExclusive[i] = D[i + 1][2] +
			(D[i - 1][1] >= D[i - 1][0] ? D[i - 1][1] : D[i - 1][0]);
		if (DExclusive[i] >= max)
			max = DExclusive[i];
	}

	return max;
}


int main(void) {
	int n;

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	if (n == 1) {
		cin >> A[1];
		cout << A[1];
		return 0;
	}

	for (int i = 1; i <= n; i++)
		cin >> A[i];
	cout << makeDArray(n);

	return 0;
}
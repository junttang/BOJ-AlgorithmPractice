#include <iostream>
// BOJ - 11054 L바이토닉S
#define MAX_NUM		1000
using namespace std;
// D[i] : A[i]를 마지막으로 하고, 가장 긴 IS
int A[MAX_NUM + 1];
int LIS[MAX_NUM + 1];	// 증가부분수열 -> LIS
int LDS[MAX_NUM + 1];	// 감소부분수열 -> LDS
// LIS+LDS가 가장 큰 조합이 가장 긴 바이토닉 수열
int makeLISLDSArray(int N) {
	int max = 0, ldsmax;

	for (int k = 1; k <= N; k++) {
		ldsmax = 0;
		for (int i = 1; i <= k; i++) {
			LIS[i] = 1;
			for (int j = 1; j < i; j++) {
				if (A[j] < A[i] && LIS[i] < LIS[j] + 1)
					LIS[i] = LIS[j] + 1;
			}
		}

		for (int i = k; i <= N; i++) {
			LDS[i] = 1;
			for (int j = k; j < i; j++) {
				if (A[k] >= A[j] && A[j] > A[i] && LDS[i] < LDS[j] + 1)
					LDS[i] = LDS[j] + 1;
			}
		}
		for (int i = k; i <= N; i++) {
			if (LDS[i]> ldsmax)
				ldsmax = LDS[i];
		}

		if (LIS[k] + ldsmax - 1 > max)
			max = LIS[k] + ldsmax - 1;
	}

	return max;
}

/*
바이토닉 수열은 k번째 수를 기점으로 그 앞 까지는 증가하고 있었고,
k부터는 감소하는 부분 수열을 의미한다.

첫 번째로 중요한 사고는 바로, LIS와 LDS를 합치면 바이토닉을 구할
수 있다는 아이디어를 떠올리는 것이고,

두 번째로 중요한 사고는, 첫 번째에서 통합할 때, LDS에는 다음의 조건
이 하나 더 있어야한다는 것이다.

그것은 무엇이냐면, 무조건 A[k]를 포함하는 부분 수열이어야한다는 점이다.

또 하나는, LDS에서, LDS[n]이 아니라 LDS 중에서 max인 친구를 찾아서 합
해야한다는 점이다.

이 두 가지가 지켜져야 비로소 바이토닉 수열, 가장 긴 수열을 찾을 수 있게
된다.

바이토닉 = LIS + LDS라는 점을 반드시 기억하도록 하자. ★★★★★
*/

int main(void) {
	int N;

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> A[i];
	cout << makeLISLDSArray(N);

	return 0;
}
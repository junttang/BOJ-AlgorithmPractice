#include <iostream>
// BOJ - 11053 LIS
#define MAX_LEN		1000
using namespace std;
// A[i] : 수열
int A[MAX_LEN + 1];
int D[MAX_LEN + 1];
// D[i] : 마지막 요소가 A[i]인 LIS의 길이

/*
DP에서 점화식의 일반항의 의미를 반드시 경우의수로만
바라볼 필요가 없음을 확인할 수 있는 문제

D[i] < D[j] + 1이라는 조건이 중요. 이거 없으면 혹여나
D의 배열이 1 2 3 2 와 같은 꼴일 때 오염될 수 있음.
*/

int makeDArray(int N) {
	int max = 1;
	D[1] = 1;

	for (int i = 2; i <= N; i++) {
		D[i] = 1;
		for (int j = 1; j < i; j++) {
			if (A[j] < A[i] && D[i] < D[j] + 1) {
				D[i] = D[j] + 1;
				if (D[i] > max) max = D[i];
			}
		}
	}

	return max;
}

int main(void) {
	int N;

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> A[i];
	cout << makeDArray(N);

	return 0;
}
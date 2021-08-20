#include <iostream>
// BOJ - 10973 Previous Permutation
#define MAX_NUM			10000
using namespace std;

int A[MAX_NUM + 1];

bool prev_permutation(int N) {
	int i, minIdx = N + 1, temp;

	A[minIdx] = -MAX_NUM;
	for (i = N; i > 1; i--) {
		if (A[i - 1] > A[i])
			break;
	}
	if (i == 1)
		return false;

	for (int j = N; j >= i; j--) {
		if (A[minIdx] < A[j] && A[j] < A[i - 1])
			minIdx = j;
	}
	temp = A[i - 1];
	A[i - 1] = A[minIdx];
	A[minIdx] = temp;

	for (int j = N; j > i; j--) {
		for (int k = i; k < j; k++) {
			if (A[k] < A[k + 1]) {
				temp = A[k];
				A[k] = A[k + 1];
				A[k + 1] = temp;
			}
		}
	}

	return true;
}

int main(void) {
	int N;

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> A[i];

	if (prev_permutation(N)) {
		for (int i = 1; i <= N; i++)
			cout << A[i] << ' ';
	}
	else
		cout << -1;

	return 0;
}

/*
다음 순열을 구하는 논리를 정확히, 부등호만 반대로 취해주면 
이전 순열을 구하는 논리가 된다.
*/
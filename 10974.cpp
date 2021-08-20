#include <iostream>
// BOJ - 10974 All Permutation
#define MAX_NUM			10000
using namespace std;

int A[MAX_NUM + 1];

bool next_permutation(int N) {
	int i, minIdx = N + 1, temp;

	A[minIdx] = MAX_NUM + 1;
	for (i = N; i > 1; i--) {
		if (A[i - 1] < A[i])
			break;
	}
	if (i == 1)
		return false;

	for (int j = N; j >= i; j--) {
		if (A[minIdx] > A[j] && A[j] > A[i - 1])
			minIdx = j;
	}
	temp = A[i - 1];
	A[i - 1] = A[minIdx];
	A[minIdx] = temp;

	for (int j = N; j > i; j--) {
		for (int k = i; k < j; k++) {
			if (A[k] > A[k + 1]) {
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
		A[i] = i;

	do {
		for (int i = 1; i <= N; i++)
			cout << A[i] << ' ';
		cout << '\n';
	} while (next_permutation(N));

	return 0;
}

/*
모든 순열을 출력하는 문제는 next_permutation 함수를
do~while문으로 묶어 연속 실행해주면 된다.
*/
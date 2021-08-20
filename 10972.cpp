#include <iostream>
// BOJ - 10972 Next Permutation
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
		cin >> A[i];

	if (next_permutation(N)) {
		for (int i = 1; i <= N; i++)
			cout << A[i] << ' ';
	}
	else
		cout << -1;

	return 0;
}

/*
특정 순열의 다음 순열을 구하는 알고리즘을 잘 기억해두자

순열을 사전순으로 나열할 시,
특정 자리수에서 마지막 순서의 순열은 내림차순의 순열이다.

그말은 즉슨, 순열의 우측끝에서 좌로 순회조회 시 처음으로 > 관계가
깨지면, 그 순간이 가장 긴 마지막 부분 순열인 것이다.

이때, 그 깨진 지점(깨지게 만든 요소)과, 그 앞의 부분 순열에서
깨진 지점보다는 크면서 그 중 가장 작은 요소를 찾고, 그 요소와 깨진
요소를 swap한다.

그러고선, 부분 순열의 크기만큼에서 오름차순으로 정렬한다.

이것이 바로, 특정 순열의 다음 순열을 찾는 알고리즘이다. 잘 기억해두자.

*/
#include <iostream>
#include <algorithm>
// BOJ - 10819 Maximize the difference
#define MAX_NUM			100

using namespace std;

int A[MAX_NUM];

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
	int N, max = 0, sum;

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> A[i];
	sort(A + 1, A + N);

	do {
		sum = 0;
		for (int i = 1; i < N; i++)
			sum += abs(A[i] - A[i + 1]);
		if (sum > max)
			max = sum;
	} while (next_permutation(N));

	cout << max;

	return 0;
}
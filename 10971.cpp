#include <iostream>
#include <algorithm>
// BOJ - 10971 Traveling Salesman Problem 2
#define MAX_NUM				100000000
#define MAX_CITIES			10

using namespace std;

int D[MAX_CITIES + 1];
int W[MAX_CITIES + 1][MAX_CITIES + 1];

bool next_permutation(int N) {
	int i, minIdx = N + 1, temp;

	D[minIdx] = MAX_NUM + 1;
	for (i = N; i > 1; i--) {
		if (D[i - 1] < D[i])
			break;
	}
	if (i == 1)
		return false;

	for (int j = N; j >= i; j--) {
		if (D[minIdx] > D[j] && D[j] > D[i - 1])
			minIdx = j;
	}
	temp = D[i - 1];
	D[i - 1] = D[minIdx];
	D[minIdx] = temp;

	for (int j = N; j > i; j--) {
		for (int k = i; k < j; k++) {
			if (D[k] > D[k + 1]) {
				temp = D[k];
				D[k] = D[k + 1];
				D[k + 1] = temp;
			}
		}
	}

	return true;
}

int main(void) {
	int N, sum, min = MAX_NUM, ignoreflag;

	cin >> N;
	for (int i = 1; i <= N; i++)
		D[i] = i;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			cin >> W[i][j];
	}

	do {
		sum = 0; ignoreflag = 0;

		for (int i = 1; i < N; i++) {
			if (W[D[i]][D[i + 1]] == 0) {
				ignoreflag = 1;
				break;
			}
			sum += W[D[i]][D[i + 1]];
		}
		if (W[D[N]][D[1]] == 0 || ignoreflag)
			continue;
		sum += W[D[N]][D[1]];
		
		if (sum < min)
			min = sum;
	} while (next_permutation(N));
	
	cout << min;

	return 0;
}
#include <iostream>
// BOJ - 14002 LIS 4
#define MAX_LEN		1000
using namespace std;
// A[i] : 수열
int A[MAX_LEN + 1];
int D[MAX_LEN + 1];
int V[MAX_LEN + 1];	// 백트래킹을 위한 인덱스 기록 배열
int LISIdx = 1;		// 백트래킹의 끝점
// D[i] : 마지막 요소가 A[i]인 LIS의 길이

/*
훑어간 부분수열의 요소들을 기억하는, 즉, 백트래킹이 필요한
문제이다.

백트래킹에는 많은 방법이 존재하며, 일반적으로는 위와 같이
인덱스를 기록할 배열을 도입하여 방법을 강구하곤 한다.
*/

int makeDArray(int N) {
	int max = 1;
	D[1] = 1;

	for (int i = 2; i <= N; i++) {
		D[i] = 1;
		V[i] = i;
		for (int j = 1; j < i; j++) {
			if (A[j] < A[i] && D[i] < D[j] + 1) {
				D[i] = D[j] + 1;
				V[i] = j;
				if (D[i] > max) { max = D[i]; LISIdx = i; }
			}
		}
	}

	return max;
}

void printVArray(int len) {
	int * printIdx;
	printIdx = new int[len];

	for (int i = 0; i < len; i++) {
		printIdx[len - 1 - i] = LISIdx;
		LISIdx = V[LISIdx];
	}

	for (int i = 0; i < len; i++)
		cout << A[printIdx[i]] << ' ';

	delete[] printIdx;
}

int main(void) {
	int N, len;

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> A[i];
	cout << (len = makeDArray(N)) << '\n';
	printVArray(len);

	return 0;
}
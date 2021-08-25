#include <iostream>
// BOJ - 1182 부분수열의 합
#define MAX_NUM			20
using namespace std;

int A[MAX_NUM];

int findAnswer(int N, int S) {
	int sum, cnt = 0;

	for (int i = 1; i < (1 << N); i++) {
		sum = 0;
		for (int j = 0; j < N; j++) {
			if (i & (1 << j))
				sum += A[j];
		}
		if (sum == S)
			cnt++;
	}

	return cnt;
}

/*
위의 함수에서, i가 1부터 1<<N까지 순회하는 것이 핵심이다.
이것이 곧 집합의 경우의 수를 모두 훑는 과정이다.

집합이
인덱스 : 0 1 2 3 4 5 ..
비트   : 0 0 0 0 0 0 ..
비트에 대응시켜 보았을 때, 저 순회가 곧 비트, 인덱스, 즉, 선택
조합을 훑는 과정이다.

그리고 매 조회 순간에, 비트가 1인 지점을 서칭하여 해당 지점의 값들을
합치면, 그것이 곧 부분 수열의 합을 확인하는 과정인 것이다.
*/

int main(void) {
	int N, S;

	cin >> N >> S;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	cout << findAnswer(N, S);

	return 0;
}
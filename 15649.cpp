#include <iostream>
// BOJ - 15649 N and M (1)
#define MAX_SIZE		10
using namespace std;

bool check[MAX_SIZE];
int A[MAX_SIZE];

/*
브루트포스 문제는 기본적으로 "모든 경우의 수를 다 시도해보는 것"이라 했다.

그러한 방법론에는, for반복이 있을 것이고,

그 외로는, 재귀, 순열, 비트 마스크 등이 있다고 했다.

그 중 재귀를 이용한 브루트포스는 일반적으로 무언가의 순서나 선택법을 묻는 문제에서 사용할 수 있다.

이 문제가 바로 그것을 연습한 문제이다.
*/

void makeAArray(int index, int n, int m) {
	if (index == m) {
		for (int i = 0; i < m; i++) {
			cout << A[i];

			if (i != m - 1) 
				cout << ' ';
		}
		cout << '\n';
		
		return;
	}

	for (int i = 1; i <= n; i++) {		// i는 _자리에 들어갈 수의 후보를 의미
		if (check[i]) 			// index는 수열의 _자리를 의미
			continue;
		
		check[i] = true;		// i를 제외하고 나머지 1~N을 기준으로 수열 
		A[index] = i;
		makeAArray(index + 1, n, m);
		check[i] = false;		// 다음 경우를 확인하기 위해 다시 정상화
	}
}

int main(void) {
	int N, M;

	cin >> N >> M;
	makeAArray(0, N, M);

	return 0;
}

#include <iostream>
// BOJ - 1248 맞춰봐
#define MAX_NUM		10
using namespace std;

char S[MAX_NUM][MAX_NUM];
int A[MAX_NUM];
int flag = 0;		// 한 가지만 출력 후 재귀 전체 종료를 위한 플래그

/*
ㅁ 0 1 2 3			// 문제 상황 이해
0  - + 0 +
1    + + +
2      - -
3        +
*/

bool good(int N, int index) {
	int sum;

	for (int start = 0; start <= index; start++) {
		sum = 0;
		for (int i = start; i <= index; i++)
			sum += A[i];
		if (S[start][index] == '+' && sum <= 0) return false;
		if (S[start][index] == '-' && sum >= 0) return false;
		if (S[start][index] == '0' && sum != 0) return false;
	}
	
	return true;
}
/*
재귀를 백트래킹하여 시간 복잡도를 현저히 줄이기 위한 good 함수
재귀함수에서 index를 보고 있을때, 해당 상황에 대하여, A[index]가 i일 때
0부터 index까지, 1부터 index까지, 2부터.... 쭉 해서 S[][]를 만족하는 값인지
즉, A[index]의 후보값이 S[][]를 위배하지 않는지 확인해주는 함수이다.

good은 순회를 돌긴 하지만, 이 친구가 불필요한 재귀호출을 줄인다.
*/

void go(int N, int index) {		// 재귀함수
	if (flag) return;
	if (index == N) {
		for (int i = 0; i < N; i++)
			cout << A[i] << ' ';
		flag = 1;
		return;
	}

	if (S[index][index] == '0') {	// 이 부분 실수 주의!!!
		A[index] = 0;
		if (good(N, index))		// A[index] 값이 적절하다면,
			go(N, index + 1);	// 재귀 호출!
	}

	else if (S[index][index] == '+') {
		for (int i = 1; i <= 10; i++) {
			A[index] = i;
			if (good(N, index))
				go(N, index + 1);
		}
	}

	else {
		for (int i = 1; i <= 10; i++) {
			A[index] = -i;
			if (good(N, index))
				go(N, index + 1);
		}
	}
}

int main(void) {
	int N;

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++)
			cin >> S[i][j];
	}
	go(N, 0);

	return 0;
}
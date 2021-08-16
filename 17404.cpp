#include <iostream>
// BOJ - 17404 RGB거리 2
#define MAX_HOUSE		1000
#define INFINITE		10000000000
using namespace std;

int A[MAX_HOUSE + 1][3]; // 0빨, 1초, 2파
int D[MAX_HOUSE + 1][3];
// D[i][j] : i번째 집 색이 j일 때, 모든 집 칠 최소비용

/*
A[1]~A[N]이 RGB거리 규칙을 만족하되, A[1]과 A[N]도 마찬가지로
서로 달라야한다는, 원형적인 조건이 붙은 문제였다.

해결하는데 꽤나 오랜 시간이 소요되었는데,

해결 방법은 다음과 같았다.

일단 RGB거리1 문제와 풀이는 거의 동일하다. 점화식만 설계하면 된다.

핵심은, A[1]이 R, G, B일 때를 고정해 총 세 번 DP를 해주어야한다는 점인데,
A[1]이 고정되므로, 각 케이스에서 우리가 초기화해주어야하는 것은 D[2][i]부터
이다. 그리고, 점화식 반복문은 i=3부터 시작하는 것이다.

이렇게 해서 N까지 점화식이 구동되면, 예를 들어 케이스(시작 색)가 0이면
D[N][1], D[N][2] 중 최솟값을 채택하면 되는 것이다.

*/

int makeDArray(int N) {
	int MIN = INFINITE, min, temp1, temp2;

	for (int k = 0; k < 3; k++) {
		D[1][0] = A[1][0]; D[1][1] = A[1][1]; D[1][2] = A[1][2];

		if (k == 0) { 
			temp1 = 1; temp2 = 2; D[2][0] = INFINITE;
			D[2][1] = D[1][0] + A[2][1];
			D[2][2] = D[1][0] + A[2][2];
		}
		else if (k == 1) { 
			temp1 = 2; temp2 = 0; D[2][1] = INFINITE;
			D[2][0] = D[1][1] + A[2][0];
			D[2][2] = D[1][1] + A[2][2];
		}
		else if (k == 2) { 
			temp1 = 1; temp2 = 0; D[2][2] = INFINITE;
			D[2][1] = D[1][2] + A[2][1];
			D[2][0] = D[1][2] + A[2][0];
		}
		
		for (int i = 3; i <= N; i++) {
			for (int j = 0; j < 3; j++) {
				switch (j) {
				case 0: D[i][j] = (D[i - 1][1] <= D[i - 1][2] ?
					D[i - 1][1] : D[i - 1][2]) + A[i][j]; break;
				case 1: D[i][j] = (D[i - 1][2] <= D[i - 1][0] ?
					D[i - 1][2] : D[i - 1][0]) + A[i][j]; break;
				case 2: D[i][j] = (D[i - 1][1] <= D[i - 1][0] ?
					D[i - 1][1] : D[i - 1][0]) + A[i][j]; break;
				}
			}
		}

		min = (D[N][temp1] <= D[N][temp2] ? D[N][temp1] : D[N][temp2]);
		if (min < MIN)
			MIN = min;
	}
	
	return MIN;
}

int main(void) {
	int N;

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> A[i][0] >> A[i][1] >> A[i][2];
	cout << makeDArray(N);

	return 0;
}
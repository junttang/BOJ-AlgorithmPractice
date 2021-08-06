#include <iostream>
// BOJ - 10844 Easy Stair Number
#define MAX_LEN		100
#define DIVISOR		1000000000

/*
2차원 점화식을 사용하는 예제

주의해야할 점 : 출력 시 DIVISOR로 나눈 나머지를 출력하라고
했는데, 이때, 나는 k에 반복문으로 합치는 방식을 채택했다.
우리는 정확한 값을 알 수는 없지만, k가 DIVISOR와 같은 경우도
있을 수 있음을 염두해야한다.

즉, 만약 k가 1000000000이면, 결과가 0이 나와야한다. 하지만
태초의 내 제출 코드는 k에 mod를 해주지 않았다. 즉, 0이 출력되지
않는 다는 말이다. ~> 이를 대비해야한다.
*/

using namespace std;
// D[i][j] : 길이가 i이고, 마지막 수가 j인 계단수 경우의 수
long long D[MAX_LEN + 1][10];	
// D[i][j] = D[i-1][j-1] + D[i-1][j+1]
void calcStairNum(int n) {
	for (int i = 1; i < 10; i++)
		D[1][i] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 9)
				D[i][j] = D[i - 1][j - 1] % DIVISOR;
			else if (j == 0)
				D[i][j] = D[i - 1][j + 1] % DIVISOR;
			else
				D[i][j] = (D[i - 1][j - 1] + D[i - 1][j + 1]) % DIVISOR;
		}
	}
}

int main(void) {
	int N;
	long long k = 0;

	cin >> N;
	calcStairNum(N);
	for (int i = 0; i < 10; i++)
		k += D[N][i] % DIVISOR;
	cout << k % DIVISOR;

	return 0;
}
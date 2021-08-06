#include <iostream>
// BOJ - 15990 Adding 1,2,3 - 5
#define MAX_NUM		100000
#define DIVISOR		1000000009
using namespace std;
/*
연속 미허용 조건이 붙은 DP 문제는 아래와 같이
n차원 배열 개념을 도입하여 해결할 수 있다.

D[i]의 방법의 수에서 마지막에 더해진 수를 2차원 필드로
구분해주는 것이다.
즉, 점화식을 분기한다.

한편, 2번 제출에서 오답이유는, 바로 나머지 연산에 대한
몰이해때문이었는데, 나머지 연산은 DIVISOR 이하의 수로
늘 표기하기 위함이기 때문에 여러번 해줘도 문제가 없다는
것을 생각하지 못한 것이 문제였다.
(별표 부분)

*/

// [][i]는 마지막 수가 i인 상태
long long D[MAX_NUM + 1][4];	
// D[i][1] = D[i-1][2] + D[i-1][3];
void makeDArray(int n) {
	D[1][1] = 1; D[2][2] = 1;
	D[3][3] = 1; D[3][2] = 1; D[3][1] = 1;
	for (int i = 4; i <= n; i++) {
		for (int j = 1; j <= 3; j++) {
			if (j == 1)
				D[i][j] = (D[i - j][2] + D[i - j][3]) % DIVISOR;
			else if (j == 2)
				D[i][j] = (D[i - j][1] + D[i - j][3]) % DIVISOR;
			else if (j == 3)
				D[i][j] = (D[i - j][1] + D[i - j][2]) % DIVISOR;
		}
	}
}

int main(void) {
	int T, n;
	long long k;

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	makeDArray(MAX_NUM);

	while (T--) {
		cin >> n;

		k = (D[n][1] + D[n][2] + D[n][3]) % DIVISOR; //(★)
		if (k == 0) k = 1;
		cout << k << '\n';
	}

	return 0;
}
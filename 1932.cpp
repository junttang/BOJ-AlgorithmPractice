#include <iostream>
// BOJ - 1932 Integer Triangle
#define MAX_COLROW	500
using namespace std;
// T : sparse representation
int T[MAX_COLROW + 1][MAX_COLROW + 1];
int D[MAX_COLROW + 1][MAX_COLROW + 1];
// D[i][j] : 위치 (i,j)에서 max인 합
/*
이 문제는 마름모를 2차원 행렬로 바라보는 것이 중요한 문제
*/
int makeDArray(int n) { // D[i][j] = max(D[i-1][j-1],D[i-1][j])
	int max = 0;
	D[1][1] = T[1][1];

 	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == i)
				D[i][j] = D[i - 1][j - 1] + T[i][j];
			else if (j == 1)
				D[i][j] = D[i - 1][j] + T[i][j];
			else {
				D[i][j] = (D[i - 1][j - 1] >= D[i - 1][j] ?
					D[i - 1][j - 1] : D[i - 1][j]) + T[i][j];
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (D[n][i] >= max)
			max = D[n][i];
	}
	return max;
}


int main(void) {
	int n;

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++)
			cin >> T[i][j];
	}
	cout << makeDArray(n);

	return 0;
}

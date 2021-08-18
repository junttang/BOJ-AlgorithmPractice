#include <iostream>
// BOJ - 3085 Candy Game
#define MAX_NUM		50
using namespace std;

char candy[MAX_NUM + 1][MAX_NUM + 1];

int calc(int N) {
	int cnt, max = 1;

	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N - 1; i++) {
			cnt = 1;
			for (int j = i; j < N - 1; j++) {
				if (candy[k][j] == candy[k][j + 1])
					cnt++;
				else break;
			}
			if (cnt > max)
				max = cnt;
		}
	}

	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N - 1; i++) {
			cnt = 1;
			for (int j = i; j < N - 1; j++) {
				if (candy[j][k] == candy[j + 1][k])
					cnt++;
				else break;
			}
			if (cnt > max)
				max = cnt;
		}
	}

	return max;
}

int main(void) {
	int N, tmp, MAX = 1;
	char temp;

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cin >> candy[i][j];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (candy[i][j] != candy[i][j + 1]) {
				temp = candy[i][j];
				candy[i][j] = candy[i][j + 1];
				candy[i][j + 1] = temp;

				tmp = calc(N);
				if (tmp > MAX)
					MAX = tmp;

				temp = candy[i][j];
				candy[i][j] = candy[i][j + 1];
				candy[i][j + 1] = temp;
			}
			if (candy[i][j] != candy[i + 1][j]) {
				temp = candy[i][j];
				candy[i][j] = candy[i + 1][j];
				candy[i + 1][j] = temp;

				tmp = calc(N);
				if (tmp > MAX)
					MAX = tmp;

				temp = candy[i][j];
				candy[i][j] = candy[i + 1][j];
				candy[i + 1][j] = temp;
			}
		}
	}
	cout << MAX;

	return 0;
}
#include <iostream>
#include <string>
// BOJ - 14391 Paper Piece
#define MAX_ROWCOL		4
using namespace std;

int paper[MAX_ROWCOL][MAX_ROWCOL];
int direction_matrix = 0; // Direction, 0:|, 1:ㅡ
int dm[MAX_ROWCOL][MAX_ROWCOL];
int MAX = 0;
// 00..0 ~ 11..1
int findAnswer(int N, int M) {
	int starti, startj, endj, sum, number;

	for (; direction_matrix < (1 << N * M); direction_matrix++) {
		sum = 0;

		for (int k = 0; k < N*M; k++) {
			if (direction_matrix & (1 << k))
				dm[k / M][k%M] = 1;
			else
				dm[k / M][k%M] = 0;
		}
		
		for (int i = 0; i < N; i++) {
			number = 0; starti = i; startj = -1; endj = M;

			for (int j = 0; j < M; j++) {
				if (dm[i][j]) {
					startj = j;
					break;
				}
			}
			for (int j = startj; j < M; j++) {
				if (!dm[i][j]) {
					endj = j;
					break;
				}
			}
			if (startj != -1) {
				for (int j = endj - 1, ten = 1; j >= startj; j--) {
					number += paper[i][j] * ten;
					ten *= 10;
				}
			}
			sum += number;
		}

		for (int i = 0; i < M; i++) {
			number = 0; starti = i; startj = -1; endj = N;

			for (int j = 0; j < N; j++) {
				if (!dm[j][i]) {
					startj = j;
					break;
				}
			}
			for (int j = startj; j < N; j++) {
				if (dm[j][i]) {
					endj = j;
					break;
				}
			}
			if (startj != -1) {
				for (int j = endj - 1, ten = 1; j >= startj; j--) {
					number += paper[j][i] * ten;
					ten *= 10;
				}
			}
			sum += number;
		}

		if (sum > MAX)
			MAX = sum;
	}

	return MAX;
}

int main(void) {
	int N, M;
	string line;

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> line;
		for (int j = 0; j < M; j++)
			paper[i][j] = line[j] - 48;
	}
	cout << findAnswer(N, M);

	return 0;
}

/*
브루트포스에서 사용하는 기법 중 0과 1로 이루어진 조합관계를
순차적으로 순회해야하는 논리구조를 갖춘 문제에 대해서
특수적으로

비트마스킹을 할 수 있다. 이 문제 역시 바로 그러한 유형의
대표 문제이고,

i = 0부터 1<<N까지 순회시켜 비트 조합을 모두 훑고, 해당 조회
과정에서
k = 0부터 N까지 1<<K와 i의 AND연산과정을 통해 조합의 각 요소
들에 대해서 체킹할 수 있다.

이 논리를 잘 기억해주도록 하자.
*/
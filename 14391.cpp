#include <iostream>
#include <string>
// BOJ - 14391 Paper Piece
#define MAX_ROWCOL		4
using namespace std;

int paper[MAX_ROWCOL][MAX_ROWCOL];
int direction_matrix = 0; // Direction, 0:|, 1:��
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
���Ʈ�������� ����ϴ� ��� �� 0�� 1�� �̷���� ���հ��踦
���������� ��ȸ�ؾ��ϴ� �������� ���� ������ ���ؼ�
Ư��������

��Ʈ����ŷ�� �� �� �ִ�. �� ���� ���� �ٷ� �׷��� ������
��ǥ �����̰�,

i = 0���� 1<<N���� ��ȸ���� ��Ʈ ������ ��� �Ȱ�, �ش� ��ȸ
��������
k = 0���� N���� 1<<K�� i�� AND��������� ���� ������ �� ���
�鿡 ���ؼ� üŷ�� �� �ִ�.

�� ���� �� ������ֵ��� ����.
*/
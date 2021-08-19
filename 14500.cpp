#include <iostream>
// BOJ - 14500 Tetromino
#define MAX_SIZE		500
using namespace std;

int paper[MAX_SIZE + 4][MAX_SIZE + 4];

int main(void) {
	int N, M, max = 0, sum;

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cin >> paper[i][j];
	}

	for (int i = 0; i < N; i++) {		
		for (int j = 0; j < M; j++) {
			sum = paper[i][j] + paper[i][j + 1] +
				paper[i][j + 2] + paper[i][j + 3];
			if (sum > max)	// ��������
				max = sum;

			sum = paper[i][j] + paper[i + 1][j] +
				paper[i + 2][j] + paper[i + 3][j];
			if (sum > max)	// �������� (����)
				max = sum;

			sum = paper[i][j] + paper[i][j + 1] +
				paper[i + 1][j] + paper[i + 1][j + 1];
			if (sum > max)	// ����
				max = sum;	// ����

			sum = paper[i][j] + paper[i][j + 1] +
				paper[i][j + 2] + paper[i + 1][j + 1];
			if (sum > max)	// ������
				max = sum;	//   ��

			sum = paper[i][j] + paper[i + 1][j] +
				paper[i + 2][j] + paper[i + 1][j + 1];
			if (sum > max)	// ��
				max = sum;	// ����
							// ��
			sum = paper[i][j + 1] + paper[i + 1][j + 1] +
				paper[i + 1][j] + paper[i + 2][j + 1];
			if (sum > max)	//   ��
				max = sum;	// ����
							//   ��
			sum = paper[i + 1][j] + paper[i + 1][j + 1] +
				paper[i + 1][j + 2] + paper[i][j + 1];
			if (sum > max)	//   ��
				max = sum;	// ������

			sum = paper[i][j] + paper[i][j + 1] +
				paper[i + 1][j + 1] + paper[i + 1][j + 2];
			if (sum > max)	// ����
				max = sum;	//   ����

			sum = paper[i][j + 1] + paper[i + 1][j + 1] +
				paper[i + 1][j] + paper[i + 2][j];
			if (sum > max)	//	 ��
				max = sum;	// ����
							// ��
			sum = paper[i][j + 1] + paper[i][j + 2] +
				paper[i + 1][j + 1] + paper[i + 1][j];
			if (sum > max)	//   ����
				max = sum;	// ����

			sum = paper[i][j] + paper[i + 1][j] +
				paper[i + 1][j + 1] + paper[i + 2][j + 1];
			if (sum > max)	// ��
				max = sum;	// ����
							//   ��

			sum = paper[i][j] + paper[i + 1][j] +
				paper[i + 2][j] + paper[i + 2][j + 1];
			if (sum > max)	// ��
				max = sum;	// ��
							// ����
			sum = paper[i][j] + paper[i][j + 1] +
				paper[i][j + 2] + paper[i + 1][j];
			if (sum > max)	// ������
				max = sum;	// ��

			sum = paper[i][j] + paper[i][j + 1] +
				paper[i + 1][j + 1] + paper[i + 2][j + 1];
			if (sum > max)	// ����
				max = sum;	//   ��
							//   ��
			sum = paper[i + 1][j] + paper[i + 1][j + 1] +
				paper[i + 1][j + 2] + paper[i][j + 2];
			if (sum > max)	//     ��
				max = sum;	// ������

			sum = paper[i][j + 1] + paper[i + 1][j + 1] +
				paper[i + 2][j + 1] + paper[i + 2][j];
			if (sum > max)	//   ��
				max = sum;	//   ��
							// ����
			sum = paper[i][j] + paper[i + 1][j] +
				paper[i + 1][j + 1] + paper[i + 1][j + 2];
			if (sum > max)	// ��
				max = sum;	// ������

			sum = paper[i][j] + paper[i][j + 1] +
				paper[i + 1][j] + paper[i + 2][j];
			if (sum > max)	// ����
				max = sum;	// ��
							// ��
			sum = paper[i][j] + paper[i][j + 1] +
				paper[i][j + 2] + paper[i + 1][j + 2];
			if (sum > max)	// ������
				max = sum;	//     ��
		}
	}
	cout << max;

	return 0;
}
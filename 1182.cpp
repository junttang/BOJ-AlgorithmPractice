#include <iostream>
// BOJ - 1182 �κм����� ��
#define MAX_NUM			20
using namespace std;

int A[MAX_NUM];

int findAnswer(int N, int S) {
	int sum, cnt = 0;

	for (int i = 1; i < (1 << N); i++) {
		sum = 0;
		for (int j = 0; j < N; j++) {
			if (i & (1 << j))
				sum += A[j];
		}
		if (sum == S)
			cnt++;
	}

	return cnt;
}

/*
���� �Լ�����, i�� 1���� 1<<N���� ��ȸ�ϴ� ���� �ٽ��̴�.
�̰��� �� ������ ����� ���� ��� �ȴ� �����̴�.

������
�ε��� : 0 1 2 3 4 5 ..
��Ʈ   : 0 0 0 0 0 0 ..
��Ʈ�� �������� ������ ��, �� ��ȸ�� �� ��Ʈ, �ε���, ��, ����
������ �ȴ� �����̴�.

�׸��� �� ��ȸ ������, ��Ʈ�� 1�� ������ ��Ī�Ͽ� �ش� ������ ������
��ġ��, �װ��� �� �κ� ������ ���� Ȯ���ϴ� ������ ���̴�.
*/

int main(void) {
	int N, S;

	cin >> N >> S;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	cout << findAnswer(N, S);

	return 0;
}
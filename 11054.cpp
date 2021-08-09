#include <iostream>
// BOJ - 11054 L�������S
#define MAX_NUM		1000
using namespace std;
// D[i] : A[i]�� ���������� �ϰ�, ���� �� IS
int A[MAX_NUM + 1];
int LIS[MAX_NUM + 1];	// �����κм��� -> LIS
int LDS[MAX_NUM + 1];	// ���Һκм��� -> LDS
// LIS+LDS�� ���� ū ������ ���� �� ������� ����
int makeLISLDSArray(int N) {
	int max = 0, ldsmax;

	for (int k = 1; k <= N; k++) {
		ldsmax = 0;
		for (int i = 1; i <= k; i++) {
			LIS[i] = 1;
			for (int j = 1; j < i; j++) {
				if (A[j] < A[i] && LIS[i] < LIS[j] + 1)
					LIS[i] = LIS[j] + 1;
			}
		}

		for (int i = k; i <= N; i++) {
			LDS[i] = 1;
			for (int j = k; j < i; j++) {
				if (A[k] >= A[j] && A[j] > A[i] && LDS[i] < LDS[j] + 1)
					LDS[i] = LDS[j] + 1;
			}
		}
		for (int i = k; i <= N; i++) {
			if (LDS[i]> ldsmax)
				ldsmax = LDS[i];
		}

		if (LIS[k] + ldsmax - 1 > max)
			max = LIS[k] + ldsmax - 1;
	}

	return max;
}

/*
������� ������ k��° ���� �������� �� �� ������ �����ϰ� �־���,
k���ʹ� �����ϴ� �κ� ������ �ǹ��Ѵ�.

ù ��°�� �߿��� ���� �ٷ�, LIS�� LDS�� ��ġ�� ��������� ����
�� �ִٴ� ���̵� ���ø��� ���̰�,

�� ��°�� �߿��� ����, ù ��°���� ������ ��, LDS���� ������ ����
�� �ϳ� �� �־���Ѵٴ� ���̴�.

�װ��� �����̳ĸ�, ������ A[k]�� �����ϴ� �κ� �����̾���Ѵٴ� ���̴�.

�� �ϳ���, LDS����, LDS[n]�� �ƴ϶� LDS �߿��� max�� ģ���� ã�Ƽ� ��
�ؾ��Ѵٴ� ���̴�.

�� �� ������ �������� ��μ� ������� ����, ���� �� ������ ã�� �� �ְ�
�ȴ�.

������� = LIS + LDS��� ���� �ݵ�� ����ϵ��� ����. �ڡڡڡڡ�
*/

int main(void) {
	int N;

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> A[i];
	cout << makeLISLDSArray(N);

	return 0;
}
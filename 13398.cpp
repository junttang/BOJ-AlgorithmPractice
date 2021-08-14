#include <iostream>
// BOJ - 13398 ������2
#define MAX_NUM		100000
using namespace std;

/*
�ʹ��� ��ư� �ذ��� ����. �ᱹ �ٽ���, '���� �ִ� �ϳ� �����ϴ� �͵� ������
��Ȳ������ �ִ� ������'�� �����ϴ� ���ε�,

1) �⺻(����x ��Ȳ) �������� �켱������ D�迭�� max�� ���س���,
2) DRight, ��, ���⼱ D[i][2]�� ��¡�Ǵ�, A[i]�� �����Ͽ�, A[i]���� �����ϴ�
�ִ� �������� �����ϴ� ���� �߿��ߴ�.
3) �ֳ��ϸ�, A[i] ���� ���� �ִ� �������� �ǹ��ϴ� DExclusive�� �ᱹ
max(D[i-1][1],D[i-1][0]) : A[i] �տ����� �ִ� �⺻ ������
DRight = D[i+1][2] : A[i+1]���� �����ϴ� �ִ� �⺻ ������
�� ���̱� �����̴�.

4)���� 1)~3)�� �����ϴ� ���� �ֿ��ߴ�.

*/

int A[MAX_NUM + 1];	// D[i][j] : A[i]������ �ִ� ������
int D[MAX_NUM + 1][3]; // 0�� '���� ����', 1�� '�հ� ����', 2�� 'i������ �ִ뿬����'
int DExclusive[MAX_NUM + 1]; // �� �� �� ���� ���� �ִ� ������
// D[i][0] = A[i], D[i][1] = max(D[i-1][0],D[i-1][1]) + A[i] 
int makeDArray(int n) {
	int max, temp;
	D[1][0] = A[1]; D[1][1] = A[1];
	max = D[1][0];

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 2; j++) {
			switch (j) {
			case 0: D[i][j] = A[i]; break;
			case 1: D[i][j] = (D[i - 1][0] >= D[i - 1][1] ?
				D[i - 1][0] : D[i - 1][1]) + A[i]; break;
			}
		}
		temp = (D[i][1] >= D[i][0] ? D[i][1] : D[i][0]);
		if (temp >= max)
			max = temp;
	}

	D[n][2] = A[n];
	for (int i = n - 1; i >= 0; i--) {
		D[i][2] = A[i];
		if (D[i][2] < D[i + 1][2] + A[i])
			D[i][2] = D[i + 1][2] + A[i];
	}

	for (int i = 2; i < n; i++) {
		DExclusive[i] = D[i + 1][2] +
			(D[i - 1][1] >= D[i - 1][0] ? D[i - 1][1] : D[i - 1][0]);
		if (DExclusive[i] >= max)
			max = DExclusive[i];
	}

	return max;
}


int main(void) {
	int n;

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	if (n == 1) {
		cin >> A[1];
		cout << A[1];
		return 0;
	}

	for (int i = 1; i <= n; i++)
		cin >> A[i];
	cout << makeDArray(n);

	return 0;
}
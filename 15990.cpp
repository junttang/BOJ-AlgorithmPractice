#include <iostream>
// BOJ - 15990 Adding 1,2,3 - 5
#define MAX_NUM		100000
#define DIVISOR		1000000009
using namespace std;
/*
���� ����� ������ ���� DP ������ �Ʒ��� ����
n���� �迭 ������ �����Ͽ� �ذ��� �� �ִ�.

D[i]�� ����� ������ �������� ������ ���� 2���� �ʵ��
�������ִ� ���̴�.
��, ��ȭ���� �б��Ѵ�.

����, 2�� ���⿡�� ����������, �ٷ� ������ ���꿡 ����
�����ض����̾��µ�, ������ ������ DIVISOR ������ ����
�� ǥ���ϱ� �����̱� ������ ������ ���൵ ������ ���ٴ�
���� �������� ���� ���� ��������.
(��ǥ �κ�)

*/

// [][i]�� ������ ���� i�� ����
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

		k = (D[n][1] + D[n][2] + D[n][3]) % DIVISOR; //(��)
		if (k == 0) k = 1;
		cout << k << '\n';
	}

	return 0;
}
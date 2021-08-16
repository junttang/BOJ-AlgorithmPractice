#include <iostream>
// BOJ - 17404 RGB�Ÿ� 2
#define MAX_HOUSE		1000
#define INFINITE		10000000000
using namespace std;

int A[MAX_HOUSE + 1][3]; // 0��, 1��, 2��
int D[MAX_HOUSE + 1][3];
// D[i][j] : i��° �� ���� j�� ��, ��� �� ĥ �ּҺ��

/*
A[1]~A[N]�� RGB�Ÿ� ��Ģ�� �����ϵ�, A[1]�� A[N]�� ����������
���� �޶���Ѵٴ�, �������� ������ ���� ��������.

�ذ��ϴµ� �ϳ� ���� �ð��� �ҿ�Ǿ��µ�,

�ذ� ����� ������ ���Ҵ�.

�ϴ� RGB�Ÿ�1 ������ Ǯ�̴� ���� �����ϴ�. ��ȭ�ĸ� �����ϸ� �ȴ�.

�ٽ���, A[1]�� R, G, B�� ���� ������ �� �� �� DP�� ���־���Ѵٴ� ���ε�,
A[1]�� �����ǹǷ�, �� ���̽����� �츮�� �ʱ�ȭ���־���ϴ� ���� D[2][i]����
�̴�. �׸���, ��ȭ�� �ݺ����� i=3���� �����ϴ� ���̴�.

�̷��� �ؼ� N���� ��ȭ���� �����Ǹ�, ���� ��� ���̽�(���� ��)�� 0�̸�
D[N][1], D[N][2] �� �ּڰ��� ä���ϸ� �Ǵ� ���̴�.

*/

int makeDArray(int N) {
	int MIN = INFINITE, min, temp1, temp2;

	for (int k = 0; k < 3; k++) {
		D[1][0] = A[1][0]; D[1][1] = A[1][1]; D[1][2] = A[1][2];

		if (k == 0) { 
			temp1 = 1; temp2 = 2; D[2][0] = INFINITE;
			D[2][1] = D[1][0] + A[2][1];
			D[2][2] = D[1][0] + A[2][2];
		}
		else if (k == 1) { 
			temp1 = 2; temp2 = 0; D[2][1] = INFINITE;
			D[2][0] = D[1][1] + A[2][0];
			D[2][2] = D[1][1] + A[2][2];
		}
		else if (k == 2) { 
			temp1 = 1; temp2 = 0; D[2][2] = INFINITE;
			D[2][1] = D[1][2] + A[2][1];
			D[2][0] = D[1][2] + A[2][0];
		}
		
		for (int i = 3; i <= N; i++) {
			for (int j = 0; j < 3; j++) {
				switch (j) {
				case 0: D[i][j] = (D[i - 1][1] <= D[i - 1][2] ?
					D[i - 1][1] : D[i - 1][2]) + A[i][j]; break;
				case 1: D[i][j] = (D[i - 1][2] <= D[i - 1][0] ?
					D[i - 1][2] : D[i - 1][0]) + A[i][j]; break;
				case 2: D[i][j] = (D[i - 1][1] <= D[i - 1][0] ?
					D[i - 1][1] : D[i - 1][0]) + A[i][j]; break;
				}
			}
		}

		min = (D[N][temp1] <= D[N][temp2] ? D[N][temp1] : D[N][temp2]);
		if (min < MIN)
			MIN = min;
	}
	
	return MIN;
}

int main(void) {
	int N;

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> A[i][0] >> A[i][1] >> A[i][2];
	cout << makeDArray(N);

	return 0;
}
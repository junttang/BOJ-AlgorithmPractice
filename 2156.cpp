#include <iostream>
// BOJ - 2156 Drink Grape Wine
#define MAX_NUM		10000
using namespace std;

int A[MAX_NUM + 1];	// ������ ��
long long D[MAX_NUM + 1][3]; // 0 �ȸ���, 1 ����, 2 ����
// D[i][j] : i�� ������ �ִ�� ���� ��, �������� j�÷� ����
long long makeDArray(int n) {
	int higher;

	D[1][1] = A[1]; 
	D[2][0] = A[1]; // �� ����ó���� ���� �ʾ� Ʋ�ȴ�.
	D[2][1] = A[1];	// DP ��ȭ�� ���� �� ���� ó���� ���� �Ĳ��� �ؾ��Ѵ�.
	D[2][2] = A[1] + A[2];

	for (int i = 3; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			switch (j) {
			case 0: higher = (D[i - 1][0] >= D[i - 1][1] ? D[i - 1][0] : D[i - 1][1]);
				D[i][j] = (higher >= D[i - 1][2] ? higher : D[i - 1][2]); break;
			case 1: D[i][j] = D[i - 1][0] + A[i]; break;
			case 2: D[i][j] = D[i - 2][0] + A[i] + A[i - 1]; break;
			}
		}
	}

	higher = (D[n][0] >= D[n][1] ? D[n][0] : D[n][1]);
	return higher >= D[n][2] ? higher : D[n][2];
}

int main(void) {
	int n;

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> A[i];
	cout << makeDArray(n);

	return 0;
}
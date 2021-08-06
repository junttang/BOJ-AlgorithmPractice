#include <iostream>
// BOJ - 10844 Easy Stair Number
#define MAX_LEN		100
#define DIVISOR		1000000000

/*
2���� ��ȭ���� ����ϴ� ����

�����ؾ��� �� : ��� �� DIVISOR�� ���� �������� ����϶��
�ߴµ�, �̶�, ���� k�� �ݺ������� ��ġ�� ����� ä���ߴ�.
�츮�� ��Ȯ�� ���� �� ���� ������, k�� DIVISOR�� ���� ��쵵
���� �� ������ �����ؾ��Ѵ�.

��, ���� k�� 1000000000�̸�, ����� 0�� ���;��Ѵ�. ������
������ �� ���� �ڵ�� k�� mod�� ������ �ʾҴ�. ��, 0�� ��µ���
�ʴ� �ٴ� ���̴�. ~> �̸� ����ؾ��Ѵ�.
*/

using namespace std;
// D[i][j] : ���̰� i�̰�, ������ ���� j�� ��ܼ� ����� ��
long long D[MAX_LEN + 1][10];	
// D[i][j] = D[i-1][j-1] + D[i-1][j+1]
void calcStairNum(int n) {
	for (int i = 1; i < 10; i++)
		D[1][i] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 9)
				D[i][j] = D[i - 1][j - 1] % DIVISOR;
			else if (j == 0)
				D[i][j] = D[i - 1][j + 1] % DIVISOR;
			else
				D[i][j] = (D[i - 1][j - 1] + D[i - 1][j + 1]) % DIVISOR;
		}
	}
}

int main(void) {
	int N;
	long long k = 0;

	cin >> N;
	calcStairNum(N);
	for (int i = 0; i < 10; i++)
		k += D[N][i] % DIVISOR;
	cout << k % DIVISOR;

	return 0;
}
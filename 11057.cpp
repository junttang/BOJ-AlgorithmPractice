#include <iostream>
// BOJ - 11057 ��������
#define MAX_LEN		1000
#define DIVISOR		10007
using namespace std;
// D[i][j] : ���̰� i�̰�, ������ �ڸ����� j�� ����Ǽ�
long long D[MAX_LEN + 1][10];
// D[i][j] = D[i-1][k] 0<=k<=j
long long makeDArray(int N) {
	long long sum;

	for (int i = 0; i <= 9; i++)
		D[1][i] = 1;

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= 9; j++) {
			sum = 0;
			for (int k = 0; k <= j; k++)
				sum += D[i - 1][k] % DIVISOR;
			D[i][j] = sum % DIVISOR;
		}
	}

	sum = 0;
	for (int i = 0; i <= 9; i++)
		sum += D[N][i] % DIVISOR;
	return sum % DIVISOR;
}

int main(void) {
	int N;

	cin >> N;
	cout << makeDArray(N);

	return 0;
}
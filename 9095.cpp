#include <iostream>
// BOJ - 9095 1,2,3 Adding
// D[N] : N�� 1,2,3���� ����� ����� ��
#define MAX_NUM			11
using namespace std;

/*
�ᱹ, D[n]�� �ǹ̸� �����ϰ�,
�װ��� ���� ��ȭ���� ����� ���� ���� �߿��ϴ�.
*/

int D[MAX_NUM + 1];

void makeDArray(void) {
	D[1] = 1;
	D[2] = 2;
	D[3] = 4;
	for (int i = 4; i <= MAX_NUM; i++)
		D[i] = D[i - 1] + D[i - 2] + D[i - 3];
}

int main(void) {
	int T, n;

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	makeDArray();
	cin >> T;

	while (T--) {
		cin >> n;
		cout << D[n] << '\n';
	}

	return 0;
}
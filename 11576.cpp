#include <iostream>
// BOJ - 11576 Base Conversion
#define MAX_DIGIT		25

/*
����� ��ư� �ذ��� �����̴�.

�־��� ���� ��Ȳ�� ���ؼ��� ���忡 �� �ذ��ߴµ�

���� �Ǽ��� �κ��� �ٷ� �� �������µ�,

1) ù°��, digit �迭�� ���� �����ذ�����,
digit �迭�� �Է� �� ���� ������ �״�� �����Ǿ�
��� ��� �� ������ �� �ִ� ���ɼ��� �������� ���߰�

2) ��°�δ�, num == 0�� �� break�� ���� �ʰ� �� ����
�ε����� limit���� �ξ� 
2 2
2
1 0
�� ���� ��Ȳ�� ��ģ ���̾���.

~> �̷��� ������ �����ϰ� ���ܸ� �Ű������� �ٽ� �� ��
������ �� �־���.

*/

using namespace std;

long long digit[MAX_DIGIT];
long long result[MAX_DIGIT];

int main(void) {
	int A, B, m, k = 0, limit = 0;
	long long num = 0, mul = 1, div = 1;

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> A >> B >> m;

	for (int i = 1; i < m; i++)
		mul *= A;

	for (int i = 0; i < m; i++) {
		cin >> digit[i];
		num += digit[i] * mul;
		mul /= A;
	}
	if (m == 1 && digit[0] == 0) {
		cout << 0;
		return 0;
	}

	for (int i = 1; div <= num; i++) {
		div *= B;
		limit++;
	}
	div /= B;
	
	for (int i = 0; ; i++) {
		if (num == 0)
			break;
		result[i] = num / div;
		num %= div;
		div /= B;
	}

	for (int i = 0; i < limit; i++)
		cout << result[i] << ' ';

	return 0;
}
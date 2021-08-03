#include <iostream>
// BOJ - 9613 GCD Summation

/*
���� ������ ������ �����ϴ� ����

GCD�� ã��, ���պ��� ������ִ� ������ ����� ���� �����ε�,
sum�� ��� ������ �־ n�� ��� 1000000�� ��� 100C2����ŭ
1000000�� ���ϸ� int�� ������ �ʰ��ϴ� ���� ���´�. ����
sum�� long long�� ���� ū ������ ��������.

~> ��, sum�� ���ϴ� �����̰�, n�� �Է��� ū ������ �����ϸ�
long�� ���ִ� ���� �����ϴ�.

*/

using namespace std;

int GCD(int a, int b) {
	if (b == 0)
		return a;
	return GCD(b, a%b);
}

int main(void) {
	int T, n, *num;
	long long sum;

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;

	while (T--) {
		cin >> n;
		num = new int[n];
		sum = 0;

		for (int i = 0; i < n; i++)
			cin >> num[i];

		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++)
				sum += GCD(num[i], num[j]);
		}

		cout << sum << '\n';
	}

	return 0;
}
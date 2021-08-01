#include <iostream>
// BOJ - 6588 Goldbach's Conjecture
#define MAX_NUM		1000000

/*
�ٽ���, �Ҽ� ���� ���� �˰��� ������
�����佺�׳׽��� ü�� ���ø��� ������ ����ؾ��ϴ� ���̴�!
*/

using namespace std;

bool check[MAX_NUM + 1];

int main(void) {
	int n, pn = 0, a;
	int * prime;

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	prime = new int[MAX_NUM + 1];

	for (int i = 2; i <= MAX_NUM; i++) {
		if (check[i] == false) {
			prime[pn++] = i;
			for (int j = i * 2; j <= MAX_NUM; j += i)
				check[j] = true;
		}
	}

	while (1) {
		cin >> n; a = 0;

		if (n == 0)
			break;

		for (int i = 0; prime[i] < n; i++) {
			if (check[n - prime[i]] == false) {
				a = prime[i];
				break;
			}
		}
		if (a == 0)
			cout << "Goldbach's conjecture is wrong.\n";
		else
			cout << n << " = " << a << " + " << (n - a) << '\n';
	}

	return 0;
}
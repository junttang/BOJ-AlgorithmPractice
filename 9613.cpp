#include <iostream>
// BOJ - 9613 GCD Summation

/*
문제 조건을 유심히 봐야하는 유형

GCD를 찾고, 조합별로 계산해주는 과정은 어렵지 않은 문제인데,
sum의 계산 과정에 있어서 n이 모두 1000000인 경우 100C2개만큼
1000000을 합하면 int의 범위를 초과하는 값이 나온다. 따라서
sum을 long long과 같은 큰 범위로 정해주자.

~> 즉, sum을 구하는 문제이고, n의 입력이 큰 수까지 가능하면
long을 해주는 것이 안전하다.

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
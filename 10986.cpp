#include <iostream>
// BOJ - 10986 Remainder Summation
using namespace std;

long long mod[1001];

int main(void) {
	int n, m, t;
	long long psum = 0, cnt = 0;
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> t;
		psum += t;
		mod[psum % m]++;
	}

	for (int i = 0; i <= m; i++) 
		cnt += ((mod[i] * (mod[i] - 1)) / 2);

	cout << mod[0] + cnt;

	return 0;
}
/*
1 2 3 1 2
1 3 6 7 9

1 1 0 1 1  (2)
1 0 0 1 0  (3)
1 3 2 3 1  (4)

i부터 j까지의 부분 구간합 : psum[j] - psum[i-1]
원하는 것 : (psum[j] - psum[i-1]) % m = 0인 구간들
모듈러 공식 :
(psum[j] - psum[i-1]) % m = 0 는 곧
psum[j] % m = psum[i-1] % m
~> 즉, 각 psum[i]에 대해 모듈러 연산한 배열에서,
m이 같은 psum[i]끼리 묶어서, 각 묶음에서 나오는 경우의수를
합하면 된다.
*/

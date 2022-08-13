#include <iostream>
// BOJ - 1300 kth Number
using namespace std;
typedef long long LL;
LL ans;

void find_value(int n, int k, LL lo, LL hi) {
	LL val = (lo + hi) / 2, smalls = 0, temp;

	if (lo <= hi) {
		for (LL layer = 1; layer <= n; layer++) {
			temp = val / layer;
			if (temp > n) temp = n;
			smalls += temp;
		}
		
		if (lo == hi) { ans = lo; return; }

		if (smalls < k)
			find_value(n, k, val + 1, hi);
		else if (smalls >= k)
			find_value(n, k, lo, val);
	}
}

int main(void) {
	LL n, k;

	cin >> n >> k;
	find_value(n, k, 1, n*n);
	cout << ans;

	return 0;
}

/*
4 8 C 16   4단
3 6 9 C    3단
2 4 6 8    2단
1 2 3 4    1단
~> 1 2 2 3 3 4 4 4 6 6 8 8 9 12 12 16

B[k] = T의 의미 : B행렬의 k번째 값은 T
== T라는 값보다 작거나 같은 원소의 개수가 최소 k개는 있음.

~> B[k]에서 k : B[k] 값보다 작거나 같은 원소의 개수
~> 우리는 여기서 T값을 찾고자 함.
=> T의 값을 조정해나가면서 T보다 작거나 같은 원소의 개수가 k값이랑 일치하면 된다.

Ex) 6
4 8 C 16   4단 : 6 / 4 = 1
3 6 9 C    3단 : 6 / 3 = 2
2 4 6 8    2단 : 6 / 2 = 3
1 2 3 4    1단 : 6 / 1 = 6 -> 4
~~> 6보다 작거나 같은 원소의 개수 : 10 ~> T=6에 대해 k=10

=> 1~N에 대해 1~N로 T 나누었을 때, 그 몫들의 합(각 몫은 N이하여야함)이
   k이고, 그 k가 주어진 k와 같은지를 확인하면 된다.

이때, T는 1부터 100000^2까지 가능한데, 너무 많은 범위이므로, 여기에서
바로 Binary Search 기법이 사용되는 것이다.
*/

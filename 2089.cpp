/*-13
7, 1
-3, 1
2, 1
-1, 0
1, 1
0, 1

-14
7, 0
-3, 1
2, 1
-1, 0
1, 1
0, 1

10
-5, 0
3, 1
-1, 1
1, 1
0 1

이 과정들에서 논리를 찾아서 코딩하면 된다.

한 가지 유의점은, N이 0일 때를 처리해주어야한다는 점이다.

*/
#include <iostream>
#include <string>
// BOJ - 2089 -2진수

using namespace std;

int main(void) {
	long long N;
	string output = "";
	string plus;

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	if (N == 0) {
		cout << 0;
		return 0;
	}

	while (N != 0) {
		if (N < 0) {
			if (N % 2 != 0) {
				N -= 1;
				plus = "1";
			}
			else
				plus = "0";
			N /= -2;
			
			output = plus + output;
		}
		else {
			if (N % 2 != 0)
				plus = "1";
			else
				plus = "0";
			N /= -2;

			output = plus + output;
		}
	}
	cout << output;

	return 0;
}


#include <iostream>
// BOJ - 11576 Base Conversion
#define MAX_DIGIT		25

/*
상당히 어렵게 해결한 문제이다.

주어진 예제 상황에 대해서는 초장에 잘 해결했는데

내가 실수한 부분은 바로 두 가지였는데,

1) 첫째는, digit 배열을 괜히 재사용해가지고,
digit 배열의 입력 시 구성 사항이 그대로 유지되어
결과 출력 시 오염될 수 있는 가능성을 생각하지 못했고

2) 둘째로는, num == 0일 때 break만 하지 않고 그 때의
인덱스를 limit으로 두어 
2 2
2
1 0
과 같은 상황을 놓친 것이었다.

~> 이러한 문제는 세심하게 예외를 신경써야함을 다시 한 번
깨달을 수 있었다.

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
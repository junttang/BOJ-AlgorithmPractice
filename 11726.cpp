#include <iostream>
// BOJ - 11726 2xN Tile
#define MAX_TILE		1000

/*
범위를 신경써야 하는 유형!
이러한 점화식 DP 유형은, 생각보다 수가 매우 급격하게 불어난다.
따라서, 수를 기억하고 있는 자료구조의 정수 범위를 주의해야하는데,
이 유형에서는 long long을 택하여도 100만 넘게 입력되어도 넘어간다.
따라서 이럴 때는, 문제의 조건을 봐야하는데, 문제에서는 10007로
나눈 나머지로 출력하라고 한다.

최초에는, 마지막 cout에서 10007로 나누었는데, 이렇게 했을 때는
T배열값이 범위 초과이기 때문에 부정확한 값이 나올 수밖에 없다.

이때는, 점화식 자체에서 지속적으로 10007로 나누어주어야 한다.
나머지의 성질을 이용하는 것이다. 합연산이기 때문에 계산 과정에서
나머지 연산으로 둘러싸여 있어도, 그 값의 결과에는 영향이 없기 때문이다.
마지막 합 부분에는 영향이 없으므로.
*/

using namespace std;

int T[MAX_TILE + 1];

void makeTArray(int n) {
	T[1] = 1;
	T[2] = 2;
	for (int i = 3; i <= n; i++)
		T[i] = (T[i - 2] + T[i - 1]) % 10007;
}


int main(void) {
	int n;

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	makeTArray(n);
	cout << T[n];

	return 0;
}
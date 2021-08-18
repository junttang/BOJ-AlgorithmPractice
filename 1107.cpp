/*
핵심적인 아이디어는, 입력된 채널 번호와 가장 가까운 채널번호
를 찾아야한다는 점이다.

우리가 최소를 구할 때에는, +와 -의 중복이 일어나면 최소 횟수를
만족시킬 수 없기 때문에 +나 - 중 하나만 연속적으로 사용하는 상
황이 최소이기 때문이다.(버튼 고장이 존재하는 상황에서)


그런데 해결하지 못한 이유 : 내가 한 구현 자체가 틀린 것은 아니다.

그런데, 입력받은 수 n과 다이얼 누를 번호 c를 구분하지 않은 것에서
지속적 오류 원인을 만들었다.

즉, 상황 분기를 너무 많이한 것이다.


최초에, n-100을 구해놓고(다이얼이 다 고장난 상황 가정)

나머지 버튼이 1개 이상 있는 상황에서의 가장 가까운 다이얼을 구하는
반복문을 구성할 때

n과 상관없이 그냥 c가 0부터 MAX_NUM까지 반복하는 상황에서 +/- 프레싱이

최소인 값을 찾아내면 되는 것이었는데


내 문제는 각 상황별로 다 분기하려고 시도한 것이 문제였다.


다음부터는, 이러한 여러 숨겨진 조건이 있는 문제를 해결할 때에는

예외를 고려하되, 너무 지나치게 분기하는 것은 지양하도록 하자.


*/

#include <iostream>
using namespace std;
bool broken[10];
int possible(int c) {
	if (c == 0) {
		if (broken[0]) {
			return 0;
		}
		else {
			return 1;
		}
	}
	int len = 0;
	while (c > 0) {
		if (broken[c % 10]) {
			return 0;
		}
		len += 1;
		c /= 10;
	}
	return len;
}
int main() {
	int n;
	cin >> n;
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		broken[x] = true;
	}
	int ans = n - 100;
	if (ans < 0) {
		ans = -ans;
	}
	for (int i = 0; i <= 1000000; i++) {
		int c = i;
		int len = possible(c);
		if (len > 0) {
			int press = c - n;
			if (press < 0) {
				press = -press;
			}
			if (ans > len + press) {
				ans = len + press;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
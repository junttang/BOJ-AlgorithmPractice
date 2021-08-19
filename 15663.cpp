#include <iostream>
// BOJ - 15663 N and M (9)
#define MAX_SIZE		10
using namespace std;

bool check[MAX_SIZE];
int A[MAX_SIZE];
int num[MAX_SIZE];

void makeAArray(int index, int n, int m) {
	if (index == m) {
		for (int i = 0; i < m; i++) {
			cout << A[i];

			if (i != m - 1)
				cout << ' ';
		}
		cout << '\n';

		return;
	}
	int prev = -1;

	for (int i = 1; i <= n; i++) {
		if (check[i] || prev == num[i])
			continue;

		check[i] = true;
		A[index] = num[i];
		prev = num[i];
		makeAArray(index + 1, n, m);
		check[i] = false;
	}
}

int main(void) {
	int N, M, temp;

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> num[i];
		for (int j = i - 1; j >= 1; j--) {
			if (num[j] > num[j + 1]) {
				temp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = temp;
			}
		}
	}

	makeAArray(0, N, M);

	return 0;
}

/*
문제를 최초에 접해보면, 9 7 9 1 이 입력되었을 때, 각각의 9가 다른 수로 인식되지만,
동시에, 수열 출력 시 기존에 이미 출력한 수열과 같은 수열은 출력하면 안되는 상황임을
몇 가지 예제 컴파일을 통해 인지할 수 있다.


내가 이 문제를 오랜 시간 해결하지 못한 것은, 최초에 시도했던 방법이 수열을 문자열화
하고, 각 수열을 배열로 히스토리화하여 기존에 등장했었는지를 확인하는 방식으로 구현했
었다. 논리 자체는 틀리지 않았지만, 이는 문자열을 다룬다는 점에서 시간초과를 야기했다.


예제를 자세히 들여다보면 해법을 발견할 수 있다.

"이미 출력한 수열과 같은 수열을 출력하지 않는다."
~> 이때, 현재 상황에서 수열은 예를 들어
1 2 3 3
1 2 3 4
와 같이 마지막 수가 변하면서 수열이 바뀌고 있음을 알 수 있다.

즉, 디테일하게 이야기하면,

예를 들어, 9가 2개 들어있다고 해서 '(1, 9), (1, 9)' 이렇게 두 번 출력하면 안 된다는
의미인 것이다.

이와 같은 조건을 처리하기 위해서는 (1, 9)를 출력하고 나서 (1, ?)에서 '?'에 해당하는 
수를 고를 때 바로 직전에 선택한 수와 같으면 안된다는 조건은 위의 prev 변수 도입을 통해
구현할 수 있다.

이때, 수열의 자리 인덱스가 늘어나는 시점에서 prev 기록 및 재귀호출 최초 시점에서 prev
검사가 이루어져야함을 아는 것이 중요하다. 각 자리수를 채울 때마다, 앞전 것과 같으면 안
되기 때문이다.

같은 이유로, continue할 때는, prev와 현재 조회 수가 같은 상황도 추가해주면 될 것이다.
*/
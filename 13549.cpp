#include <iostream>
#include <deque>
// BOJ - 13549 숨바꼭질 3
#define MAX_NUM		100000
using namespace std;

bool check[MAX_NUM + 1];
int seconds[MAX_NUM + 1];
deque<int> DQ;

/*
cost가 0과 1인 최단거리 탐색 문제를 BFS로 해결하는 방법!!

~> BFS가 cost 0도 포함해서 다룬다면, 큐 대신 덱을 사용한다!!

~> cost가 0이란 것은, cost가 1인 친구들보다 우선순위가 커야하므로

옵션을 보고, cost가 0인 옵션들의 경우 덱의 앞으로 넣어줘 먼저 덱에서
빠져서 조회되도록 한다.
1인 옵션들은 뒤로 넣어주는 것이다.


이때!!!!!!!!!!!!
주의할 점이 하나 있는데, C의 절차적 프로그래밍을 감안해야 한다.

즉, 0인 옵션을 1보다 먼저 확인해봐야한다. 그래야 최단거리에 더 가까워
질 수 있지 않겠는가?
*/

int bfs(int N, int K) {
	int x;

	DQ.push_back(N);
	check[N] = true;

	while (!DQ.empty()) {
		x = DQ.front(); DQ.pop_front();

		if (x == K)
			break;

		if (2 * x <= MAX_NUM && check[2 * x] == false) {
			check[2 * x] = true;
			DQ.push_front(2 * x);
			seconds[2 * x] = seconds[x];
		}

		if (x + 1 <= MAX_NUM && check[x + 1] == false) {
			check[x + 1] = true;
			DQ.push_back(x + 1);
			seconds[x + 1] = seconds[x] + 1;
		}

		if (x - 1 >= 0 && check[x - 1] == false) {
			check[x - 1] = true;
			DQ.push_back(x - 1);
			seconds[x - 1] = seconds[x] + 1;
		}
	}

	return seconds[x];
}

int main(void) {
	int N, K;

	cin >> N >> K;
	cout << bfs(N, K);

	return 0;
}
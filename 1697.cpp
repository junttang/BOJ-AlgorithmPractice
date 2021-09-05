#include <iostream>
#include <queue>
// BOJ - 1697 숨바꼭질
#define MAX_NUM		100000
using namespace std;

/*
BFS 알고리즘을 최단거리 탐색 용으로 사용하기 위해선
가중치가 1이어야하고, 정점이 너무 많아선 안되는데,

이 문제는 다행히 이 조건을 만족한다.

여기서 중요한 점은, 문제 상황을 그래프화하여 볼 줄 아는 능력이다.

그리고, 행렬 그래프화 관점처럼, 선형적인 수 관계 역시 그래프화하여
볼 수 있음도 알 수 있다.
*/

bool check[MAX_NUM + 1];
int seconds[MAX_NUM + 1];
queue<int> Q;

int bfs(int N, int K) {
	int x, MIN = 1000000000;
	
	Q.push(N);
	check[N] = true;

	while (!Q.empty()) {
		x = Q.front(); Q.pop();

		if (x == K) {
			if (seconds[x] < MIN)
				MIN = seconds[x];
			continue;
		}

		if (x + 1 <= MAX_NUM && check[x + 1] == false) {
			check[x + 1] = true;
			Q.push(x + 1);
			seconds[x + 1] = seconds[x] + 1;
		}

		if (x - 1 >= 0 && check[x - 1] == false) {
			check[x - 1] = true;
			Q.push(x - 1);
			seconds[x - 1] = seconds[x] + 1;
		}

		if (2 * x <= MAX_NUM && check[2 * x] == false) {
			check[2 * x] = true;
			Q.push(2 * x);
			seconds[2 * x] = seconds[x] + 1;
		}
	}
	
	return MIN;
}

int main(void) {
	int N, K;

	cin >> N >> K;
	cout << bfs(N, K);

	return 0;
}
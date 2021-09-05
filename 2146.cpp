#include <iostream>
#include <queue>
// BOJ - 2146 Making Bridge
#define MAX_SIZE		100
using namespace std;

/*
우선 이 문제는 두 차례의 BFS가 필요한 문제이다.

첫번째로는, 섬들에 번호를 매겨 섬들을 구분해야한다.
이 작업은, 행렬관점의 BFS를 실시해, map배열에 1이 적힌,
즉, 섬이 있다고 있는 부분들을 BFS로 체크해, 연결된 그래프들을
각각 1, 2, .. 이런 식으로 섬 넘버링을 해주는 것이다.


둘째로는, 이 섬들(map에 1이 적힌)의 각 (i,j)들을 모두 큐에 넣어
BFS를 실시하여, map이 0인 부분들에 대하여, 거리 카운팅을 하는 것이다.
이렇게 하면, 동시다발적으로, 각 섬들로부터 바다부분에 대해 한칸씩 갈수록
거리 카운팅이 된다.

이때, 거리 카운팅이 부딪히는 지점에서, 두 거리를 더해주고, 이 값들의 최소
를 찾으면 되는 것이다.


이때, 정말 중요한 아이디어는, 부딪히는 지점에서, 두 파형이 서로 다른 섬에서
온 파형인지를 체크하는 것이 중요한데,

이를 구현하는 방식이 헷갈릴 수 있다. 나는 이 부분에서 막혔는데,

이는 거리 카운팅을 할떄마다, 섬 넘버링을 그대로 확장해주는 방식으로 처리할 수
있다. 즉, 넘버링이 서로 다른 파형이 부딪히게 하는 것이다. 이렇게 함으로써,
디스트를 더해 최소값을 찾을 수 있다.

BFS로 거리 계산하는 관점, 행렬좌표를 BFS하는 관점을 잘 기억하자.
*/

int map[MAX_SIZE][MAX_SIZE];
bool check[MAX_SIZE][MAX_SIZE];
int island[MAX_SIZE][MAX_SIZE];
int dist[MAX_SIZE][MAX_SIZE];
queue<pair<int,int>> Q;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

void island_numbering(int N) {
	int x, y, xx, yy;
	int cnt = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] && !check[i][j]) {
				Q.push(make_pair(i, j));
				check[i][j] = true;
				island[i][j] = ++cnt;

				while (!Q.empty()) {
					x = Q.front().first;
					y = Q.front().second;
					Q.pop();

					for (int k = 0; k < 4; k++) {
						xx = x + dx[k];
						yy = y + dy[k];
						if (xx < 0 || xx >= N || yy < 0 || yy >= N)
							continue;

						if (map[xx][yy] && !check[xx][yy]) {
							check[xx][yy] = true;
							Q.push(make_pair(xx, yy));
							island[xx][yy] = cnt;
						}
					}
				}
			}
		}
	}
}

int bfs(int N) {
	int MIN = 10000000, temp, x, y, xx, yy;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			check[i][j] = false;
			if (map[i][j])
				Q.push(make_pair(i, j));
		}
	}

	while (!Q.empty()) {
		x = Q.front().first;
		y = Q.front().second;
		Q.pop();

		for (int k = 0; k < 4; k++) {
			xx = x + dx[k];
			yy = y + dy[k];
			if (xx < 0 || xx >= N || yy < 0 || yy >= N)
				continue;

			if (!map[xx][yy] && !check[xx][yy]) {
				check[xx][yy] = true;
				Q.push(make_pair(xx, yy));
				dist[xx][yy] = dist[x][y] + 1;
				island[xx][yy] = island[x][y];
			}
			else if (!map[xx][yy]) {
				if (island[xx][yy] != island[x][y]) {
					temp = dist[xx][yy] + dist[x][y];
					if (temp < MIN)
						MIN = temp;
				}
			}
		}
	}

	return MIN;
}

int main(void) {
	int N;

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cin >> map[i][j];
	}
	island_numbering(N);
	cout << bfs(N);

	return 0;
}
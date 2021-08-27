#include <cstdio>
#include <queue>
// BOJ - 2178 Maze Search
#define MAX_SIZE		100
using namespace std;

int n, m;
int a[MAX_SIZE][MAX_SIZE];
bool check[MAX_SIZE][MAX_SIZE];
int dist[MAX_SIZE][MAX_SIZE];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int main(void) {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &a[i][j]);
		}
	}
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	check[0][0] = true;
	dist[0][0] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (check[nx][ny] == false && a[nx][ny] == 1) {
					q.push(make_pair(nx, ny));
					dist[nx][ny] = dist[x][y] + 1;
					check[nx][ny] = true;
				}
			}
		}
	}
	printf("%d\n", dist[n - 1][m - 1]);

	/*
	<x,y>를 정점으로 두고, 4방향 서칭을 하며, 각 4방향이 간선으로서 존재한다.
	이때, check와 a == 1 판단을 통해 1인 친구들끼리만 정점 연결이 된 형태가
	된다.

	또한, dist를 통해, 큐에 집단적 삽입을 할 때마다 거리가 1씩 증가하게 해주는
	작업도 해주어야한다.

	해결하지 못한 문제이다.
	위와 같은, 그래프로 바라보는 연습을 지속적으로 해주자.
	*/

	return 0;
}
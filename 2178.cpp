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
	<x,y>�� �������� �ΰ�, 4���� ��Ī�� �ϸ�, �� 4������ �������μ� �����Ѵ�.
	�̶�, check�� a == 1 �Ǵ��� ���� 1�� ģ���鳢���� ���� ������ �� ���°�
	�ȴ�.

	����, dist�� ����, ť�� ������ ������ �� ������ �Ÿ��� 1�� �����ϰ� ���ִ�
	�۾��� ���־���Ѵ�.

	�ذ����� ���� �����̴�.
	���� ����, �׷����� �ٶ󺸴� ������ ���������� ������.
	*/

	return 0;
}
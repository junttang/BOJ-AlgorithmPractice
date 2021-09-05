#include <iostream>
#include <queue>
// BOJ - 2146 Making Bridge
#define MAX_SIZE		100
using namespace std;

/*
�켱 �� ������ �� ������ BFS�� �ʿ��� �����̴�.

ù��°�δ�, ���鿡 ��ȣ�� �Ű� ������ �����ؾ��Ѵ�.
�� �۾���, ��İ����� BFS�� �ǽ���, map�迭�� 1�� ����,
��, ���� �ִٰ� �ִ� �κе��� BFS�� üũ��, ����� �׷�������
���� 1, 2, .. �̷� ������ �� �ѹ����� ���ִ� ���̴�.


��°�δ�, �� ����(map�� 1�� ����)�� �� (i,j)���� ��� ť�� �־�
BFS�� �ǽ��Ͽ�, map�� 0�� �κе鿡 ���Ͽ�, �Ÿ� ī������ �ϴ� ���̴�.
�̷��� �ϸ�, ���ôٹ�������, �� ����κ��� �ٴٺκп� ���� ��ĭ�� ������
�Ÿ� ī������ �ȴ�.

�̶�, �Ÿ� ī������ �ε����� ��������, �� �Ÿ��� �����ְ�, �� ������ �ּ�
�� ã���� �Ǵ� ���̴�.


�̶�, ���� �߿��� ���̵���, �ε����� ��������, �� ������ ���� �ٸ� ������
�� ���������� üũ�ϴ� ���� �߿��ѵ�,

�̸� �����ϴ� ����� �򰥸� �� �ִ�. ���� �� �κп��� �����µ�,

�̴� �Ÿ� ī������ �ҋ�����, �� �ѹ����� �״�� Ȯ�����ִ� ������� ó���� ��
�ִ�. ��, �ѹ����� ���� �ٸ� ������ �ε����� �ϴ� ���̴�. �̷��� �����ν�,
��Ʈ�� ���� �ּҰ��� ã�� �� �ִ�.

BFS�� �Ÿ� ����ϴ� ����, �����ǥ�� BFS�ϴ� ������ �� �������.
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
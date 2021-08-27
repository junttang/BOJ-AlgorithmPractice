#include <iostream>
#include <queue>
// BOJ - 7576 Tomatoes
#define MAX_SIZE		1000
using namespace std;

/*
��ǥ��� T,
check���,
dist���
�� ���� �����ϰ�,

���� �ǹ� ���� �迭 dx, dy�� ��������,

��ǥ����� ������� �׷���ȭ�Ͽ� BFS�� �����ϴ� �����̴�!!
(�ſ� �߿��� ��ų���� �⺻�� ��ų)
*/

int T[MAX_SIZE][MAX_SIZE];
bool check[MAX_SIZE][MAX_SIZE];
int rot_day[MAX_SIZE][MAX_SIZE];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
int MAX = 0;
int left_tomato_flag = 0;

int main(void) {
	int M, N, x, y, xx, yy;
	queue<pair<int, int>> Q;

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> T[i][j];

			if (T[i][j] == 1) {	// ���� �丶����� ���������� ť ����
				check[i][j] = true;
				Q.push(make_pair(i, j));
				rot_day[i][j] = 0;		// ���ϳ� ���� ���̹Ƿ� 0 ���
			}
		}
	}

	while (!Q.empty()) {
		x = Q.front().first;
		y = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; i++) {		// 4-���� Ȯ��
			xx = x + dx[i]; yy = y + dy[i];	// 4-���� �ĺ� ����

			if (xx >= 0 && xx < N && yy >= 0 && yy < M 
				&& check[xx][yy] == false && T[xx][yy] == 0) { // Ž�� ���ɿ���
				check[xx][yy] = true; // �丶���̸鼭 ���ÿ� �̹湮 �����̾����
				Q.push(make_pair(xx, yy));
				rot_day[xx][yy] = rot_day[x][y] + 1; // ť ���� ���� ���� dist���
				if (rot_day[xx][yy] > MAX)
					MAX = rot_day[xx][yy];	// ���� dist�� �հ��� �� ���� �� ��!
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (check[i][j] == false && T[i][j] == 0)
				left_tomato_flag = 1;
		}
	}
	if (left_tomato_flag) cout << -1;
	else cout << MAX;

	return 0;
}
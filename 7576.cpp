#include <iostream>
#include <queue>
// BOJ - 7576 Tomatoes
#define MAX_SIZE		1000
using namespace std;

/*
좌표행렬 T,
check행렬,
dist행렬
세 개를 도입하고,

방향 의미 전역 배열 dx, dy를 만들어놓고,

좌표평면을 대상으로 그래프화하여 BFS를 수행하는 유형이다!!
(매우 중요한 스킬이자 기본적 스킬)
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

			if (T[i][j] == 1) {	// 익은 토마토들은 선제적으로 큐 삽입
				check[i][j] = true;
				Q.push(make_pair(i, j));
				rot_day[i][j] = 0;		// 당일날 썪은 것이므로 0 기록
			}
		}
	}

	while (!Q.empty()) {
		x = Q.front().first;
		y = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; i++) {		// 4-방향 확인
			xx = x + dx[i]; yy = y + dy[i];	// 4-방향 후보 지정

			if (xx >= 0 && xx < N && yy >= 0 && yy < M 
				&& check[xx][yy] == false && T[xx][yy] == 0) { // 탐색 가능여부
				check[xx][yy] = true; // 토마토이면서 동시에 미방문 정점이어야함
				Q.push(make_pair(xx, yy));
				rot_day[xx][yy] = rot_day[x][y] + 1; // 큐 집단 삽입 마다 dist기록
				if (rot_day[xx][yy] > MAX)
					MAX = rot_day[xx][yy];	// 가장 dist가 먼것이 곧 최종 날 수!
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
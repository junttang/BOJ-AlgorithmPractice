#include <iostream>
#include <deque>
// BOJ - 1261 Algospot
using namespace std;

/*
scanf("%1d")를 이용하여 디지트별로 정수를 입력받는 스킬을 기억하자
*/

int A[100][100];
bool check[100][100];
int barrier[100][100];
deque<pair<int, int>> DQ;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

int bfs(int M, int N) {
	int x, y, xx, yy;

	DQ.push_back(make_pair(0, 0));
	check[0][0] = true;

	while (!DQ.empty()) {
		x = DQ.front().first;
		y = DQ.front().second;
		DQ.pop_front();

		if (x == N - 1 && y == M - 1)
			break;

		for (int i = 0; i < 4; i++) {
			xx = x + dx[i];
			yy = y + dy[i];

			if (xx < 0 || xx >= N || yy < 0 || yy >= M)
				continue;

			if (A[xx][yy] == 0 && check[xx][yy] == false) {
				check[xx][yy] = true;
				barrier[xx][yy] = barrier[x][y];
				DQ.push_front(make_pair(xx, yy));
			}

			if (A[xx][yy] == 1 && check[xx][yy] == false) {
				check[xx][yy] = true;
				barrier[xx][yy] = barrier[x][y] + 1;
				DQ.push_back(make_pair(xx, yy));
			}
		}
	}

	return barrier[x][y];
}

int main(void) {
	int M, N;

	cin >> M >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			scanf("%1d", &A[i][j]);
	}
	cout << bfs(M, N);

	return 0;
}
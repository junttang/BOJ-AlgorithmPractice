#include <iostream>
#include <string>
// BOJ - 16929 Two Dots
#define MAX_SIZE		50
using namespace std;

char A[MAX_SIZE][MAX_SIZE];
bool check[MAX_SIZE][MAX_SIZE];
int dist[MAX_SIZE][MAX_SIZE];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

/*
아래와 같이 DFS를 변형한 재귀함수를 구현하는 것이 핵심인 문제

이 함수 구성의 핵심은, color가 같은지를 판단해서 재귀를 호출하고,
check에 따른 처리는 재귀호출 직후에 전반부에서 실시하는 것이다.

또 다른 핵심으로는, dist[][]를 만들어, check 방문 시에 기존 dist값
과 cnt값을 비교하여 cnt가 4이상이면 사이클이 형성되었음을 의미하므로
이를 이용하는 것이다.
*/

bool go(int N, int M, pair<int,int> vertex, int cnt) {
	int x, y, xx, yy;
	x = vertex.first; y = vertex.second;
	if (check[x][y] && cnt - dist[x][y] >= 4) return true;
	if (check[x][y]) return false;

	check[x][y] = true; dist[x][y] = cnt;
	for (int i = 0; i < 4; i++) {
		xx = x + dx[i]; yy = y + dy[i];

		if (xx >= 0 && xx < N && yy >= 0 && yy <= M
			&& A[xx][yy] == A[x][y]) {
			if (go(N, M, make_pair(xx, yy), cnt + 1))
				return true;
		}
	}

	return false;
}

int main(void) {
	int N, M;
	string input;

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> input;
		for (int j = 0; j < M; j++)
			A[i][j] = input[j];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (check[i][j] == false) {
				if (go(N, M, make_pair(i, j), 0)) {
					cout << "Yes";
					return 0;
				}
			}
		}
	}
	cout << "No";
	
	return 0;
}
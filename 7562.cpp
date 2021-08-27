#include <iostream>
#include <queue>
// BOJ - 7562 Displacement of Knight
#define MAX_SIZE		300
using namespace std;

bool check[MAX_SIZE][MAX_SIZE];
int cnt[MAX_SIZE][MAX_SIZE];
int dx[] = { -1,-2,-1,-2,1,2,1,2 };
int dy[] = { 2,1,-2,-1,2,1,-2,-1 };
int answer = 0;
int flag = 0;

void restore(int l) {
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < l; j++) {
			check[i][j] = false;
			cnt[i][j] = 0;
		}
	}
	flag = 0;
	answer = 0;
}

int main(void) {
	int T, l, curX, curY, destX, destY, x, y, xx, yy;
	queue<pair<int, int>> Q;

	cin >> T;
	while (T--) {
		cin >> l >> curX >> curY >> destX >> destY;

		check[curX][curY] = true;
		Q.push(make_pair(curX, curY));
		cnt[curX][curY] = 0;

		while (!Q.empty()) {
			x = Q.front().first;
			y = Q.front().second;
			Q.pop();

			for (int i = 0; i < 8; i++) {
				xx = x + dx[i]; yy = y + dy[i];

				if (xx >= 0 && xx < l && yy >= 0 && yy < l
					&& check[xx][yy] == false) {
					if (xx == destX && yy == destY && !flag) {
						answer = cnt[x][y] + 1;
						flag = 1;
					}
					check[xx][yy] = true;
					Q.push(make_pair(xx, yy));
					cnt[xx][yy] = cnt[x][y] + 1;
				}
			}
		}
		cout << answer << '\n';

		restore(l);
	}

	return 0;
}
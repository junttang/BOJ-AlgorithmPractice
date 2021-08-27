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
�Ʒ��� ���� DFS�� ������ ����Լ��� �����ϴ� ���� �ٽ��� ����

�� �Լ� ������ �ٽ���, color�� �������� �Ǵ��ؼ� ��͸� ȣ���ϰ�,
check�� ���� ó���� ���ȣ�� ���Ŀ� ���ݺο��� �ǽ��ϴ� ���̴�.

�� �ٸ� �ٽ����δ�, dist[][]�� �����, check �湮 �ÿ� ���� dist��
�� cnt���� ���Ͽ� cnt�� 4�̻��̸� ����Ŭ�� �����Ǿ����� �ǹ��ϹǷ�
�̸� �̿��ϴ� ���̴�.
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
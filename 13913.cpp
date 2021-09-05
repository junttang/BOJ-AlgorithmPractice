#include <iostream>
#include <queue>
#include <stack>
// BOJ - 13913 ���ٲ��� 4
#define MAX_NUM		100000
using namespace std;

bool check[MAX_NUM + 1];
int seconds[MAX_NUM + 1];
int from[MAX_NUM + 1]; // for backtracking
queue<int> Q;
stack<int> S;

/*
�� ���� ¤�� �Ѿ �� : BFS�� ������ ���·� ���� ������ ������
ó������ �������� �����ϸ�, �� ������ �� �ִܰŸ��� ���̴�. ����
MIN ã�� ������ �ʿ����,

�������� �Ʒ��� ���� from �迭 ���� �� �չ��� �ٶ󺸰� �ϱ⸸ �������
�ָ� ���̴�.
*/

void bfs(int N, int K) {
	int x;

	Q.push(N);
	check[N] = true;

	while (!Q.empty()) {
		x = Q.front(); Q.pop();

		if (x == K) {
			cout << seconds[x] << '\n';
			for (int i = x; i != N; i = from[i])
				S.push(i);
			S.push(N);
			while (!S.empty()) {
				cout << S.top() << ' ';
				S.pop();
			}

			break;
		}

		if (x + 1 <= MAX_NUM && check[x + 1] == false) {
			check[x + 1] = true;
			Q.push(x + 1);
			from[x + 1] = x;
			seconds[x + 1] = seconds[x] + 1;
		}

		if (x - 1 >= 0 && check[x - 1] == false) {
			check[x - 1] = true;
			Q.push(x - 1);
			from[x - 1] = x;
			seconds[x - 1] = seconds[x] + 1;
		}

		if (2 * x <= MAX_NUM && check[2 * x] == false) {
			check[2 * x] = true;
			Q.push(2 * x);
			from[2 * x] = x;
			seconds[2 * x] = seconds[x] + 1;
		}
	}
}

int main(void) {
	int N, K;

	cin >> N >> K;
	bfs(N, K);

	return 0;
}
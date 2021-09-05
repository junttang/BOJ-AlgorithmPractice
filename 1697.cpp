#include <iostream>
#include <queue>
// BOJ - 1697 ���ٲ���
#define MAX_NUM		100000
using namespace std;

/*
BFS �˰����� �ִܰŸ� Ž�� ������ ����ϱ� ���ؼ�
����ġ�� 1�̾���ϰ�, ������ �ʹ� ���Ƽ� �ȵǴµ�,

�� ������ ������ �� ������ �����Ѵ�.

���⼭ �߿��� ����, ���� ��Ȳ�� �׷���ȭ�Ͽ� �� �� �ƴ� �ɷ��̴�.

�׸���, ��� �׷���ȭ ����ó��, �������� �� ���� ���� �׷���ȭ�Ͽ�
�� �� ������ �� �� �ִ�.
*/

bool check[MAX_NUM + 1];
int seconds[MAX_NUM + 1];
queue<int> Q;

int bfs(int N, int K) {
	int x, MIN = 1000000000;
	
	Q.push(N);
	check[N] = true;

	while (!Q.empty()) {
		x = Q.front(); Q.pop();

		if (x == K) {
			if (seconds[x] < MIN)
				MIN = seconds[x];
			continue;
		}

		if (x + 1 <= MAX_NUM && check[x + 1] == false) {
			check[x + 1] = true;
			Q.push(x + 1);
			seconds[x + 1] = seconds[x] + 1;
		}

		if (x - 1 >= 0 && check[x - 1] == false) {
			check[x - 1] = true;
			Q.push(x - 1);
			seconds[x - 1] = seconds[x] + 1;
		}

		if (2 * x <= MAX_NUM && check[2 * x] == false) {
			check[2 * x] = true;
			Q.push(2 * x);
			seconds[2 * x] = seconds[x] + 1;
		}
	}
	
	return MIN;
}

int main(void) {
	int N, K;

	cin >> N >> K;
	cout << bfs(N, K);

	return 0;
}
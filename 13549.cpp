#include <iostream>
#include <deque>
// BOJ - 13549 ���ٲ��� 3
#define MAX_NUM		100000
using namespace std;

bool check[MAX_NUM + 1];
int seconds[MAX_NUM + 1];
deque<int> DQ;

/*
cost�� 0�� 1�� �ִܰŸ� Ž�� ������ BFS�� �ذ��ϴ� ���!!

~> BFS�� cost 0�� �����ؼ� �ٷ�ٸ�, ť ��� ���� ����Ѵ�!!

~> cost�� 0�̶� ����, cost�� 1�� ģ���麸�� �켱������ Ŀ���ϹǷ�

�ɼ��� ����, cost�� 0�� �ɼǵ��� ��� ���� ������ �־��� ���� ������
������ ��ȸ�ǵ��� �Ѵ�.
1�� �ɼǵ��� �ڷ� �־��ִ� ���̴�.


�̶�!!!!!!!!!!!!
������ ���� �ϳ� �ִµ�, C�� ������ ���α׷����� �����ؾ� �Ѵ�.

��, 0�� �ɼ��� 1���� ���� Ȯ���غ����Ѵ�. �׷��� �ִܰŸ��� �� �����
�� �� ���� �ʰڴ°�?
*/

int bfs(int N, int K) {
	int x;

	DQ.push_back(N);
	check[N] = true;

	while (!DQ.empty()) {
		x = DQ.front(); DQ.pop_front();

		if (x == K)
			break;

		if (2 * x <= MAX_NUM && check[2 * x] == false) {
			check[2 * x] = true;
			DQ.push_front(2 * x);
			seconds[2 * x] = seconds[x];
		}

		if (x + 1 <= MAX_NUM && check[x + 1] == false) {
			check[x + 1] = true;
			DQ.push_back(x + 1);
			seconds[x + 1] = seconds[x] + 1;
		}

		if (x - 1 >= 0 && check[x - 1] == false) {
			check[x - 1] = true;
			DQ.push_back(x - 1);
			seconds[x - 1] = seconds[x] + 1;
		}
	}

	return seconds[x];
}

int main(void) {
	int N, K;

	cin >> N >> K;
	cout << bfs(N, K);

	return 0;
}
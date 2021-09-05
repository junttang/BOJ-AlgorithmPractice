#include <cstdio>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
// BOJ - 16964 DFS Special Judge
const int N_MAX = 100000;

/*
DFS�� �������Ͽ� ��Ȯ�� �湮�������� �Ǵ��ϴ� ������
������ ���� �������� �ذ��Ѵ�.


������ �湮�� ������ �ڽĵ� �߿��� �湮���� ���� ������ ���� 1�� �̻��϶�
���� �湮���� ������ ������ �湮�� ������ �ڽ��̾���Ѵ�.

�Ǵ�, ������ �湮�� ������ �ڽĵ� �߿��� �湮���� ���� ������ ���� 0�� ��
���� �湮 ���� ������ ���ݱ��� �湮�� ������ �߿��� �湮���� ���� �ڽ���
���� 1�� �̻��̸鼭 ���� �ֱٿ� �湮�� ������ �ڽ��̾���Ѵ�.(���� ��)


����,
�湮���� ���� �ڽ� ���� 1�̻��̸鼭 stack�� top���� ���� ����� ������
���� ���� �ִ� ������ �θ� �������� Ȯ���ϰ�, �ƴ϶�� false order�� ���̴�.
*/

int n;
int parent[N_MAX + 1];
int childNum[N_MAX + 1];
bool visited[N_MAX + 1];

stack<int> s;
vector<int> order, edges[N_MAX + 1];

void dfs(int x, int prv) {
	if (visited[x]) return;
	visited[x] = true;
	parent[x] = prv;	// �θ� ������ ���
	childNum[prv] += 1; // �ڽ� ���� ���

	for (auto next : edges[x]) {
		dfs(next, x);
	}
}

int main() {
	scanf("%d", &n);

	for (int i = 1; i < n; i++) {
		int u, v; scanf("%d %d", &u, &v);
		edges[u].push_back(v);
		edges[v].push_back(u);
	}

	dfs(1, 0);

	for (int i = 0; i < n; i++) {
		int x; scanf("%d", &x);
		order.push_back(x);
	}

	if (order.empty()) {
		printf("0\n"); return 0;
	}


	if (order[0] != 1) {
		printf("0\n"); return 0;
	}
	s.push(order[0]);

	bool isPossible = true;


	for (int i = 1; i < n; i++) {
		int x = order[i];
		int topIndex = 0;
		while (!s.empty()) {
			topIndex = s.top();
			if (childNum[topIndex] > 0) break;
			s.pop();
		}
		if (s.empty()) {
			isPossible = false; break;
		}
		if (parent[x] == topIndex) {
			childNum[topIndex] -= 1;
			s.push(x);
		}
		else {
			isPossible = false; break;
		}
	}

	(isPossible) ? printf("1\n") : printf("0\n");


	return 0;
}
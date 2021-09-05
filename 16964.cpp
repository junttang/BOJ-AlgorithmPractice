#include <cstdio>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
// BOJ - 16964 DFS Special Judge
const int N_MAX = 100000;

/*
DFS를 역추적하여 정확한 방문순서인지 판단하는 문제는
다음의 논리를 바탕으로 해결한다.


직전에 방문한 정점의 자식들 중에서 방문하지 않은 정점의 수가 1개 이상일때
현재 방문중인 정점이 직전에 방문한 정점의 자식이어야한다.

또는, 직전에 방문한 정점의 자식들 중에서 방문하지 않은 정점의 수가 0일 때
현재 방문 중인 정점이 지금까지 방문한 정점들 중에서 방문하지 않은 자식의
수가 1개 이상이면서 가장 최근에 방문한 정점의 자식이어야한다.(스택 논리)


따라서,
방문하지 않은 자식 수가 1이상이면서 stack의 top에서 가장 가까운 정점이
현재 보고 있는 정점의 부모 정점인지 확인하고, 아니라면 false order인 것이다.
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
	parent[x] = prv;	// 부모 정점을 기록
	childNum[prv] += 1; // 자식 개수 기록

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
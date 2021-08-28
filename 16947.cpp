/*#include <iostream>
#include <vector>
#include <queue>
// BOJ - 16947 Seoul Metro 2nd Line
#define MAX_STATION		3000
using namespace std;

vector<int> Edge[MAX_STATION + 1];
bool check[MAX_STATION + 1];
int dist[MAX_STATION + 1];
bool cycle_check[MAX_STATION + 1];
bool cycle[MAX_STATION + 1];

bool DFS(int N, int vertex, int cnt) {
	if (check[vertex] == true && cnt - dist[vertex] >= 3)
		return true;
	if (check[vertex] == true) return false;

	check[vertex] = true; dist[vertex] = cnt; cycle_check[vertex] = false;
	for (int i = 0; i < Edge[vertex].size(); i++) {
		if (DFS(N, Edge[vertex][i], cnt + 1))
			cycle_check[Edge[vertex][i]] = true;
	}
	return false;
}

void BFS(int vertex) {
	queue<int> Q;

	if (cycle[vertex])
		dist[vertex] = 0;
	Q.push(vertex); 
	while (!Q.empty()) {
		vertex = Q.front();
		Q.pop();
		for (int i = 0; i < Edge[vertex].size(); i++) {
			if (check[Edge[vertex][i]] == false) {
				Q.push(Edge[vertex][i]);
				check[Edge[vertex][i]] = true;
				dist[Edge[vertex][i]] = dist[vertex] + 1;
				if (cycle[Edge[vertex][i]])
					dist[Edge[vertex][i]] = 0;
			}
		}
	}
}

int main(void) {
	int N, a, b;

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> a >> b;
		Edge[a].push_back(b);
		Edge[b].push_back(a);
	}

	for (int i = 1; i <= N; i++) {
		DFS(N, i, 0);
		for (int j = 1; j <= N; j++) {
			if (cycle_check[j] == true)
				cycle[j] = true;
			check[j] = false;
			dist[j] = 0;
		}
	}
	BFS(1);

	for (int i = 1; i <= N; i++)
		cout << dist[i] << ' ';

	return 0;
}*/
/*
위에는 내 기존 풀이이다.

각 정점에 대해서 변형 DFS를 실시한다.
이 변형 DFS는 기본적으로 사이클이 있는지 없는지를 판단하는
기능을 하는데, 여기에 약간 변형을 주어, 사이클임을 확인하는
데에 기준점을 체크하는 역할을 한다.

따라서 모든 정점에 대해 이 변형 DFS를 실시하면 결국 사이클에
포함되는 모든 정점이 체킹된다.

이제, 이 체킹을 기준으로, 특정 점에서 dist 배열을 이용한
BFS를 실시한다. 이때, 체킹포인트의 경우 dist를 0으로 바꿔주어
BFS 확장 시 정상적으로 dist가 기록된다.

이렇게 하여 오랜 시간이 걸렸지만, 기본 예제에 대해서 모두 정상
작동하는 코드가 완성되었다.

그런데 계속 틀렸다고 표시된다. 도무지 예외가 발견되지 않아

아래의 정답 코드를 첨부한다.
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> a[3000];
int check[3000]; // 0: not visited, 1: visited, 2: cycle
int dist[3000];
int go(int x, int p) {	// 변형 DFS, p는 이전 조회 정점
	// -2: found cycle and not included
	// -1: not found cycle
	// 0~n-1: found cycle and start index
	if (check[x] == 1) {	// 처음 방문했던 노드 방문했으면 사이클!
		return x;
	}
	check[x] = 1;		// 방문하였음을 표시
	for (int y : a[x]) {	// 모든 연결 간선 체킹
		if (y == p) continue;	// 이전 노드이면, 자기자신이면 패스
		int res = go(y, x);		// x의 연결 정점 y에 대한 정보 확인
		if (res == -2) return -2; // -2이면 계속 -2 반환
		if (res >= 0) {	// 사이클을 찾은 경우(사이클 시작 정점)
			check[x] = 2;	// 사이클에 포함
			if (x == res) return -2;	// 사이클의 시작점을 찾음
			else return res;		// 사이클의 시작 정점을 반환
		}
	}
	return -1;	// 사이클을 찾지 못함
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u -= 1; v -= 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	go(0, -1);
	queue<int> q;
	for (int i = 0; i < n; i++) {
		if (check[i] == 2) {
			dist[i] = 0;
			q.push(i);
		}
		else {
			dist[i] = -1;
		}
	}
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int y : a[x]) {
			if (dist[y] == -1) {
				q.push(y);
				dist[y] = dist[x] + 1;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << dist[i] << ' ';
	}
	cout << '\n';
	return 0;
}
/*
직전에 방문한 노드로는 탐색을 하지 않고 처음으로 방문했던 노드를 다시 만난다면 사이클
의 시작점이다. 이 경우 사이클에 포함시키고 사이클의 시작점을 리턴한다.
이때 리턴을 하다가 현재 노드와 리턴값(사이클의 시작점)이 같아진다면 여기부터는 사이클이
아니므로 -2를 리턴한다.
check배열에 ( 0 : 방문 x , 1 : 방문, 2 : 사이클 )을 기록한다.
bfs를 통해 각 노드와 사이클과의 거리를 구하면 된다.

모든 노드를 확인하여 사이클에 포함되었다면 dist에 사이클과의 거리 0을 기록하고 큐에 
push한다.
사이클에 포함되지 않는다면 -1로 초기화한다.
이후 bfs를 수행하며 다음 노드가 사이클에 포함되어있지 않다면(dist[i]가 -1 이라면) 큐에
push하고 거리를 1증가시킨다.
*/
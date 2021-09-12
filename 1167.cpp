#include <iostream>
#include <vector>
#include <queue>
// BOJ - 1167 Diameter of Tree

/*
트리에서의 지름을 찾는 다음의 알고리즘을 반드시 기억하자.

이름 : BFS 두번을 통한 트리 지름 찾기
1) 임의의 정점을 기준으로 BFS를 진행하여, 가장 거리가 먼 정점을 찾는다.
2) 해당 정점을 기준으로 다시 BFS를 진행하여, 가장 거리가 먼 정점을 찾는다.
3) 두 '해당 정점' 사이의 거리를 구한다. 이 역시 BFS로 진행하면 되며, A를
기준으로 시작하여 B에 도달했을 때의 dist값을 구하면 된다.
4) 만약 간선에 weight이 있으면, dist를 조금 조정해주면 된다.
*/

#define MAX_VERTEX	100000
using namespace std;

typedef struct _node {
	int vertex;
	int cost;
}Node;

vector<Node> Tree[MAX_VERTEX + 1];
bool check[MAX_VERTEX + 1];
int dist[MAX_VERTEX + 1];
queue<int> Q;

int BFS(int N, int vertex) {
	int x, MAX = 0, maxVertex = vertex;

	for (int i = 1; i <= N; i++) {
		check[i] = false;
		dist[i] = 0;
	}

	check[vertex] = true;
	Q.push(vertex);
	
	while (!Q.empty()) {
		x = Q.front(); Q.pop();

		for (int i = 0; i < Tree[x].size(); i++) {
			if (check[Tree[x][i].vertex] == false) {
				check[Tree[x][i].vertex] = true;
				dist[Tree[x][i].vertex] = dist[x] + Tree[x][i].cost;
				Q.push(Tree[x][i].vertex);
			}
		}

		if (dist[x] > MAX) {
			MAX = dist[x];
			maxVertex = x;
		}
	}

	return maxVertex;
}

int findAnswer(int N, int A, int B) {
	int x, ans;

	for (int i = 1; i <= N; i++) {
		check[i] = false;
		dist[i] = 0;
	}

	check[A] = true;
	Q.push(A);

	while (!Q.empty()) {
		x = Q.front(); Q.pop();

		for (int i = 0; i < Tree[x].size(); i++) {
			if (check[Tree[x][i].vertex] == false) {
				check[Tree[x][i].vertex] = true;
				dist[Tree[x][i].vertex] = dist[x] + Tree[x][i].cost;
				if (Tree[x][i].vertex == B)
					ans = dist[Tree[x][i].vertex];
				Q.push(Tree[x][i].vertex);
			}
		}
	}

	return ans;
}

int main(void) {
	int V, a, b, c, A, B;
	Node temp;

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> V;
	for (int i = 0; i < V; i++) {
		cin >> a;
		while (1) {
			cin >> b;

			if (b == -1) break;
			cin >> c; temp.cost = c;
			temp.vertex = b; 
			Tree[a].push_back(temp);
			temp.vertex = a;
			Tree[b].push_back(temp);
		}
	}
	A = BFS(V, 1);
	B = BFS(V, A);
	cout << findAnswer(V, A, B);

	return 0;
}
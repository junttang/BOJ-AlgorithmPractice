#include <iostream>
#include <vector>
#include <queue>
// BOJ - 1967 Diameter of Tree

#define MAX_VERTEX	10000
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
	if (V == 1) {
		cout << 0;
		return 0;
	}
	for (int i = 0; i < V - 1; i++) {
		cin >> a >> b >> c;
		temp.cost = c;
		temp.vertex = b;
		Tree[a].push_back(temp);
		temp.vertex = a;
		Tree[b].push_back(temp);
	}

	A = BFS(V, 1);
	B = BFS(V, A);
	cout << findAnswer(V, A, B);

	return 0;
}
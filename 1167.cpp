#include <iostream>
#include <vector>
#include <queue>
// BOJ - 1167 Diameter of Tree

/*
Ʈ�������� ������ ã�� ������ �˰����� �ݵ�� �������.

�̸� : BFS �ι��� ���� Ʈ�� ���� ã��
1) ������ ������ �������� BFS�� �����Ͽ�, ���� �Ÿ��� �� ������ ã�´�.
2) �ش� ������ �������� �ٽ� BFS�� �����Ͽ�, ���� �Ÿ��� �� ������ ã�´�.
3) �� '�ش� ����' ������ �Ÿ��� ���Ѵ�. �� ���� BFS�� �����ϸ� �Ǹ�, A��
�������� �����Ͽ� B�� �������� ���� dist���� ���ϸ� �ȴ�.
4) ���� ������ weight�� ������, dist�� ���� �������ָ� �ȴ�.
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
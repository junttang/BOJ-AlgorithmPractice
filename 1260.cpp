#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
// BOJ - 1260 DFS and BFS
#define MAX_VERTEX	1000
using namespace std;

vector<int> A[MAX_VERTEX + 1];
bool check[MAX_VERTEX + 1];
queue<int> Q[MAX_VERTEX + 1];

void DFS(int vertex) {
	cout << vertex << ' ';
	check[vertex] = true;
	for (int i = 0; i < A[vertex].size(); i++) {
		if (check[A[vertex][i]] == false)
			DFS(A[vertex][i]);
	}
}

void BFS(int vertex) {
	int tempV;
	
	check[vertex] = true; Q->push(vertex);
	while(!Q->empty()) {
		tempV = Q->front(); Q->pop(); cout << tempV << ' ';
		for (int i = 0; i < A[tempV].size(); i++) {
			if (check[A[tempV][i]] == false) {
				check[A[tempV][i]] = true;
				Q->push(A[tempV][i]);
			}
		}
	}
}

void restore(int N) {
	for (int i = 0; i <= N; i++)
		check[i] = false;
	cout << '\n';
}

int main(void) {
	int N, M, startV, a, b;
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> startV;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		A[a].push_back(b);
		A[b].push_back(a);
	}
	for (int i = 1; i <= N; i++) 
		sort(A[i].begin(), A[i].end());

	DFS(startV); 
	restore(N);
	BFS(startV);

	return 0;
}
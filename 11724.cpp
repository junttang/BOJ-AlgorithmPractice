#include <iostream>
#include <vector>
// BOJ - 11724 Number of Connected Components
#define MAX_VERTEX		1000
using namespace std;

vector<int> A[MAX_VERTEX + 1];
bool check[MAX_VERTEX + 1];

void DFS(int vertex) {
	check[vertex] = true;
	for (int i = 0; i < A[vertex].size(); i++) {
		if (check[A[vertex][i]] == false)
			DFS(A[vertex][i]);
	}
}

int main(void) {
	int N, M, a, b, cnt = 0;

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		A[a].push_back(b);
		A[b].push_back(a);
	}

	for (int i = 1; i <= N; i++) {
		if (check[i] == false) {
			DFS(i);
			cnt++;
		}
	}
	cout << cnt;

	return 0;
}
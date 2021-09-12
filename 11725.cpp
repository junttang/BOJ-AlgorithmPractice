#include <iostream>
#include <vector>
// BOJ - 11725 Finding the parent of tree
#define MAX_VERTEX	100000
using namespace std;

vector<int> Tree[MAX_VERTEX + 1];
int parent[MAX_VERTEX + 1];
bool check[MAX_VERTEX + 1];

void DFS(int n) {
	for (int i = 0; i < Tree[n].size(); i++) {
		if (check[Tree[n][i]] == false) {
			parent[Tree[n][i]] = n;
			check[Tree[n][i]] = true;
			DFS(Tree[n][i]);
		}
	}
}

int main(void) {
	int N, a, b;

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		Tree[a].push_back(b);
		Tree[b].push_back(a);
	}
	check[1] = true;
	DFS(1);

	for (int i = 2; i <= N; i++)
		cout << parent[i] << '\n';

	return 0;
}
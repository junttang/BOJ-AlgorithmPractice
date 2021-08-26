#include <iostream>
#include <vector>
// BOJ - 1707 Bipartite Graph
#define MAX_VERTEX		20000
using namespace std;

vector<int> Edge[MAX_VERTEX + 1];
int check[MAX_VERTEX + 1];
int not_bi_flag = 0;
int no_flag = 0;

void DFS(int vertex, int c) {
	check[vertex] = c;
	for (int i = 0; i < Edge[vertex].size(); i++) {
		if (check[Edge[vertex][i]] == 0)
			DFS(Edge[vertex][i], 3 - c);
		else if (check[vertex] == check[Edge[vertex][i]])
			not_bi_flag = 1;
	}
}

/*
이 문제는 두 가지가 중요하다.

첫 째로는, check를 bool이 아닌 int로 두어 미방문, 방문A, 방문B와
같은 식으로 구분하여 이분 그래프 판단을 시도하는 점

둘 째로는, 방문 시마다 1과 2가 반복적으로 호출되도록만드는 것이 중요하다.

이때 중요한 부분은, 내가 최초 시도했던 방법은, DFS가 호출될 때마다 count를
하여 count를 2로 나눈 나머지로 판단하는 방식을 채택했는데

이 방식은 반드시 틀린다.

이유는, 특정 정점에 대해서 DFS가 쭉 가다가 멈췄을 때이다. 멈추면, 해당 정점에
연결된 나머지 정점들에 대해서 DFS를 또 진행하면 되는데, 이때,

이분 그래프의 관점에선, 나(해당 정점)와는 다른 팀을 부여해야하는데, count를
하는 방식으로는 이것이 보장이 안된다.

이를 위해 우리는 3-c를 재귀호출에 사용하는 방식을 채택할 수 있다는 점을
반드시 기억하자.
*/

void restore(int V) {
	for (int i = 1; i <= V; i++) {
		Edge[i].clear();
		check[i] = 0;
	}
	not_bi_flag = 0;
	no_flag = 0;
}

int main(void) {
	int K, V, E, a, b;

	cin >> K;
	while (K--) {
		cin >> V >> E;

		for (int i = 1; i <= E; i++) {
			cin >> a >> b;
			Edge[a].push_back(b);
			Edge[b].push_back(a);
		}

		for (int i = 1; i <= V; i++) {
			if (check[i] == 0) {
				DFS(i, 1);
				if (not_bi_flag) no_flag = 1;
			}
		}
		if (no_flag) cout << "NO\n";
		else cout << "YES\n";

		restore(V);
	}

	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
// BOJ - 13023 ABCDE
using namespace std;

bool a[2000][2000];
vector<int> g[2000];
vector<pair<int, int>> edges;

/*
천재적인 아이디어가 필요한 문제이다.

A -> B -> C -> D -> E
관계가 있는지를 체킹해야하는데, 이를 그저 naive하게 하려고 하면
결코 답을 구할 수가 없게 된다. 너무나 가능한 가짓수가 다양하고
많기 때문이다.

이때, 신박한 아이디어가 사용된다.

A->B와 C->D를 먼저 특정하는 것이다. 이는 간선리스트를 사용하는 것이
편리하다. 순회가 짧기 때문이다.

그러고선, A, B, C, D가 서로 같은 것들이 있는지 체킹한다. 같지
않아야한다.

체킹이 완료되면, 인접행렬을 이용해 B와 C 사이에 관계가 있는지
체킹한다. 이는 한번의 연산으로 가능하므로 효율적이다.

여기까지 오면 ABCD가 연결된 것이다. 이제 D가 E와만 연결되면 끝인데,
여기선 인접리스트를 사용한다.

D에 연결된 모든 정점들을 체킹하는 것이다.

이때, 연결정점이 ABCD 중에 하나와 같으면 그것은 안된다.
이를 체킹해준 후,

여기까지 통과했으면, 이는 ABCDE를 충족시키는 상황인 것이다.
*/

int main(void) {
	int n, m;

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		edges.push_back({ from, to });
		edges.push_back({ to, from });
		a[from][to] = a[to][from] = true;
		g[from].push_back(to);
		g[to].push_back(from);
	}

	m *= 2;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			// A -> B
			int A = edges[i].first;
			int B = edges[i].second;
			// C -> D
			int C = edges[j].first;
			int D = edges[j].second;
			if (A == B || A == C || A == D || B == C || B == D || C == D) 
				continue;
			// B -> C
			if (!a[B][C])
				continue;
			// D -> E
			for (int E : g[D]) {
				if (A == E || B == E || C == E || D == E) 
					continue;
				cout << 1 << '\n';

				return 0;
			}
		}
	}
	cout << 0 << '\n';

	return 0;
}
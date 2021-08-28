#include <iostream>
#include <queue>
#include <vector>

/*
내 풀이가 틀린 이유 : 너무 naive했음.

이 문제는 입력으로 그래프와 간선정보, 그리고 BFS 순서가 들어온다.

그리고 BFS의 결과가 올바른 순서인지를 판단하는 문제이다.

간선 정보 입력 순서에 따라 BFS 결과는 여러가지가 가능하므로 스페셜 저지
를 구성한다고 하는 것이다.


여기서의 핵심 아이디어는,

1을 큐에 넣는다.

큐에서 빼고, 이 친구가 order[0]과 같은지 본다. 틀리면 false 반환

이어서, 이 친구의 간선들의 미방문 개수를 판단한다. 이를 cnt에 넣는다.
이때, 제일 중요한 아이디어는,
cnt를 세면서 동시에, 이 간선들의 parent 정보를 이 친구(팝된)를 바라보게
해주는 것이다.

이어서, cnt 만큼 j를 돌린다.
order[m+j]를 봐준다. 이 친구의 parent가 기존의 이 친구인지를 봐야한다.
아니라면 false이다.
맞다면, 이들을 큐에 넣어주고, 방문 표시도 해준다.

이를 큐가 빌때까지 반복하면 된다.


나는, parent 아이디어를 생각치 못했다.
그저 나이브하게 반복문 중첩시켜서 판단했는데, 이렇게 하니
입력이 100000까지다 보니 시간초과가 날 수밖에 없었다.

이러한, 방향전환 아이디어를 잘 기억해주고, 이를 DFS 스페셜 저지에도
적용해보자.
*/

using namespace std;
vector<int> a[100000];
int parent[100000];
int order[100000];
bool check[100000];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u -= 1; v -= 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for (int i = 0; i < n; i++) {
		cin >> order[i];
		order[i] -= 1;
	}
	queue<int> q;
	q.push(0);
	check[0] = true;
	int m = 1;
	for (int i = 0; i < n; i++) {
		if (q.empty()) {
			cout << 0 << '\n';
			return 0;
		}
		int x = q.front(); q.pop();
		if (x != order[i]) {
			cout << 0 << '\n';
			return 0;
		}
		int cnt = 0;
		for (int y : a[x]) {
			if (check[y] == false) {
				parent[y] = x;
				cnt += 1;
			}
		}
		for (int j = 0; j < cnt; j++) {
			if (m + j >= n || parent[order[m + j]] != x) {
				cout << 0 << '\n';
				return 0;
			}
			q.push(order[m + j]);
			check[order[m + j]] = true;
		}
		m += cnt;
	}
	cout << 1 << '\n';
	return 0;
}
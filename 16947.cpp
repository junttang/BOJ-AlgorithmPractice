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
������ �� ���� Ǯ���̴�.

�� ������ ���ؼ� ���� DFS�� �ǽ��Ѵ�.
�� ���� DFS�� �⺻������ ����Ŭ�� �ִ��� �������� �Ǵ��ϴ�
����� �ϴµ�, ���⿡ �ణ ������ �־�, ����Ŭ���� Ȯ���ϴ�
���� �������� üũ�ϴ� ������ �Ѵ�.

���� ��� ������ ���� �� ���� DFS�� �ǽ��ϸ� �ᱹ ����Ŭ��
���ԵǴ� ��� ������ üŷ�ȴ�.

����, �� üŷ�� ��������, Ư�� ������ dist �迭�� �̿���
BFS�� �ǽ��Ѵ�. �̶�, üŷ����Ʈ�� ��� dist�� 0���� �ٲ��־�
BFS Ȯ�� �� ���������� dist�� ��ϵȴ�.

�̷��� �Ͽ� ���� �ð��� �ɷ�����, �⺻ ������ ���ؼ� ��� ����
�۵��ϴ� �ڵ尡 �ϼ��Ǿ���.

�׷��� ��� Ʋ�ȴٰ� ǥ�õȴ�. ������ ���ܰ� �߰ߵ��� �ʾ�

�Ʒ��� ���� �ڵ带 ÷���Ѵ�.
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> a[3000];
int check[3000]; // 0: not visited, 1: visited, 2: cycle
int dist[3000];
int go(int x, int p) {	// ���� DFS, p�� ���� ��ȸ ����
	// -2: found cycle and not included
	// -1: not found cycle
	// 0~n-1: found cycle and start index
	if (check[x] == 1) {	// ó�� �湮�ߴ� ��� �湮������ ����Ŭ!
		return x;
	}
	check[x] = 1;		// �湮�Ͽ����� ǥ��
	for (int y : a[x]) {	// ��� ���� ���� üŷ
		if (y == p) continue;	// ���� ����̸�, �ڱ��ڽ��̸� �н�
		int res = go(y, x);		// x�� ���� ���� y�� ���� ���� Ȯ��
		if (res == -2) return -2; // -2�̸� ��� -2 ��ȯ
		if (res >= 0) {	// ����Ŭ�� ã�� ���(����Ŭ ���� ����)
			check[x] = 2;	// ����Ŭ�� ����
			if (x == res) return -2;	// ����Ŭ�� �������� ã��
			else return res;		// ����Ŭ�� ���� ������ ��ȯ
		}
	}
	return -1;	// ����Ŭ�� ã�� ����
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
������ �湮�� ���δ� Ž���� ���� �ʰ� ó������ �湮�ߴ� ��带 �ٽ� �����ٸ� ����Ŭ
�� �������̴�. �� ��� ����Ŭ�� ���Խ�Ű�� ����Ŭ�� �������� �����Ѵ�.
�̶� ������ �ϴٰ� ���� ���� ���ϰ�(����Ŭ�� ������)�� �������ٸ� ������ʹ� ����Ŭ��
�ƴϹǷ� -2�� �����Ѵ�.
check�迭�� ( 0 : �湮 x , 1 : �湮, 2 : ����Ŭ )�� ����Ѵ�.
bfs�� ���� �� ���� ����Ŭ���� �Ÿ��� ���ϸ� �ȴ�.

��� ��带 Ȯ���Ͽ� ����Ŭ�� ���ԵǾ��ٸ� dist�� ����Ŭ���� �Ÿ� 0�� ����ϰ� ť�� 
push�Ѵ�.
����Ŭ�� ���Ե��� �ʴ´ٸ� -1�� �ʱ�ȭ�Ѵ�.
���� bfs�� �����ϸ� ���� ��尡 ����Ŭ�� ���ԵǾ����� �ʴٸ�(dist[i]�� -1 �̶��) ť��
push�ϰ� �Ÿ��� 1������Ų��.
*/
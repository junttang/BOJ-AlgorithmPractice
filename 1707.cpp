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
�� ������ �� ������ �߿��ϴ�.

ù °�δ�, check�� bool�� �ƴ� int�� �ξ� �̹湮, �湮A, �湮B��
���� ������ �����Ͽ� �̺� �׷��� �Ǵ��� �õ��ϴ� ��

�� °�δ�, �湮 �ø��� 1�� 2�� �ݺ������� ȣ��ǵ��ϸ���� ���� �߿��ϴ�.

�̶� �߿��� �κ���, ���� ���� �õ��ߴ� �����, DFS�� ȣ��� ������ count��
�Ͽ� count�� 2�� ���� �������� �Ǵ��ϴ� ����� ä���ߴµ�

�� ����� �ݵ�� Ʋ����.

������, Ư�� ������ ���ؼ� DFS�� �� ���ٰ� ������ ���̴�. ���߸�, �ش� ������
����� ������ �����鿡 ���ؼ� DFS�� �� �����ϸ� �Ǵµ�, �̶�,

�̺� �׷����� ��������, ��(�ش� ����)�ʹ� �ٸ� ���� �ο��ؾ��ϴµ�, count��
�ϴ� ������δ� �̰��� ������ �ȵȴ�.

�̸� ���� �츮�� 3-c�� ���ȣ�⿡ ����ϴ� ����� ä���� �� �ִٴ� ����
�ݵ�� �������.
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
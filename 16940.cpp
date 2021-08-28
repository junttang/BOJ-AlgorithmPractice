#include <iostream>
#include <queue>
#include <vector>

/*
�� Ǯ�̰� Ʋ�� ���� : �ʹ� naive����.

�� ������ �Է����� �׷����� ��������, �׸��� BFS ������ ���´�.

�׸��� BFS�� ����� �ùٸ� ���������� �Ǵ��ϴ� �����̴�.

���� ���� �Է� ������ ���� BFS ����� ���������� �����ϹǷ� ����� ����
�� �����Ѵٰ� �ϴ� ���̴�.


���⼭�� �ٽ� ���̵���,

1�� ť�� �ִ´�.

ť���� ����, �� ģ���� order[0]�� ������ ����. Ʋ���� false ��ȯ

�̾, �� ģ���� �������� �̹湮 ������ �Ǵ��Ѵ�. �̸� cnt�� �ִ´�.
�̶�, ���� �߿��� ���̵���,
cnt�� ���鼭 ���ÿ�, �� �������� parent ������ �� ģ��(�˵�)�� �ٶ󺸰�
���ִ� ���̴�.

�̾, cnt ��ŭ j�� ������.
order[m+j]�� ���ش�. �� ģ���� parent�� ������ �� ģ�������� �����Ѵ�.
�ƴ϶�� false�̴�.
�´ٸ�, �̵��� ť�� �־��ְ�, �湮 ǥ�õ� ���ش�.

�̸� ť�� �������� �ݺ��ϸ� �ȴ�.


����, parent ���̵� ����ġ ���ߴ�.
���� ���̺��ϰ� �ݺ��� ��ø���Ѽ� �Ǵ��ߴµ�, �̷��� �ϴ�
�Է��� 100000������ ���� �ð��ʰ��� �� ���ۿ� ������.

�̷���, ������ȯ ���̵� �� ������ְ�, �̸� DFS ����� ��������
�����غ���.
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
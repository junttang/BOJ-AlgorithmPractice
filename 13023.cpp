#include <iostream>
#include <vector>
#include <algorithm>
// BOJ - 13023 ABCDE
using namespace std;

bool a[2000][2000];
vector<int> g[2000];
vector<pair<int, int>> edges;

/*
õ������ ���̵� �ʿ��� �����̴�.

A -> B -> C -> D -> E
���谡 �ִ����� üŷ�ؾ��ϴµ�, �̸� ���� naive�ϰ� �Ϸ��� �ϸ�
���� ���� ���� ���� ���� �ȴ�. �ʹ��� ������ �������� �پ��ϰ�
���� �����̴�.

�̶�, �Ź��� ���̵� ���ȴ�.

A->B�� C->D�� ���� Ư���ϴ� ���̴�. �̴� ��������Ʈ�� ����ϴ� ����
���ϴ�. ��ȸ�� ª�� �����̴�.

�׷���, A, B, C, D�� ���� ���� �͵��� �ִ��� üŷ�Ѵ�. ����
�ʾƾ��Ѵ�.

üŷ�� �Ϸ�Ǹ�, ��������� �̿��� B�� C ���̿� ���谡 �ִ���
üŷ�Ѵ�. �̴� �ѹ��� �������� �����ϹǷ� ȿ�����̴�.

������� ���� ABCD�� ����� ���̴�. ���� D�� E�͸� ����Ǹ� ���ε�,
���⼱ ��������Ʈ�� ����Ѵ�.

D�� ����� ��� �������� üŷ�ϴ� ���̴�.

�̶�, ���������� ABCD �߿� �ϳ��� ������ �װ��� �ȵȴ�.
�̸� üŷ���� ��,

������� ���������, �̴� ABCDE�� ������Ű�� ��Ȳ�� ���̴�.
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
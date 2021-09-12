#include <iostream>
// BOJ - 2250 Height and Width of Tree

/*
Ʋ�ȴ� ���� : �������� �� ��� �κп����� 1�� ��Ʈ��� ��������
�ʾ������� �翬 1�� ��Ʈ��� �����ϰ� �����ع���.
~> ���� Ʈ�������� ��Ʈ�� �������̴�. ���� ��Ʈ�� ã�ƾ��� ������
�ִ�.


����Ǯ�� ���̵��
1) �ᱹ ���ȣ�� �ش� ��尡 �θ���� �Ž��� �ö󰡴� ����
~> ���Ͽ� ���ε� ���� ã�� ���� ~> parent �ʵ� �������� �ذ� ����
2) �ᱹ ����ȣ�� ������ȸ Inorder ��ȸ�� ������
~> ������ȸ �����ָ鼭 �湮 ������� ����ȣ �ο��ϸ� �ȴ�.

3) �� ���� ��/�� ��ȣ�� �־�� ��������ȭ�� �����ϹǷ� ��屸��ü ����
4) �� ��ȣ ���� �ʺ� ���Ѵ�. (���� ��, ���� �ƽ� �����Ͽ�)

5) �̶�, ��Ʈ�� ���� �������� ����, ������ ��Ʈ�� ã�ƾ��Ѵ�.

*/

#define MAX_VERTEX	10000
using namespace std;

typedef struct _node {
	int left;
	int right;
	int row;
	int col;
	int parent;
}Node;

Node BT[2 * MAX_VERTEX + 10];
int root;
int visit_order = 1;
int max_row = 0;
int cnt = 0; 

bool yes_child(int n) {
	if (n != -1)
		return true;
	return false;
}

int what_row(int n, int root) {
	if (n == root) {
		if (cnt > max_row)
			max_row = cnt;
		return cnt;
	}
	cnt++;
	return what_row(BT[n].parent, root);
}

void inorder(int n, int root) {
	if (yes_child(BT[n].left)) inorder(BT[n].left, root);
	BT[n].col = visit_order++;
	cnt = 0; BT[n].row = what_row(n, root);
	if (yes_child(BT[n].right)) inorder(BT[n].right, root);
}

int main(void) {
	int N, a, b, c, localmin, localmax, MAX = 0, rownum = 1;

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a >> b >> c;
		if (BT[a].parent == 0)
			BT[a].parent = -1;
		BT[a].left = b; 
		if (b != -1) BT[b].parent = a;
		BT[a].right = c;
		if (c != -1) BT[c].parent = a;
	}
	for (int i = 1; i <= N; i++) {
		if (BT[i].parent == -1)
			root = i;
	}
	inorder(root, root);

	for (int k = 0; k <= max_row; k++) {
		localmin = MAX_VERTEX + 1; localmax = 0;
		for (int i = 1; i <= N; i++) {
			if (BT[i].row == k) {
				if (BT[i].col > localmax)
					localmax = BT[i].col;
				if (BT[i].col < localmin)
					localmin = BT[i].col;
			}
		}

		if (localmax - localmin + 1 > MAX) {
			MAX = localmax - localmin + 1;
			rownum = k + 1;
		}
	}
	cout << rownum << ' ' << MAX;

	return 0;
}
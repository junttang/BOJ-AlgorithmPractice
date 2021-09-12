#include <iostream>
// BOJ - 2250 Height and Width of Tree

/*
틀렸던 이유 : 문제에선 그 어느 부분에서도 1이 루트라고 단정짓지
않았음에도 당연 1이 루트라고 생각하고 가정해버림.
~> 이진 트리에서는 루트는 임의적이다. 따라서 루트를 찾아야할 때에도
있다.


문제풀이 아이디어
1) 결국 행번호는 해당 노드가 부모까지 거슬러 올라가는 높이
~> 유니온 파인드 논리로 찾기 가능 ~> parent 필드 도입으로 해결 가능
2) 결국 열번호는 중위순회 Inorder 순회와 동일함
~> 중위순회 돌려주면서 방문 순서대로 열번호 부여하면 된다.

3) 각 노드는 행/열 번호가 있어야 조합최적화가 가능하므로 노드구조체 구성
4) 행 번호 별로 너비를 구한다. (로컬 민, 로컬 맥스 도입하여)

5) 이때, 루트를 결코 단정짓지 말고, 스스로 루트를 찾아야한다.

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
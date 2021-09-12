#include <iostream>
// BOJ - 1991 Tree Traversal

/*
이 문제처럼, 입력이 임의로 루트-자식 순서 상관없이
자유롭게 들어올 수 있는 문제는 원론적으로 이진 트리 구조로
접근하여야한다.
그게 훨씬 간편한 것이다. 결국은. 배열로 하면, 입력할 때 이쁘게
들어오는게 아니라면 처리해야할 상황이 많아진다.
*/

using namespace std;
struct Node {
	int left;
	int right;
};
Node a[50];
void preorder(int x) {
	if (x == -1) return;
	cout << (char)(x + 'A');
	preorder(a[x].left);
	preorder(a[x].right);
}
void inorder(int x) {
	if (x == -1) return;
	inorder(a[x].left);
	cout << (char)(x + 'A');
	inorder(a[x].right);
}
void postorder(int x) {
	if (x == -1) return;
	postorder(a[x].left);
	postorder(a[x].right);
	cout << (char)(x + 'A');
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		char x, y, z;
		cin >> x >> y >> z;
		x = x - 'A';
		if (y == '.') {
			a[x].left = -1;
		}
		else {
			a[x].left = y - 'A';
		}
		if (z == '.') {
			a[x].right = -1;
		}
		else {
			a[x].right = z - 'A';
		}
	}
	preorder(0);
	cout << '\n';
	inorder(0);
	cout << '\n';
	postorder(0);
	cout << '\n';
	return 0;
}
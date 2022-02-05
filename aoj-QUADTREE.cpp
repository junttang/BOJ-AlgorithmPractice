#include <iostream>
#include <string>
// Algospot - QUADTREE
using namespace std;

// x (xwwwb)(xw(xwbbb)ww)(x(x(xwwbb)bww)wwb)b
// xxwwwbxwxwbbbwwxxxwwbbbwwwwbb

string image;
int index;

typedef struct _node{	// ���� Ʈ���� �����ϱ� ���� �⺻ ����ü
	char data;
	struct _node *upleft;	// NODE��� ��Ī�� link ���� ���� ���Ŀ� ���ǵǱ⿡
	struct _node *upright;	// struct _node�� ������ �����ؾ��Կ� ����!
	struct _node *downleft;
	struct _node *downright;
}NODE;

NODE* makeTree(void) {		// ����Ʈ���� �����ϴ� �Լ�
	NODE *newNode = new NODE;		// ȣ�� �ø��� NODE �Ҵ�

	if (index >= image.size())		// index ������ image��� ��Ʈ���� �� ȣ�⸶��
		return NULL;			// ��ȸ�ϴ� ������, ȣ��ø��� 1�� increment�ȴ�.
	// ���� index�� image ��Ʈ���� ������ �ε������� ū ��쿣 �Լ��� ���� ��ȯ�Ѵ�.
	newNode->data = image[index];
	index++;

	if (newNode->data == 'x') {		// ���� ��Ȳ�� ���� x�� ��쿣 �Ʒ��� ���� �����
		newNode->downleft = makeTree();		// ���� 4���� �ڽĳ�带 �����Ѵ�.
		newNode->downright = makeTree();	// �ε��� ������ ������ �ٷ� �� �κп���
		newNode->upleft = makeTree();		// ��Ʈ���� �� ��Ҹ� �� �帧�� �°� ����
		newNode->upright = makeTree();		// �ϱ� �����̴�.
		// �̶�, ���ϸ� ������ ���� down��ũ���� �����ϰ� ������ �ָ�
	}
	else {	// x�� �ƴ� ��쿣 ���ܳ���̹Ƿ�
		newNode->upleft = newNode->upright
			= newNode->downleft = newNode->downright = NULL;
	}

	return newNode;
}

void readTree(NODE *node) {	// ���� ��Ȳ�� ���� Ʈ���� ���� ��� �� ������ȸ�� �ùٸ�.
	if (node != NULL) {
		cout << node->data;
		readTree(node->upleft);
		readTree(node->upright);
		readTree(node->downleft);
		readTree(node->downright);
	}
}

int main(void) {
	int C;

	cin >> C;
	while (C--) {
		cin >> image;

		index = 0;
		NODE* root = makeTree();
		readTree(root);
		cout << endl;
		
		image.clear();	// �� �׽�Ʈ ���̽����� �ʱ�ȭ���ִ� �� �߿�
	}

	return 0;
}
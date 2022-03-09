#include <iostream>
// BOJ - 2164 Card2
using namespace std;

typedef struct _node {
	int key;
	struct _node *r_link;
	struct _node *f_link;
}Node;

Node *head = NULL, *tail = NULL;
int queueCnt;

void qPush(int x) {
	Node *newNode = new Node;
	newNode->key = x;
	newNode->r_link = head;
	if (queueCnt > 0) head->f_link = newNode;
	head = newNode;
	if (queueCnt == 0) tail = newNode;
	queueCnt++;
}

void qPop(void) {
	Node *delNode = tail;
	if (queueCnt == 1) head = tail = NULL;
	else tail = tail->f_link;
	queueCnt--;
}

int solve(int n) {
	int temp;

	for (int i = 1; i <= n; i++) qPush(i);

	while (queueCnt > 1) {
		qPop();
		temp = tail->key;
		qPop();
		qPush(temp);
	}

	return head->key;
}

int main(void) {
	int n;

	cin >> n;
	cout << solve(n);

	return 0;
}
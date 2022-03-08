#include <iostream>
#include <string>
// BOJ - 18258 Queue 2
using namespace std;

typedef struct _node {
	int key;
	struct _node *link;
	struct _node *f_link;
}Node;

Node *head = NULL, *tail = NULL;
int queueCnt = 0;

bool qEmpty(void) { if (queueCnt == 0) return true; return false; }

void qPush(int x) {
	Node *newNode = new Node;
	newNode->key = x;

	newNode->link = head;
	newNode->f_link = NULL;
	if (queueCnt > 0)
		head->f_link = newNode;
	head = newNode;
	if (queueCnt == 0) tail = newNode;

	queueCnt++;
}


void qPop(void) {
	if (qEmpty()) { cout << -1 << '\n'; return; }
	Node *delNode = tail;

	if (queueCnt == 1) 
		head = tail = NULL;
	else {
		tail = tail->f_link;
		tail->link = NULL;
	}
	cout << delNode->key << '\n';
	delete[] delNode;

	queueCnt--;
}

void qSize(void) { cout << queueCnt << '\n'; }

void qFront(void) { if (qEmpty()) cout << -1 << '\n'; else cout << tail->key << '\n'; }

void qBack(void) { if (qEmpty()) cout << -1 << '\n'; else cout << head->key << '\n'; }

int main(void) {
	int n, num; string option;
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	while (n--) {
		cin >> option;
		switch (option[0]) {
		case 'p': 
			if (option[1] == 'u') {
				cin >> num;
				qPush(num);
			}
			else qPop(); break;
		case 's': qSize(); break;
		case 'f': qFront(); break;
		case 'b': qBack(); break;
		case 'e': cout << qEmpty() << '\n'; break;
		}
	}

	return 0;
}
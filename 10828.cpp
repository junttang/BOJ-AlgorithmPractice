#include <iostream>
#include <string>
// BOJ - 10828 Stack
using namespace std;

typedef struct _node {
	int key;
	struct _node *link;
}Node;

Node *head = NULL;
int stackCnt;

bool sEmpty(void) { if (stackCnt == 0) return true; return false; }

void sTop(void) {
	if (sEmpty()) { cout << -1 << '\n';; return; }
	cout << head->key << '\n';
}

void sPush(int x) {
	Node *newNode = new Node;
	newNode->key = x; 
	newNode->link = head;
	head = newNode;
	stackCnt++;
}

void sPop(void) {
	if (sEmpty()) { cout << -1 << '\n';; return; }
	Node *delNode = head;
	head = head->link;
	cout << delNode->key << '\n';
	delete[] delNode;
	stackCnt--;
}

void sSize(void) { cout << stackCnt << '\n'; }

int main(void) {
	int n, num; string option;
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> option;
		switch (option[0]) {
		case 'p': if (option[1] == 'u') { cin >> num; sPush(num); }
			else sPop(); break;
		case 't': sTop(); break;
		case 's': sSize(); break;
		case 'e': cout << sEmpty() << '\n'; break;
		}
	}

	return 0;
}
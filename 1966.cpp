#include <iostream>
#include <list>
// BOJ - 1966 Printer Queue
using namespace std;

typedef struct _node {
	int index;
	int prior;
}Node;

list<Node> q;

int solve(int m) {
	int printCnt = 0, tempPrior;
	bool popflag;

	while (!q.empty()) {
		tempPrior = q.front().prior; popflag = false;

		for (list<Node>::iterator iter = q.begin(); iter != q.end(); iter++) {
			if ((*iter).prior > tempPrior) {
				q.push_back(q.front());
				q.pop_front();
				popflag = true;
				break;
			}
		}

		if (!popflag) {
			printCnt++;
			if (q.front().index == m) return printCnt;
			q.pop_front();
		}
	}
}

int main(void) {
	int t, n, m, p;
	Node temp;

	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> p;
			temp.index = i; temp.prior = p;
			q.push_back(temp);
		}

		cout << solve(m) << '\n';
		q.clear();
	}

	return 0;
}
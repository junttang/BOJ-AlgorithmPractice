#include <iostream>
#include <list>
#include <deque>
// BOJ - 1021 Rotating Queue
using namespace std;

list<int> rq;
int pick[51];

void leftTraverse(int leftLen, int *sum) {
	(*sum) += leftLen;
	for (int i = 0; i < leftLen; i++) { rq.push_back(rq.front()); rq.pop_front(); }
}

void rightTraverse(int rightLen, int *sum) { 
	(*sum) += (rightLen + 1);
	for (int i = 0; i <= rightLen; i++) { rq.push_front(rq.back()); rq.pop_back(); }
}

int solve(int n, int m) {
	int pickCnt = 0, leftLen, rightLen, sum = 0;
	bool equalLeft, equalRight;

	while (pickCnt != m) {
		leftLen = rightLen = 0; equalLeft = equalRight = false;

		if (rq.front() == pick[pickCnt]) {
			rq.pop_front();
			pickCnt++;
			continue;
		}

		for (list<int>::iterator iter = rq.begin(); iter != rq.end(); iter++) {
			if ((*iter) == pick[pickCnt]) break;
			if ((*iter) == pick[pickCnt + 1]) equalLeft = true;
			leftLen++;
		}
		for (list<int>::reverse_iterator riter = rq.rbegin(); riter != rq.rend(); riter++) {
			if ((*riter) == pick[pickCnt]) break;
			if ((*riter) == pick[pickCnt + 1]) equalRight = true;
			rightLen++;
		}

		if (leftLen < (rightLen + 1)) leftTraverse(leftLen, &sum);
		else if (leftLen > (rightLen + 1)) rightTraverse(rightLen, &sum);
		else {
			if (equalRight) rightTraverse(rightLen, &sum);
			else leftTraverse(leftLen, &sum);
		}
	}

	return sum;
}

int main(void) {
	int n, m;

	cin >> n >> m;
	for (int i = 0; i < m; i++) cin >> pick[i];
	for (int i = 1; i <= n; i++) rq.push_back(i);
	cout << solve(n, m);

	return 0;
}
#include <iostream>
#include <queue>
// BOJ - 11866 Josephus Problem 0
using namespace std;

bool check[1000];
int checkCnt;
queue<int> q;

void solve(int n, int k) {
	int cnt, index = 0;
	
	while (checkCnt != n) {
		cnt = 0;
		
		while (cnt != k) {
			if (check[index] == false) cnt++; 
			if (cnt == k) break;
			if (index + 1 == n) index = 0;
			else index++;
		}

		check[index] = true;
		q.push(index + 1);
		checkCnt++;
	}

	cout << '<';
	while (q.size() > 1) {
		cout << q.front() << ", ";
		q.pop();
	}
	cout << q.front() << '>';
}

int main(void) {
	int n, k;

	cin >> n >> k;
	solve(n, k);

	return 0;
}
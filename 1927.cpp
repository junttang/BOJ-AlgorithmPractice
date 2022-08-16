#include <iostream>
#include <vector>
#include <queue>
// BOJ - 1927 Min Heap
using namespace std;

priority_queue<int, vector<int>, greater<int>> minheap;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, op;

	cin >> n;
	while (n--) {
		cin >> op;

		if (op == 0) {
			if (minheap.size() == 0) cout << "0\n";
			else {
				cout << minheap.top() << '\n';
				minheap.pop();
			}
		}
		else minheap.push(op);
	}

	return 0;
}

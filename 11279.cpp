#include <iostream>
#include <queue>
// BOJ - 11279 Max Heap
using namespace std;

priority_queue<int> maxheap;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, op;

	cin >> n;
	while (n--) {
		cin >> op;

		if (op == 0) {
			if (maxheap.size() == 0) cout << "0\n";
			else {
				cout << maxheap.top() << '\n';
				maxheap.pop();
			}
		}
		else maxheap.push(op);
	}

	return 0;
}

#include <iostream>
#include <math.h>
#include <vector>
#include <queue>
// BOJ - 11286 Absolute Heap
#define PAIR pair<int, int>
using namespace std;

priority_queue<PAIR, vector<PAIR>, greater<PAIR>> abheap;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; PAIR op;

	cin >> n;
	while (n--) {
		cin >> op.second;  op.first = abs(op.second);

		if (op.second == 0) {
			if (abheap.size() == 0) cout << "0\n";
			else {
				cout << abheap.top().second << '\n';
				abheap.pop();
			}
		}
		else abheap.push(op);
	}

	return 0;
}

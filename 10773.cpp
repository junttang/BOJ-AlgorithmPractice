#include <iostream>
#include <stack>
// BOJ - 10773 Zero
using namespace std;

stack<int> s;

int main(void) {
	int k, num, sum = 0;

	cin >> k;
	while (k--) {
		cin >> num;
		if (num == 0) s.pop();
		else s.push(num);
	}

	while (!s.empty()) {
		sum += s.top();
		s.pop();
	}
	cout << sum;

	return 0;
}
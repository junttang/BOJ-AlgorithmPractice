#include <iostream>
#include <vector>
#include <algorithm>
// BOJ - 2751
using namespace std;

int main(void) {
	int n, num;

	vector<int> v;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++)
		cout << v[i] << '\n';

	return 0;
}
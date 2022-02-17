#include <iostream>
#include <vector>
#include <algorithm>
// BOJ - 11651 Coordinates Sorting 2
using namespace std;

vector<int> v[200001];

int main(void) {
	int n, x, y;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		v[y + 100000].push_back(x);
	}

	for (int i = 0; i < 200001; i++) {
		if (v[i].size() > 0)
			sort(v[i].begin(), v[i].end());
	}

	for (int i = 0; i < 200001; i++) {
		if (v[i].size() > 0) {
			for (int j = 0; j < v[i].size(); j++)
				cout << v[i][j] << ' ' << i - 100000 << '\n';
		}
	}

	return 0;
}
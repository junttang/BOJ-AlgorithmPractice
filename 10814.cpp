#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
// BOJ - 10814 Age Sorting
using namespace std;

vector<string> v[201];

int main(void) {
	int n, age;
	string name;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> age >> name;
		v[age].push_back(name);
		name.clear();
	}

	for (int i = 1; i < 201; i++) {
		for (int j = 0; j < v[i].size(); j++)
			cout << i << ' ' << v[i][j] << '\n';
	}

	return 0;
}
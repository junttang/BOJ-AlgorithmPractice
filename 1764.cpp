#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
// BOJ 1764 Never seen or heard of
#define len temp.length()
#define first temp.front()-97
#define last temp.back()-97
using namespace std;

vector<string> name[21][26][26];
vector<string> ans;

int main(void) {
	int n, m;
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string temp; cin >> temp;
		name[len][first][last].push_back(temp);
	}
	for (int i = 0; i < m; i++) {
		string temp; cin >> temp;

		for (int j = 0; j < name[len][first][last].size(); j++) 
			if (temp.compare(name[len][first][last][j]) == false) {
				ans.push_back(temp);
				break;
			}
	}

	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) 
		cout << ans[i] << '\n';

	return 0;
}

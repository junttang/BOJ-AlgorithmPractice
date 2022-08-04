#include <iostream>
#include <vector>
#include <string>
// BOJ 14425 Set of strings
#define get_temp() string temp; cin >> temp;
#define len temp.length()
#define first temp.front()-97
#define last temp.back()-97
using namespace std;

vector<string> str[501][26][26];

int main(void) {
	int n, m, cnt = 0;
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		get_temp();
		str[len][first][last].push_back(temp);
	}

	for (int i = 0; i < m; i++) {
		get_temp();
		for (int j = 0; j < str[len][first][last].size(); j++)
			if (temp.compare(str[len][first][last][j]) == 0)
				cnt++;
	}
	cout << cnt;

	return 0;
}

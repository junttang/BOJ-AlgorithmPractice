#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
// BOJ - 1181 Word Sorting
using namespace std;

vector<string> v[51];

int main(void) {
	int n;
	string word;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		bool noflag = false;
		cin >> word;
		for (int j = 0; j < v[word.size()].size(); j++) {
			if (!word.compare(v[word.size()][j])) {
				noflag = true;
				break;
			}
		}
		if (!noflag)
			v[word.size()].push_back(word);
	}

	for (int i = 1; i < 51; i++)
		sort(v[i].begin(), v[i].end());

	for (int i = 1; i < 51; i++) {
		for (int j = 0; j < v[i].size(); j++)
			cout << v[i][j] << '\n';
	}

	return 0;
}
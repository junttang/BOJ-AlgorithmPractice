#include <iostream>
#include <vector>
#include <string>
// BOJ 1620 I'm pocketmon master Dasom Lee
#define is_upper(c) ((c > 95) ? false : true)
#define set_val(a, b) a = b.a(); if (is_upper(a)) a -= 65; else a -= 97;
using namespace std;

vector<pair<string, int>> pkm[21][26][26];
string index[100000];

int main(void) {
	int n, m, front, back, len, temp_i;
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		pair<string, int> temp;
		cin >> temp.first; temp.second = i + 1;
		
		set_val(front, temp.first);
		set_val(back, temp.first);
		len = temp.first.length();

		pkm[len][front][back].push_back(temp);
		index[i] = temp.first;
	}

	for (int i = 0; i < m; i++) {
		string temp; cin >> temp;

		if (temp[0] <= 57) {
			temp_i = atoi(temp.c_str());
			cout << index[temp_i - 1] << "\n";
		}
		else {
			set_val(front, temp);
			set_val(back, temp);
			len = temp.length();

			for (int j = 0; j < pkm[len][front][back].size(); j++) 
				if (temp.compare(pkm[len][front][back][j].first) == false) {
					cout << pkm[len][front][back][j].second << "\n";
					break;
				}
		}
	}

	return 0;
}

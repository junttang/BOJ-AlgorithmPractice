#include <iostream>
#include <stack>
#include <string>
#include <array>
// BOJ - 11656 접미사 

using namespace std;

int main(void) {
	string str;
	stack<string> s;
	int temp;
	string * dictionary;

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> str;
	temp = str.size();
	dictionary = new string[temp];

	for (int i = 0; i < temp; i++) {
		s.push(str);
		dictionary[i] = s.top();
		str.erase(0, 1);
	}

	for (int i = temp - 1; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			if (dictionary[j] > dictionary[j + 1])
				swap(dictionary[j], dictionary[j + 1]);
		}
	}
	for (int i = 0; i < temp; i++)
		cout << dictionary[i] << '\n';
	
	return 0;
}
